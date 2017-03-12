#include "Song.hpp"

Song::Song()
{
	title="Title";
	artist="Artist";
}

Song::~Song()
{
	//
}

const string & Song::getTitle() const
{
	return title;
}

const string & Song::getArtist() const
{
	return artist;
}

const Time & Song::getTime() const
{
	return time;
}

void Song::print(int i,bool simple) const
{
	int width = 15;
	const string delim=" | ";
	cout << left; // ensuring all songs start left-aligned
	if (i==0)
		cout << setw(3) << "Nr";
	else
		cout << setw(3) << i;
	if (simple)
		cout << setw(50) << title << setw(31) << delim << endl;
	else
		cout << setw(50) << title << setw(width) << artist << setw(width) << right << time.getFormatTime() << delim << endl;
}

void Song::setTitle(string pTitle)
{
	title=pTitle;
}

void Song::setArtist(string pArtist)
{
	artist=pArtist;
}

void Song::setTime(Time & pTime)
{
	time=pTime;
}

void Song::setTime(int minutes)
{
	time.setTime(minutes);
}

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
