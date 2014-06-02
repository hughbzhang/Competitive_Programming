export CHESS_GATEWAY=imp1
export PATH=/home/usaco35/stockfish-dd-src/src:$PATH
export PYTHONPATH=common:strat:ChessBoard:c++/swig
python strat/run-cstrategy.py -s StockfishStrategy -i Salmon
