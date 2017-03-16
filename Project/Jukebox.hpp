#ifndef JUKEBOX
#define JUKEBOX

#include "Album.hpp"
#include "Menu.hpp"
#include "Queue.hpp"
#include <random>
#include <time.h>

using namespace std;

enum Sorts
{
	BYNAME,
	BYTIME,
};

class Jukebox
{
	private:
		vector <Album> albums;
		Menu mainMenu,fileMenu,printMenu,playMenu;
		Queue queue;
		
		void createPlayList();
		vector <string> createPlayList(vector <int> & choices);

		void print();
		void load();
		void file();
		void play();
		void addAlbum();
		void deleteAlbum();
		void Sort(Sorts sortBy);
		const int printSongList() const;
		const int getAmountSongs() const;

		void playList();
		void createRandomList();

		void print(Sorts sortBy,bool simple=false);
		void printAll(bool simple=false)const;
		void save(string fileName="Juketest")const;
		void searchPrint(bool simplePrint=false) const;

		const Song getSong(int i) const;

		unsigned int search (const string & albumName) const;

		//Queue

	public:
		Jukebox();
		~Jukebox();
		void run();
};



#endif
