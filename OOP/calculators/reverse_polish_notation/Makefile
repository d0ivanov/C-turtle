

all: calc


Context.o: Context.cc Context.hh Operation.hh
Calc.o: Calc.cc Calc.hh Context.hh Operation.hh
main.o: main.cc Calc.hh Context.hh Operation.hh
BinOperations.o: BinOperations.cc BinOperations.hh Operation.hh Context.hh

calc: main.o Calc.o Context.o BinOperations.o
	g++ main.o Calc.o Context.o BinOperations.o -o calc

clean:
	rm -f *.o *~ calc

