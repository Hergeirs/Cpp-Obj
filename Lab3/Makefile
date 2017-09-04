#compiling all targets is standard... 

U1: U1.o PersonClass.o PersonListClass.o NameClass.o AddressClass.o UserInterfaceClass.o Functions.o
	g++ U1.o PersonClass.o PersonListClass.o NameClass.o AddressClass.o Functions.o UserInterfaceClass.o -o U1

U1.o:
	g++ -c U1.cpp

PersonClass.o:
	g++ -c PersonClass/PersonClass.cpp

PersonListClass.o:
	g++ -c PersonListClass/PersonListClass.cpp

NameClass.o:
	g++ -c NameClass/NameClass.cpp

AddressClass.o:
	g++ -c AddressClass/AddressClass.cpp

UserInterfaceClass.o:
	g++ -c UserInterfaceClass/UserInterfaceClass.cpp

Functions.o:
	g++ -c Functions.cpp

cleanAll:
	rm -f *.o U1

clean:
	rm *.o
