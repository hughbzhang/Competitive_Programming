import examples


moves = "e4 c5 Nf3 e6 d4 cxd4 Nxd4 a6 Bd3 Nf6 O-O Qc7 Qe2 d6 c4 g6 Nc3 Bg7 Nf3 O-O Bf4 Nc6 Rac1 e5 Bg5 h6 Be3 Bg4 Nd5 Qd8 h3 Nxd5 cxd5 Nd4 Bxd4 Bxf3 Qxf3 exd4 Rc4 Rc8 Rfc1 Rxc4 Rxc4 h5 Qd1 Be5 Qc1 Qf6 Rc7 Rb8 a4 Kg7 b4 h4 Kf1 Bf4 Qd1 Qd8 Rc4 Rc8 a5 Rxc4 Bxc4 Qf6 Be2 Be5 Bf3 Qd8 Qc2 b6 axb6 Qxb6 Qc4 d3"

model = examples.SimpleChessModel()
for m in moves.split():
    model.onChessMove(m)
    print m, model.fairProbabilityEstimate()
