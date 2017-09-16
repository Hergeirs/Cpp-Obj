all: main.o AddressClass.o NameClass.o PersonClass.o queue.o HousingQ.o Functions.o
	g++ main.o AddressClass.o NameClass.o PersonClass.o queue.o HousingQ.o Functions.o -o main -std=c++11 -Wall -pedantic

main.o:
	g++ -c main.cpp

AddressClass.o:
	g++ -c AddressClass/AddressClass.cpp

NameClass.o:
	g++ -c NameClass/NameClass.cpp

PersonClass.o:
	g++ -c PersonClass/PersonClass.cpp

queue.o:
	g++ -c Queue/queue.cpp

HousingQ.o:
	g++ -c HousingQ/HousingQ.cpp

Functions.o:
	g++ -c Functions/Functions.cpp

run:
	./main

clean:
	rm -f *.o main
