#ifndef JUKEBOX
#define JUKEBOX

#include "Album.hpp"
#include "Menu.hpp"
#include "Queue.hpp"

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

		void print();
		void load();
		void file();
		void play();
		void addAlbum();
		void deleteAlbum();
		void Sort(Sorts sortBy);
		int printSongList();
		void playList();

		void print(Sorts sortBy,bool simple=false);
		void printAll(bool simple=false)const;
		void save(string fileName="Juketest")const;
		void searchPrint(bool simplePrint=false) const;

		const Song getSong(int i) const;

		unsigned int search (string & albumName) const;

		//Queue

	public:
		Jukebox();
		~Jukebox();
		void run();
};



#endif
