import logging
import threading

class ColorThread(logging.Formatter):
    """Format log lines in color according to which thread did the logging."""
    BLACK, RED, GREEN, YELLOW, BLUE, MAGENTA, CYAN, WHITE = [30+i for i in range(8)]
    def __init__(self, msg):
        logging.Formatter.__init__(self, msg)

    def format(self, record):
        t = threading.current_thread()

        color = None
        if   t.name == "Feed"             : color = ColorThread.BLUE
        elif t.name.startswith("GWIn"    ): color = ColorThread.YELLOW
        elif t.name.startswith("GWOut"   ): color = ColorThread.GREEN
        elif t.name.startswith("GWClient"): color = ColorThread.CYAN
        elif t.name == "GWAccept"         : color = ColorThread.WHITE

        s = logging.Formatter.format(self, record)
        if color is not None:
            s = ("\033[1;%dm" % color) + s + "\033[0m"
        return s

## Globally accessible log object.
log = logging.getLogger()
log.setLevel(logging.DEBUG)

def init():
    """Configure logger to print in the desired format, and with the color handler."""
    ct = ColorThread("%(threadName)-15s %(levelname)-7s %(asctime)s %(filename)10.10s:%(lineno)4d %(funcName)25.25s() %(message)s")
    ch = logging.StreamHandler()
    ch.setFormatter(ct)
    log.addHandler(ch)

init()
