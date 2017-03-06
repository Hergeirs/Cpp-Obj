#ifndef SONG
#define SONG

#include "Time.hpp"
#include <iostream>

class Song
{
	private:
	string title;
	string artist;
	Time time;

	public:
	Song();
	~Song();
	const string & getTitle() const;
	const string & getArtist() const;
	const Time & getTime() const;

	void print(int i=0) const;

	void setTitle(string pTitle);
	void setArtist(string pArtist);
	void setTime(Time & pTime);
	void setTime(int minutes);
};

const ostream & operator << (ostream & os, const Song & song);
const istream & operator >> (istream & os, Song & song);

#endif
