#compiling all targets is standard... 

all:main.o ArrayClass.o TestClass.o
	g++ main.o ArrayClass.o TestClass.o -o main

main.o:
	g++ -c main.cpp


ArrayClass.o:
	g++ -c ArrayClass/ArrayClass.cpp

TestClass.o:
	g++ -c TestClass/TestClass.cpp

run:
	./main

cleanAll:
	rm -f *.o main

clean:
	rm *.o
	

