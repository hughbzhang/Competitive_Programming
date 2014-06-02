import sys

import model
import example_models
from messages import *

from log import log

if __name__ == "__main__":
    infilename  = sys.argv[1]
    outfilename = sys.argv[2]

    needHeader = True

    with open(infilename, 'r') as infile:
        with open(outfilename, 'w') as outfile:
            for l in infile.readlines():
                m = example_models.StockfishChessModel("stockfish")

                srcfile, line, result, moves = l.split(",")
                gameId = "%s:%s" % (srcfile, line)
                moves = moves.rstrip().split(" ")

                m.onChessMessage(ChessNewGameMessage(gameId))

                if needHeader:
                    print >>outfile, ",".join("src,line,result,n,move,fairPrice".split(",") + m.header())
                    needHeader = False

                print >>outfile, ",".join([srcfile,line,result,"0","",str(m.fairPrice())] + m.features())
                for i in xrange(len(moves)):
                    msg = ChessMoveMessage(gameId, moves[i], moves[:(i+1)])
                    m.onChessMessage(msg)
                    print >>outfile, ",".join([srcfile,line,result,str(i+1),moves[i],str(m.fairPrice())] + m.features())
