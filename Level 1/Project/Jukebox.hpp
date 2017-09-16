#ifndef JUKEBOX
#define JUKEBOX

#include "Album.hpp"	// need them albums.
#include "Menu.hpp"		// and das menus
#include "Queue.hpp"	// queue important for grade
#include <algorithm>	// used for find_if and soforth
#include <random>		// to randomize songs into queue/playlist.
#include <time.h>		// seed for default_random_engine.

using namespace std;

enum Sorts
{
	BYNAME,
	BYTIME,
};

class Jukebox
{
	private:
		const string FILENAME="Jukebox";

		vector <Album> albums;						//Jukebox needs albums
		Menu mainMenu,fileMenu,printMenu,playMenu; // constructing menus.
		
		//Queue
		Queue queue;

		// File sub-menu
		void file();
		//choice 1
		void load();
		//choice 2
		void save()const;	
		
		// Main menu-choices 1 and 2
		void addAlbum();
		void deleteAlbum();

		//Print sub-menu
		void print();
		//choice 1
		void searchPrint(bool simplePrint=false) const;
		// the rest:
		void print(Sorts sortBy,bool simple=false);
		void printAll(bool simple=false)const;
	
		//Playlist submenu
		void play();
		// choice 1
		void createPlayList();
		// choice 2
		void createRandomList();
		// choice 3
		void playList();


		// functions for extracting list of integer from delim seperated list.
		vector <string> createPlayList(vector <int> & choices);
		void Sort(Sorts sortBy);

		// function to print all songs in jukebox in a list with corresponding index
		const int printSongList() const;
		// Function to get amount of song's total in jukebox
		const int getAmountSongs() const;
		// Function to grab song corresponding to index in above printfunction.
		const Song getSong(int i) const;

		// Function to search for given albumName. Returns index of album if found. 
		// else it returns unvalid index (size()) of array.
		uint search (const string & albumName) const;
		
		vector <Song> makeSongs(size_t amountSongs);

	// All necessary public functions.
	public:
		Jukebox();
		~Jukebox();
		void run();
};
#endif