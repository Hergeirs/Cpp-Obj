FILES= main.cpp DataFileReader.cpp DataFilter.cpp TestApp.cpp
FLAGS=-std=c++14 -Wall -pedantic
OUTFILE=main

all:
	g++ ${FILES} -o ${OUTFILE} ${FLAGS};

run:
	./${OUTFILE};
	
memoryCheck:
	valgrind --track-origins=yes --leak-check=full --show-leak-kinds=all ./${OUTFILE};

clean:
	rm *.knt main;
