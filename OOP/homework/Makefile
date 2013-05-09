all: string

string.o: string.hh string.cc
main.o: main.cc string.hh

string: main.o string.o
	g++ main.o string.o -o string

clean:
	rm -rf *~ *.o
