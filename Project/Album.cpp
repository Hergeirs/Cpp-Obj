#include "Album.hpp"
//------------------------------------------------------------------------------
// Default constructor and destructor
//------------------------------------------------------------------------------

Album::Album()
{
	songs = vector <Song> ();
	name="not found";
}

Album::Album(string & albumName, vector <Song> pSongs):name(albumName),songs(pSongs){}

Album::~Album()
{
	//
}

//------------------------------------------------------------------------------
// Function to clear list of songs
//------------------------------------------------------------------------------

void Album::clear()
{
	songs.clear();
}

//------------------------------------------------------------------------------
// printing function takes bool to determine whether it should print all output
//------------------------------------------------------------------------------
void Album::print(bool simple) const
{
	int i=0;
	printPrompt("Total time: "+getFormatTime(),name,false,false,80);

   // cout << '|' << setw(70) << left << " Total playing time: " << setw(15) << right << getFormatTime() << " |" << endl;

	if (!simple)
	{
		centerText("",'_',' ',0,80);
		Song().print(0,false);
		for (auto & s: songs)
			s.print(++i,false);
		centerText("",'_','|',0,80);
	}
	
    cout << endl;
}

//------------------------------------------------------------------------------
// Function to get const song vector from album
//------------------------------------------------------------------------------

const vector <Song> & Album::getSongs() const
{
	return songs;
}

//------------------------------------------------------------------------------
// Set the name of album.
//------------------------------------------------------------------------------

void Album::setName(const string & pName)
{
	name=pName;
}

//------------------------------------------------------------------------------
// add songs to vector.
//------------------------------------------------------------------------------

void Album::addSongs(vector <Song> & addSongs)
{
	songs=addSongs;
}

//------------------------------------------------------------------------------
// add song to vector.
//------------------------------------------------------------------------------

void Album::addSong(Song song)
{
	songs.push_back(song);
}

//------------------------------------------------------------------------------
// Get amount of songs in album. used to find total amount of songs. 
//------------------------------------------------------------------------------

const int Album::getAmount()const
{
	return songs.size();
}

//------------------------------------------------------------------------------
// okkurt um funktiónina. Get the name of album. This is used for "<<" overload
//------------------------------------------------------------------------------

const string & Album::getName()const
{
	return name;
}

//------------------------------------------------------------------------------
// Total time. Used to print.
//------------------------------------------------------------------------------

const int Album::getTotalTime() const
{
int totalTime=0;
	for (auto s: songs)
		totalTime+=s.getTime().getTotalSeconds();
	return totalTime;
}

//------------------------------------------------------------------------------
// get total time  of album formatted for printing as string.
//------------------------------------------------------------------------------

const string Album::getFormatTime() const
{
	return Time(getTotalTime()).getFormatTime();
}

//------------------------------------------------------------------------------
// operator overloadings
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
// overloading for comparing albums using their total time.
//------------------------------------------------------------------------------

const bool Album::operator < (Album & other)
{
	return getTotalTime() < other.getTotalTime();
}

//------------------------------------------------------------------------------
// overloading ofstream with operator '<<' for Album
//------------------------------------------------------------------------------

const ostream & operator << (ostream & os,const Album & album)
{
	os << album.getName() << endl << album.getAmount() << endl;
	for (auto s: album.getSongs())
		os << s;
	return os;
}

//------------------------------------------------------------------------------
// overloading ifstream with operator '>>' for album
//------------------------------------------------------------------------------

const istream & operator >> (istream & is, Album & album)
{
	int amountSongs;
	Song song;
	string name;
	getline(is,name);
	album.setName(name);
	is >> amountSongs;
	is.get();
	for (int i=0;i<amountSongs && is >> song;++i)
		album.addSong(song);
	return is;
}