#ifndef ALBUM
#define ALBUM

#include "Song.hpp"
#include <iostream>

class Album
{
	private:
		string name;
		vector <Song> songs;

	public:
		Album();
		~Album();
		void clear();
		void print(bool simple = false) const;
		const vector <Song> & getSongs() const;
		const Song & getSong (int index) const;
		const int getAmount() const;
		const string & getName() const;
		const int getTotalTime() const;
		const string getFormatTime() const;
		void setName(string pName);
		void addSong(Song song);



		//overloading operators
		const bool operator < (Album & album);

};

const ostream & operator << (ostream & os,const Album & album);
const istream & operator >> (istream & is, Album & album);

#endif
