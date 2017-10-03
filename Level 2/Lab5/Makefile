FILES= main.cpp TestApp.cpp ListManipulator.cpp Functions.cpp Menu.cpp MenuItem.cpp 
FLAGS= -O0 -g -std=c++14 -Wall -pedantic
OUTFILE=main

all:
	g++ ${FILES} -o ${OUTFILE} ${FLAGS};

run:
	./${OUTFILE};
	
memoryCheck:
	valgrind -v --track-origins=yes --leak-check=full --show-leak-kinds=all ./${OUTFILE};

clean:
	rm *.knt main;
