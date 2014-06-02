import order

class Order:
    """Order object used with full detail in matching engine, and anonymized in public books."""
    BUY  =  1 ## relying on numeric value to sign in some places
    SELL = -1 ## relying on numeric value to sign in some places

    def __init__(self, oid, qty, side, price, owner=None, gameId=None, goid=None):
        assert side in (Order.BUY, Order.SELL)
        self.oid    = oid    ## order id
        self.qty    = qty    ## quantity of the order (not signed)
        self.side   = side   ## Order.BUY or Order.SELL
        self.price  = price  ## price for the order
        self.owner  = owner  ## owner of the order is determined from Gateway name that sent it
        self.gameId = gameId ## game that this order pertains to
        self.goid   = goid   ## gateway's order id, needed to track pending orders

    def __str__(self):
        """String representation used to display in ladder. Must stay very concise."""
        return str(self.qty)

