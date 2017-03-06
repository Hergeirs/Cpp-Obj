#include "Album.hpp"

Album::Album()
{
	songs = vector <Song> ();
	name="not found";
}

Album::~Album()
{
	//
}

void Album::clear()
{
	songs.clear();
}

void Album::print(bool simple) const
{
	int width=50;
	printPrompt(name," Album name ",false,false);
	if (!simple)
	{
		cout << setw(width) << left << "song title: " << setw(9) << right << "length" << endl;
		for (auto s: songs)
		{
			cout << setw(width) << left << s.getTitle() << setw(9) << right << s.getTime().getFormatTime() << endl;
		}
    }
    cout << setw(width) << left << "Total playing time of "+name+":" << setw(9) << right << getFormatTime() << endl;
    cout << endl;
}

const vector <Song> & Album::getSongs() const
{
	return songs;
}

const Song & Album::getSong (int index) const
{
	return songs[index];
}
void Album::setName(string pName)
{
	name=pName;
}

void Album::addSong(Song song)
{
	songs.push_back(song);
}

const int Album::getAmount()const
{
	return songs.size();
}

const string & Album::getName()const
{
	return name;
}

const int Album::getTotalTime() const
{
int totalTime=0;
	for (auto s: songs)
		totalTime+=s.getTime().getTotalMinutes();
	return totalTime;
}

const string Album::getFormatTime() const
{
	Time totalTime;
	for (auto s:songs)
		totalTime=totalTime+s.getTime();
	return totalTime.getFormatTime();
}

const bool Album::operator < (Album & other)
{
	return getTotalTime() < other.getTotalTime();
}

const ostream & operator << (ostream & os,const Album & album)
{
	os << album.getName() << endl << album.getAmount();
	for (int i=0;i<album.getAmount();++i)
	{
		os << album.getSong(i);
	}
	return os;
}

const istream & operator >> (istream & is, Album & album)
{
	int amountSongs;
	Song song;
	string name;
	getline(is,name);
	album.setName(name);
	is >> amountSongs;
	for (int i=0;i<amountSongs && is >> song;++i)
		album.addSong(song);

	return is;
}

