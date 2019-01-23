SRCDIR = src
BINDIR = bin
LIBDIR = lib
DATADIR = data
TYPE ?= -O5
CPPFLAGS = $(TYPE) -Wall -I./include/ -L./lib/  

CPP = g++

CREATED_OBJECTS = 

OBJECTS = $(CREATED_OBJECTS) 
OBJECTS_LOC = $(OBJECTS:%.o=$(LIBDIR)/%.o)

.PHONY: all clean Makefile

all: 

%.o: 
	make -C src $@
	
%: $(OBJECTS) 
	$(CPP) $(OBJECTS_LOC) $(CPPFLAGS) -o $(BINDIR)/$@ $(SRCDIR)/$@.cpp -lm 
	
clean:
	rm -f bin/* lib/*
	touch bin/.dir
	touch lib/.dir
