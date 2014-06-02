SOURCES  = $(wildcard common/*.cpp)
SOURCES += $(wildcard *.cpp)
OBJDIR   = .obj
OBJLIST = $(patsubst %.cpp,$(OBJDIR)/%.o,$(SOURCES))
$(shell echo "-- SOURCES = $(SOURCES)" >&2)

SWIGFILES   = $(wildcard *.i)
SWIGOBJDIR  = $(OBJDIR)/swig
SWIGSOURCES = $(patsubst %.i,%_swig.cxx,$(SWIGFILES))
SWIGOBJLIST = $(patsubst %.i,$(SWIGOBJDIR)/%.o,$(SWIGFILES))
$(shell echo "-- SWIGFILES = $(SWIGFILES)" >&2)

SWIGLIB    = _cstrat.so
SWIGOUTDIR = swig
$(shell echo "-- OUTPUT = $(SWIGOUTDIR)/$(SWIGLIB)" >&2)

CXX = g++
CXXFLAGS = -g -O0 -march=corei7 -Wall -I. -Icommon -fPIC

INCPYTHON = $(shell dirname `locate Python.h | grep -v ".hip" | head -n1`)
$(shell echo "-- INCPYTHON = $(INCPYTHON)" >&2)

.PHONY: clean all
all: $(OBJLIST) $(SWIGLIB)

$(OBLIST): $(wildcard *.h)

$(OBJDIR)/%.o: %.cpp $(OBJDIR)/dummy
	$(CXX) -c $(CXXFLAGS) -o $@ $<

$(SWIGLIB): $(SWIGOBJLIST) $(OBJLIST)
	$(CXX) -shared -o $(SWIGOUTDIR)/$@ $(SWIGOBJLIST) $(OBJLIST)
	rm -f *_swig.cxx

$(SWIGOBJLIST): $(SWIGSOURCES)

$(SWIGSOURCES): $(SWIGFILES) $(OBJDIR)/dummy
	mkdir -p $(SWIGOUTDIR)
	swig -c++ -python -outdir $(SWIGOUTDIR) -o $@ $<

$(SWIGOBJDIR)/%.o: $(SWIGSOURCES) $(OBJDIR)/dummy
	$(CXX) -c $(CXXFLAGS) -I$(INCPYTHON) -Wno-unused-but-set-variable -o $@ $<

clean:
	rm -rf $(OBJDIR)
	rm -f $(SWIGOUTDIR)/*cstrat*
	rm -f *_swig.cxx

$(OBJDIR)/dummy:
	mkdir -p $(OBJDIR)/common
	mkdir -p $(SWIGOBJDIR)
	touch $(OBJDIR)/dummy

