class FairPriceModelListener:
    def onFairPrice(self, model):
        pass

class FairPriceModel:
    def __init__(self, name, listeners=None):
        self.name = name
        self.listeners = listeners if listeners is not None else []
        for L in self.listeners:
            assert isinstance(FairPriceModelListener, L)

    def notify(self):
        "FairPriceModels should call notify() when they have finished their computations, and are ready for listeners to act on their prices."
        fp = self.fairPrice()
        for L in listeners:
            L.onFairPrice(self, fp)

    def onChessMessage(self, m):
        pass

    def onExchangeMessage(self, m):
        pass

    def featuresDict(self):
        "Return a dict of arbitrary features."
        return dict()

    def features(self):
        "Return a list of arbitrary features in header order."
        f = self.featuresDict()
        return [str(f.get(h, "")) for h in self.header()]

    def header(self):
        "Return the names of the features to output when dumping this model to csv."
        return list()

    def fairPrice(self):
        "This model's estimated fair price, in range [0,100]."
        pass
