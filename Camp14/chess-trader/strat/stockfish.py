import pexpect
import re

class Stockfish:
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

    def __init__(self):
        self.proc = pexpect.spawn("stockfish")
        self.proc.delaybeforesend = 0
        pattern1 = "Stockfish DD 64 SSE4.2 by Tord Romstad, Marco Costalba and Joona Kiiski\r\n"
        pattern2 = "Stockfish DD 64 by Tord Romstad, Marco Costalba and Joona Kiiski\r\n"
        self.proc.expect_exact([pattern1, pattern2])

    def getScores(self, line):
        cols = [c.strip() for c in line.split("|")]
        name = cols.pop(0)
        scores = [float(s) if s != "---" else float("nan") for c in cols for s in c.split()]
        assert len(scores) == 6
        scores = dict(zip(("WM", "WE", "BM", "BE", "TM", "TE"), scores))
        return name, scores

    def getStockfishLines(self, moves):
        cmds = "position startpos moves " + " ".join(moves) + "\nd\neval\n"
        self.proc.send(cmds + "isready\n\n")
        lines = []
        while True:
            l = self.proc.readline().rstrip()
            if l == "readyok":
                self.proc.expect_exact("readyok\r\n")
                return lines
            elif l != "":
                lines.append(l)
        
    def eval(self, moves, verbose=False, empty=False):
        fen = ""
        legalMoves = ""
        scores = dict()
        pctM =float("nan")
        pctE1=float("nan")
        pctE2=float("nan")
        total=float("nan")
    
        if not empty:
            for l in self.getStockfishLines(moves):
                m = re.search("^Fen: (.*)$", l)
                if m: fen = m.group(1)
    
                m = re.search("^Legal moves: (.*)$", l)
                if m: legalMoves = m.group(1)
    
                if any(l.startswith(h) for h in Stockfish.SCORE_HEADERS):
                    name, s = self.getScores(l)
                    scores[name] = s
    
                m = re.search("^Scaling: +([0-9.]+)% MG, +([0-9.]+)% \* +([0-9.]+)% EG.$", l)
                if m:
                    pctM  = float(m.group(1))
                    pctE1 = float(m.group(2))
                    pctE2 = float(m.group(3))
    
                m = re.search("Total evaluation: ([0-9.-]+)$", l)
                if m:
                    total = float(m.group(1))
    
        return fen, legalMoves, scores, pctM, pctE1, pctE2, total

    
