FILES= main.cpp Car.cpp TrainStation.cpp Train.cpp Simulation.cpp Time.cpp Event.cpp TrainsSimulation.cpp
FLAGS= -O0 -g -std=c++14 -Wall -pedantic
OUTFILE=main

all:
	g++ ${FILES} -o ${OUTFILE} ${FLAGS};

run:
	./${OUTFILE};
	
memoryCheck:
	valgrind -v --track-origins=yes --leak-check=full --show-leak-kinds=all ./${OUTFILE};

clean:
	rm -f main;
