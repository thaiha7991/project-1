cc=g++
cf=-Wall -g -I include

asm=$(shell uname -m)
obj=algos.o graph.o main.o

all: flights rmobj

flights: $(obj)
	$(cc) $(cf) -o $@.$(asm) $^

algos.o: src/algos.cpp
	$(cc) $(cf) -c $^

graph.o: src/graph.cpp
	$(cc) $(cf) -c $^

main.o: src/main.cpp
	$(cc) $(cf) -c $^

rmobj:
	rm *.o

clean:
	rm flights
