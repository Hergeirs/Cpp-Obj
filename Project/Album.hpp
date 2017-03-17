#ifndef ALBUM
#define ALBUM

#include "Song.hpp"
#include <vector> // vector

class Album
{
	private:
		string name;
		vector <Song> songs;

	public:
		Album();									//constructor.
		~Album();									//destructor.
		void clear();								//to clear songs from album.
		void print(bool simple = false) const;		//print songs in album.
		const vector <Song> & getSongs() const;		//gives vector with songs by reference.
		const int getAmount() const;				//returns amount of songs in vector.
		const string & getName() const;				//returns name of album.
		const int getTotalTime() const;				//returns combined playing time of album (seconds).
		const string getFormatTime() const;			//formats getFormatTime() output as string.
		void setName(const string & pName);			//sets name of album using the inputted string.
		void addSong(Song song);					//adds song to the vector.



		//overloading comparison operator
		const bool operator < (Album & album);		
};
// overloading if and ofstream for album objects.
const ostream & operator << (ostream & os,const Album & album);
const istream & operator >> (istream & is, Album & album);

#endif
