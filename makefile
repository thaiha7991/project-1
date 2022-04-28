cc=g++
cf=-Wall -g -I include

asm=$(shell uname -m)
obj=tasks.o algos.o graph.o main.o
bin=flights.$(asm)

all: flights mvobj

flights: $(obj)
	$(cc) $(cf) -o $(bin) $^

tasks.o: src/tasks.cpp
	$(cc) $(cf) -c $^

algos.o: src/algos.cpp
	$(cc) $(cf) -c $^

graph.o: src/graph.cpp
	$(cc) $(cf) -c $^

main.o: src/main.cpp
	$(cc) $(cf) -c $^

mvobj:
	mkdir obj
	mv *.o obj

clean:
	rm obj/*
	rmdir obj
	rm $(bin)
