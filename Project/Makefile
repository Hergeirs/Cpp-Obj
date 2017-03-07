all: clean
	g++ Functions.cpp Time.cpp Song.cpp Album.cpp Menu.cpp MenuItem.cpp Queue.cpp Jukebox.cpp main.cpp -o main -g -std=c++11 -Wall -pedantic
#all: clean Functions.o Time.o Song.o Album.o Menu.o MenuItem.o Jukebox.o main.o
#	g++ Functions.o Time.o Song.o Album.o Menu.o MenuItem.o Jukebox.o main.o -o main -std=c++11 -Wall -pedantic -g

Menu.o:
	g++ -c Menu.cpp

MenuItem.o:
	g++ -c MenuItem.cpp

main.o:
	g++ -c main.cpp

Jukebox.o:
	g++ -c Jukebox.cpp

Time.o:
	g++ -c Time.cpp

Functions.o:
	g++ -c Functions.cpp

Song.o:
	g++ -c Song.cpp

Album.o:
	g++ -c Album.cpp

Queue.o:

run:
	./main

clean:
	rm -f *.o main
