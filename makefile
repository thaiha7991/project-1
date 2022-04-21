cc=g++
cf=-Wall -g -I include

asm=$(shell uname -m)
obj=alg.o graph.o main.o

all: flights rmobj

flights: $(obj)
	$(cc) $(cf) -o $@.$(asm) $^

alg.o: src/alg.cpp
	$(cc) $(cf) -c $^

graph.o: src/graph.cpp
	$(cc) $(cf) -c $^

main.o: src/main.cpp
	$(cc) $(cf) -c $^

rmobj:
	rm *.o

clean:
	rm flights
