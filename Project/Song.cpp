#include "Song.hpp"

//------------------------------------------------------------------------------
// Default constructor. Default values used for printing frame
//------------------------------------------------------------------------------

Song::Song()
{
	title="Title";
	artist="Artist";
}
//Destructor... not needed just good form to include
Song::~Song()
{
	//
}

//------------------------------------------------------------------------------
// Get title of song. Used for non member functions specifically overloadings.
//------------------------------------------------------------------------------

const string & Song::getTitle() const
{
	return title;
}

//------------------------------------------------------------------------------
// returns artist name. Used for overloading (non-memberfunction).
//------------------------------------------------------------------------------

const string & Song::getArtist() const
{
	return artist;
}

//------------------------------------------------------------------------------
// Returns song's time element as constant reference
//------------------------------------------------------------------------------

const Time & Song::getTime() const
{
	return time;
}

//------------------------------------------------------------------------------
// memberfunction to print a song. Takes integer for index and bool for mode.
//------------------------------------------------------------------------------

void Song::print(int i,bool simple) const
{
	int width = 15;
	const string delim=" | ";
	cout << "| ";
	cout << left; // ensuring all songs start left-aligned
	if (i==0)
		cout << setw(4) << "Nr";
	else
		cout << setw(4) << i;
	if (simple)
		cout << setw(50) << title << setw(31) << delim << endl;
	else
		cout << setw(50) << title << setw(width) << artist << setw(width) << right << time.getFormatTime() << delim << endl;
}

//------------------------------------------------------------------------------
// memberfunction to set name of song.
//------------------------------------------------------------------------------

void Song::setTitle(string pTitle)
{
	title=pTitle;
}

//------------------------------------------------------------------------------
// memberfunction to set name of artist. used by non member/friend functions.
//------------------------------------------------------------------------------

void Song::setArtist(string pArtist)
{
	artist=pArtist;
}

//------------------------------------------------------------------------------
// set time. used by non member functions. ifstream and jukebox functions
//------------------------------------------------------------------------------

void Song::setTime(Time & pTime)
{
	time=pTime;
}
void Song::setTime(int seconds)
{
	time.setTime(seconds);
}

//------------------------------------------------------------------------------
// in/out file overloadings for song objects
//------------------------------------------------------------------------------

const ostream & operator << (ostream & os,const  Song & song)
{
	os << song.getTitle() << '|' << song.getArtist() << '|' << song.getTime();
	os << endl;
	return os;
}

const istream & operator >> (istream & os, Song & song)
{
	Time time;
	string s;
	getline(os,s,'|');
	song.setTitle(s);
	getline(os,s,'|');
	song.setArtist(s);
	os >> time;
	song.setTime(time);
return os;
}
