main: main.o
		g++ -o main main.o

main.o: main.cpp hashTable.h
		g++ -O3 -g -std=c++17 -Wall -pedantic -c main.cpp
clean:
		rm -f main main.o