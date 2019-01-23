SRCDIR = ./
BINDIR = ../bin
LIBDIR = ../lib
DATADIR = ../data
TYPE ?= -O5
CPPFLAGS = $(TYPE) -Wall -I../include/ -L../lib/ 
CFLAGS = $(TYPE) -Wall -I../include/ -L../lib/ 

CPP = g++

%.o: %.cc 
	$(CPP) $(CPPFLAGS) -c $< -o $(LIBDIR)/$@ 


%.o: %.cpp
	$(CPP) $(CPPFLAGS) -c $< -o $(LIBDIR)/$@


%.o: %.c
	$(CPP) $(CFLAGS) -c $< -o $(LIBDIR)/$@

	
