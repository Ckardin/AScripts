.PHONY: mrproper, clean, install
# .PHONY: clean, doc, install, Prepare

.SUFFIXES:

CC=g++
AR=ar
CXXFLAGS=-O2 -Wall -Wextra -Werror -I./
OBJS=Diff.o Echo.o Lines.o MakeInfo.o Spaces.o

A_SHLIB=so
A_STLIB=a
A_EXT=
BINDIR=$(ASHES_DIR)/bin
LIBDIR=$(ASHES_DIR)/lib
INCDIR=$(ASHES_DIR)/inc
A_SHLIB=so
A_STLIB=a
A_EXT=
BINDIR=$(ASHES_DIR)/bin
LIBDIR=$(ASHES_DIR)/lib
INCDIR=$(ASHES_DIR)/inc

all: AScripts.o $(OBJS)
	$(AR) rcs libAScripts.$(A_STLIB) $<
	$(CC) Diff.o     -o Diff$(A_EXT)     -L. -lAScripts
	$(CC) Echo.o     -o Echo$(A_EXT)     -L. -lAScripts
	$(CC) Lines.o    -o Lines$(A_EXT)    -L. -lAScripts
	$(CC) MakeInfo.o -o MakeInfo$(A_EXT) -L. -lAScripts
	$(CC) Spaces.o   -o Spaces$(A_EXT)   -L. -lAScripts
	$(CC) -shared -fPIC $< -o libAScripts.$(A_SHLIB)

install:
	install -p -m 755 Diff$(A_EXT)     $(BINDIR)
	install -p -m 755 Echo$(A_EXT)     $(BINDIR)
	install -p -m 755 Lines$(A_EXT)    $(BINDIR)
	install -p -m 755 MakeInfo$(A_EXT) $(BINDIR)
	install -p -m 755 Spaces$(A_EXT)   $(BINDIR)
	install -p -m 755 libAScripts.$(A_SHLIB) $(LIBDIR)
	install -p -m 755 libAScripts.$(A_STLIB) $(LIBDIR)
	install -p -m 755 AScripts.h $(INCDIR)

AScripts.o: AScripts.cpp AScripts.h
	$(CC) -fPIC $(CXXFLAGS) -c $< -o $@

%.o: %.cpp AScripts.o
	$(CC) $(CXXFLAGS) -c $< -o $@

clean:
	rm *.o

mrproper: 
	rm libAScripts.$(A_SHLIB)
	rm libAScripts.$(A_STLIB)
	rm Diff$(A_EXT)
	rm Echo$(A_EXT)
	rm Lines$(A_EXT)
	rm MakeInfo$(A_EXT)
	rm Spaces$(A_EXT)