all: clean
	g++ Functions.cpp Time.cpp Song.cpp Album.cpp Menu.cpp MenuItem.cpp Queue.cpp Jukebox.cpp main.cpp -o main -g -std=c++11 -Wall -pedantic
	./main
#all: clean Functions.o Time.o Song.o Album.o Menu.o MenuItem.o Jukebox.o main.o
#	g++ Functions.o Time.o Song.o Album.o Menu.o MenuItem.o Jukebox.o main.o -o main -std=c++11 -Wall -pedantic -g

Menu.o:
	g++ -c -g Menu.cpp

MenuItem.o:
	g++ -c -g MenuItem.cpp

main.o:
	g++ -c -g main.cpp

Jukebox.o:
	g++ -c -g Jukebox.cpp

Time.o:
	g++ -c -g Time.cpp

Functions.o:
	g++ -c -g Functions.cpp

Song.o:
	g++ -c -g Song.cpp

Album.o:
	g++ -c -g Album.cpp

Queue.o:

run:
	./main

clean:
	rm -f *.o main
