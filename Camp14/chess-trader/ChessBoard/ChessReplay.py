#/usr/bin/env python

## downloader:
## ~/code/chess/games/www.chessgames.com$ for ID in {1500319..1500700}; do echo $ID; test -f $ID || wget -O $ID "http://www.chessgames.com/perl/nph-chesspgn?text=1&gid=$ID"; sleep 1; done

## even better (5M games):
## http://icofy-blog.de/icofy-base/

## bulk play:
## ~/code/chess$ find games/www.chessgames.com/ -maxdepth 1 -type f | sort | xargs -L1 python ChessBoard/ChessReplay.py

##
## Analyze chess game files to produce csv
## of game state and features at each move
## of each game.
## 
## Example usage:
## python ChessReplay.py ~/jump/chess/chesschallenge/games/www.chessgames.com/* > temp-out
##

from ChessBoard import ChessBoard
import sys
import re
import subprocess
import os

def findStockfish():
    candidates = ["/Users/matt/jump/chess/stockfish-dd-mac/src/stockfish",
                  "/home/mschubmehl/code/chess/stockfish-dd-src/src_c11/stockfish",
                  ]
    for c in candidates:
        if os.path.isfile(c):
            return c
    return "stockfish"

STOCKFISH = findStockfish()

def getScores(line):
    cols = [c.strip() for c in line.split("|")]
    name = cols.pop(0)
    scores = [float(s) if s != "---" else float("nan") for c in cols for s in c.split()]
    assert len(scores) == 6
    scores = dict(zip(("WM", "WE", "BM", "BE", "TM", "TE"), scores))
    return name, scores

SCORE_HEADERS = [ "Material, PST, Tempo"
                 ,"  Material imbalance"
                 ,"               Pawns"
                 ,"             Knights"
                 ,"             Bishops"
                 ,"               Rooks"
                 ,"              Queens"
                 ,"            Mobility"
                 ,"         King safety"
                 ,"             Threats"
                 ,"        Passed pawns"
                 ,"               Space"
                 ,"               Total"
                 ]

def getStockfishLines(moves, verbose=False):
    p = subprocess.Popen([STOCKFISH], stdin=subprocess.PIPE, stdout=subprocess.PIPE)
    cmds = "position startpos moves " + " ".join(moves) + "\nd\neval\n"
    out, err = p.communicate(cmds)
    assert p.returncode == 0
    if verbose: print out
    return out.split("\n")

stockfishProcess = None
def getStockfishLinesFast(moves, verbose=False):
    import pexpect
    global stockfishProcess
    if stockfishProcess is None:
        stockfishProcess = pexpect.spawn(STOCKFISH)
        stockfishProcess.delaybeforesend = 0
        stockfishProcess.expect_exact("Stockfish DD 64 SSE4.2 by Tord Romstad, Marco Costalba and Joona Kiiski\r\n")

    cmds = "position startpos moves " + " ".join(moves) + "\nd\neval\n"
    stockfishProcess.send(cmds + "isready\n\n")
    lines = []
    while True:
        l = stockfishProcess.readline().rstrip()
        if l == "readyok":
            stockfishProcess.expect_exact("readyok\r\n")
            if verbose: print("\n".join(lines))
            return lines
        elif l != "":
            lines.append(l)

def stockfishEval(moves, verbose=False, empty=False):
    fen = ""
    legalMoves = ""
    scores = dict()
    pctM =float("nan")
    pctE1=float("nan")
    pctE2=float("nan")
    total=float("nan")

    if not empty:
        for l in getStockfishLinesFast(moves, verbose=verbose):
            m = re.search("^Fen: (.*)$", l)
            if m: fen = m.group(1)

            m = re.search("^Legal moves: (.*)$", l)
            if m: legalMoves = m.group(1)

            if any(l.startswith(h) for h in SCORE_HEADERS):
                name, s = getScores(l)
                scores[name] = s

            m = re.search("^Scaling: +([0-9.]+)% MG, +([0-9.]+)% \* +([0-9.]+)% EG.$", l)
            if m:
                pctM  = float(m.group(1))
                pctE1 = float(m.group(2))
                pctE2 = float(m.group(3))

            m = re.search("Total evaluation: ([0-9.-]+)$", l)
            if m:
                total = float(m.group(1))

    #print 'fen=%s' % fen
    #print 'legalMoves=%s' % legalMoves
    #print 'scores=%s' % scores
    #print 'pctM=%s' % pctM
    #print 'pctE1=%s' % pctE1
    #print 'pctE2=%s' % pctE2
    #print 'total=%s' % total
    return fen, legalMoves, scores, pctM, pctE1, pctE2, total

def loadMovesAndResult(filenames):
    for filename in filenames:
        with open(filename, 'r') as f:
            for i, l in enumerate(f):
                l = l.strip()
                if l.startswith("[") or l == "":
                    lines = []
                    continue
                else:
                    src = "%s:%d" % (filename, i+1)
                    lines.append(l)

                    ## once we have result line, yield this game
                    if l.endswith("0-1") or l.endswith("1-0") or l.endswith("1/2-1/2"):
                        movesline = (" ".join(lines))
                        moves = re.sub("([0-9]+\\.) *", "\n\\1", movesline).lstrip()

                        moves = [m.strip().split(".") for m in moves.split("\n")]
                        n = len(moves)

                        turnNumbers = [int(m[0]) for m in moves]
                        assert turnNumbers == range(1,n+1)

                        moves = [m[1].split(" ") for m in moves]

                        assert len(moves[n-1]) in [2,3] ## black may not have moved, and result should be last
                        result = moves[n-1][-1]
                        assert result in ["1-0", "0-1", "1/2-1/2"]
                        moves[n-1] = moves[n-1][:-1]

                        assert all(len(m) in [1,2] for m in moves)

                        yield src, moves, result


def main():
    assert len(sys.argv) >= 2
    filenames = sys.argv[1:]
    verbose = False

    header  = "src,n,moveNumber,colorMoving,move,fen,result,resultReplay"
    header += ",MaterialPSTTempoTM,MaterialPSTTempoTE"
    header += ",MaterialImbalanceTM,MaterialImblanceTE"
    header += ",PawnsTM,PawnsTE"
    header += ",KnightsWM,KnightsWE,KnightsBM,KnightsBE,KnightsTM,KnightsTE"
    header += ",BishopsWM,BishopsWE,BishopsBM,BishopsBE,BishopsTM,BishopsTE"
    header += ",RooksWM,RooksWE,RooksBM,RooksBE,RooksTM,RooksTE"
    header += ",QueensWM,QueensWE,QueensBM,QueensBE,QueensTM,QueensTE"
    header += ",MobilityWM,MobilityWE,MobilityBM,MobilityBE,MobilityTM,MobilityTE"
    header += ",KingSafetyWM,KingSafetyWE,KingSafetyBM,KingSafetyBE,KingSafetyTM,KingSafetyTE"
    header += ",ThreatsWM,ThreatsWE,ThreatsBM,ThreatsBE,ThreatsTM,ThreatsTE"
    header += ",PassedPawnsWM,PassedPawnsWE,PassedPawnsBM,PassedPawnsBE,PassedPawnsTM,PassedPawnsTE"
    header += ",SpaceWM,SpaceWE,SpaceBM,SpaceBE,SpaceTM,SpaceTE"
    header += ",pctMidGame,pctEndGame1,pctEndGame2,totalScore"
    print header

    for src, moves, result in loadMovesAndResult(filenames):
        if verbose: print src, moves, result

        chess = ChessBoard()
        resultReplay = "NA"

        textMoves = []
        n = 0
        for i, turn in enumerate(moves):
            moveNumber = i+1
            for j, m in enumerate(turn):
                n += 1
                colorMoving = "WB"[j]
                if verbose: print n, " (", colorMoving, "):", m
                assert chess.addTextMove(m), chess.getReason()
                textMoves.append(chess.getLastTextMove(ChessBoard.AN))

                if verbose:
                    chess.printBoard()
                    print "moves/2 = ", len(textMoves)/2
                if chess.isGameOver():
                    resultCode = chess.getGameResult()
                    resultReplay = {1:"WHITE_WIN", 2:"BLACK_WIN", 3:"STALEMATE",4:"FIFTY_MOVES_RULE",5:"THREE_REPETITION_RULE"}[resultCode]

                ## evaluate using stockfish
                stockfishFEN, legalMoves, scores, pctM, pctE1, pctE2, total = stockfishEval(textMoves, verbose=verbose)

                fen = chess.getFEN()
                assert fen == stockfishFEN

                row  = "%(src)s,%(n)d,%(moveNumber)d,%(colorMoving)s,%(m)s,%(fen)s,%(result)s,%(resultReplay)s" % locals()
                s = scores['Material, PST, Tempo']; row += ',%(TM)s,%(TE)s' % s
                s = scores['Material imbalance'];   row += ',%(TM)s,%(TE)s' % s
                s = scores['Pawns'];                row += ',%(TM)s,%(TE)s' % s
                s = scores['Knights'];              row += ',%(WM)s,%(WE)s,%(BM)s,%(BE)s,%(TM)s,%(TE)s' % s
                s = scores['Bishops'];              row += ',%(WM)s,%(WE)s,%(BM)s,%(BE)s,%(TM)s,%(TE)s' % s
                s = scores['Rooks'];                row += ',%(WM)s,%(WE)s,%(BM)s,%(BE)s,%(TM)s,%(TE)s' % s
                s = scores['Queens'];               row += ',%(WM)s,%(WE)s,%(BM)s,%(BE)s,%(TM)s,%(TE)s' % s
                s = scores['Mobility'];             row += ',%(WM)s,%(WE)s,%(BM)s,%(BE)s,%(TM)s,%(TE)s' % s
                s = scores['King safety'];          row += ',%(WM)s,%(WE)s,%(BM)s,%(BE)s,%(TM)s,%(TE)s' % s
                s = scores['Threats'];              row += ',%(WM)s,%(WE)s,%(BM)s,%(BE)s,%(TM)s,%(TE)s' % s
                s = scores['Passed pawns'];         row += ',%(WM)s,%(WE)s,%(BM)s,%(BE)s,%(TM)s,%(TE)s' % s
                s = scores['Space'];                row += ',%(WM)s,%(WE)s,%(BM)s,%(BE)s,%(TM)s,%(TE)s' % s
                row += ",%(pctM)f,%(pctE1)f,%(pctE2)f,%(total)f" % locals()
                print row

                #print "%(src)s,%(n)d,%(moveNumber)d,%(colorMoving)s,%(m)s,%(fen)s,%(result)s,%(resultReplay)s,%(pctM)f,%(pctE1)f,%(pctE2)f,%(total)f" % locals()

#this calls the 'main' function when this script is executed
if __name__ == '__main__': main()
