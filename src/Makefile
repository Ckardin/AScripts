.PHONY: mrproper, clean, install
# .PHONY: clean, doc, install, Prepare

.SUFFIXES:

BINDIR=$(ASHES_DIR)/bin
LIBDIR=$(ASHES_DIR)/lib
INCDIR=$(ASHES_DIR)/inc

CC=g++
AR=ar
CXXFLAGS=-fPIC -O2 -Wall -Wextra -Werror -I./
OBJS=Diff.o Echo.o Lines.o MakeInfo.o Spaces.o

all: AScripts.o $(OBJS)
	$(CC) -shared -fPIC $< -o AScripts.$(A_SHLIB)
	$(AR) rcs AScripts.$(A_STLIB) $<
	$(CC) -fPIC $< Diff.o     -o Diff
	$(CC) -fPIC $< Echo.o     -o Echo
	$(CC) -fPIC $< Lines.o    -o Lines
	$(CC) -fPIC $< MakeInfo.o -o MakeInfo
	$(CC) -fPIC $< Spaces.o   -o Spaces

install:
	$(CP) Diff $(BINDIR)/
	$(CP) Echo $(BINDIR)/
	$(CP) Lines $(BINDIR)/
	$(CP) MakeInfo $(BINDIR)/
	$(CP) Spaces $(BINDIR)/
	$(CP) AScripts.$(A_SHLIB) $(LIBDIR)/
	$(CP) AScripts.$(A_STLIB) $(LIBDIR)/
	$(CP) AScripts.h $(INCDIR)/

AScripts.o: AScripts.cpp AScripts.h
	$(CC) $(CXXFLAGS) -c $< -o $@
	strip $@

%.o: %.cpp AScripts.o
	$(CC) $(CXXFLAGS) -c $< -o $@
	strip $@

clean:
	$(RM) *.o

mrproper: clean
	$(RM) Ascripts.$(A_SHLIB)
	$(RM) AScripts.$(A_STLIB)