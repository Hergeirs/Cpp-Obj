#compiling all targets is standard... else make U1, make U2 etc...

all: U1 U2 U3

U1: U1.o NameClass.o
	g++ U1.cpp NameClass/NameClass.cpp -o U1

U2: U2.o AddressClass.o
	g++ U2.cpp AddressClass/AddressClass.cpp -o U2

U3: U3.o PersonClass.o NameClass.o AddressClass.o Functions.o
	g++ U3.o PersonClass.o NameClass.o AddressClass.o Functions.o -o U3

U1.o:
	g++ -c U1.cpp

U2.o:
	g++ -c U2.cpp

U3.o:
	g++ -c U3.cpp

PersonClass.o:
	g++ -c PersonClass/PersonClass.cpp
	
AddressClass.o:
	g++ -c AddressClass/AddressClass.cpp
	
NameClass.o:
	g++ -c NameClass/NameClass.cpp
	
Functions.o:
	g++ -c Functions.cpp

cleanAll:
	rm -f *.o U1 U2 U3

clean:
	rm *.o
