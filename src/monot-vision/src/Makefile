#Define source, dependencies and executable files
_DEPS=temperature_conversion.h
_OBJS=main.o temperature_conversion.o
_EXECUTABLE=test

CC=g++
SDIR=.
IDIR=.
ODIR=output
LDIR=../lib/mosquitto
CFLAGS=-Wall -ggdb -I$(LDIR) -I$(LDIR)/cpp -I$(IDIR)
LDFLAGS=-L$(LDIR) $(LDIR)/cpp/libmosquittopp.so.1 $(LDIR)/libmosquitto.so.1

DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))
OBJS = $(patsubst %,$(ODIR)/%,$(_OBJS))
EXECUTABLE=$(ODIR)/$(_EXECUTABLE)


.PHONY: all clean

all: $(ODIR) $(EXECUTABLE)

#create output dir
$(ODIR):
	-mkdir -p $(ODIR)

#generate executable from all compiled object files
$(EXECUTABLE): $(OBJS) $(DEPS)
	${CXX} $^ -o $@ ${LDFLAGS}
	cp run.sh $(ODIR)

#compile all source codes
$(ODIR)/%.o: $(SDIR)/%.cpp
	${CXX} -c $^ -o $@ ${CFLAGS}

clean:
	-rm -f -R $(ODIR)
