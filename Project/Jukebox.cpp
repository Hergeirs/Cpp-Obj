#include "Jukebox.hpp"
#include <algorithm>

//------------------------------------------------------------------------------
// Default constructor
//------------------------------------------------------------------------------

Jukebox::Jukebox() // Default initializer
{
	//main menu
	mainMenu.setMenuTitle("Main menu");
	mainMenu.addItem("File...", true);
	mainMenu.addItem("Add an album", false);
	mainMenu.addItem("Delete an album", false);
	mainMenu.addItem("Print...",false);
	mainMenu.addItem("Play...",false);
	mainMenu.addItem("Exit",true);

	//submenu file
	fileMenu.setMenuTitle("File menu");
	fileMenu.addItem("Open",true);
	fileMenu.addItem("Save",false);
	fileMenu.addItem("Back to main menu",true);

	//submenu print
	printMenu.setMenuTitle("Printing menu");
	printMenu.addItem("Print one album",false);
	printMenu.addItem("Print all sorted by album name",false);
	printMenu.addItem("print all sorted by album total time",false);
	printMenu.addItem("Print simple sorted by album name",false);
	printMenu.addItem("Print simple sorted by album total time",false);
	printMenu.addItem("Back to main menu",true);

	//submenu play
	playMenu.setMenuTitle("Play menu");
	playMenu.addItem("Create a play list from songs",true);
	playMenu.addItem("Create a random list",true);
	playMenu.addItem("Play list",false);
	playMenu.addItem("Back to main menu",true);
}

Jukebox::~Jukebox()
{
	//don't need deconstruct as all types in all subclasses don't need one
}

//------------------------------------------------------------------------------
// Function to Prompt user if he's sure.
//------------------------------------------------------------------------------

void printSure(bool ALL=true)
{
	string what="THIS";
	if (ALL)
		what="ALL current";
	cout << "***********Warning!************" << endl;
	cout << "   Enter integer for action" << endl;
	cout << "Are you sure you want to delete." << endl;
	cout << "     "+what+" albums?" << endl;
	cout << "1: Yes" << endl;
	cout << "0: Back to Menu" << endl;
	cout << "*******************************" << endl;
	cout << endl;
}

//------------------------------------------------------------------------------
// Function to to ask wether user's sure about deletion
//------------------------------------------------------------------------------

bool sure(bool all=true)
{
	while (1)
	{
		printSure(all);
		switch (getInt())
		{
		case 0:
			return false;
		case 1:
			return true;
		default:
			printPrompt("Not valid Choice");
		}
		cls();
	}
}

//------------------------------------------------------------------------------
// run function contains Main menu switch.
//------------------------------------------------------------------------------

void Jukebox::run()
{
	do
	{
		switch (mainMenu.getMenuChoice())
		{
			case 1:
				file();
				break;
			case 2:
				addAlbum();
				break;
			case 3:
				deleteAlbum();
				break;
			case 4:
				print();
				break;
			case 5:
				play();
				break;
			case 6:
				return;	//exiting here
			default:	//don't need default, as getMenuChoice() takes care of unwanted values.
				break;
		}
	}while(true);
}

//------------------------------------------------------------------------------
// submenu switch File
//------------------------------------------------------------------------------

void Jukebox::file()
{
	do
	{
		switch(fileMenu.getMenuChoice())
		{
		case 1:
			if(sure())
			{
				load();
				fileMenu.enableAll(); 		// enabling save menu.
				mainMenu.enableAll();		// enabling all menus in menu.
				printMenu.enableAll();
			}
			break;
		case 2:
			save();
			break;
		case 3:
			return;
		default:
			printPrompt("Something's wrong... must fix");
		}

	}while(true);
}

//------------------------------------------------------------------------------
// Loads All albums from correctly formatted file.
//------------------------------------------------------------------------------

void Jukebox::load()
{
	albums.clear(); 				//Need to clear out albums already in list.
	Album album;
	int amountAlbums=0;
	ifstream is("Juketest");
	if(is.is_open())
		while (is >> album)
		{
			albums.push_back(album);
			album.clear(); //empty album for refill.
			++amountAlbums;
		}
	printPrompt(toString(amountAlbums)+" Albums where loaded.");
	is.close();
}

//------------------------------------------------------------------------------
// Saves to same file we loaded from
//------------------------------------------------------------------------------

void Jukebox::save(string fileName) const
{
	ofstream os("Juketest");
	int amountAlbums=0;
	if(os.is_open())
		for (auto a: albums)
			os << a && ++amountAlbums;
	os.close();
	printPrompt(toString(amountAlbums)+" Albums where saved.");
}

//------------------------------------------------------------------------------
// Add an album to vector using keyboard input.
//------------------------------------------------------------------------------

void Jukebox::addAlbum()
{
	string albumName,songTitle,artist;

	bool found=false;
	do
	{
		getLine(albumName,"Enter name of album: ");
		found=search(albumName)!=albums.size();
		if(found)
			printPrompt("Album named "+ albumName+" already exists in list!");
	}while(found);

	uint amountSongs=getInt("Enter amount of songs in album: ");
	Album album;
	album.setName(albumName);
	Song tmpSong;


	for (uint i=0;i<amountSongs;++i)
	{
		getLine(songTitle,"Name of song : "+toString(i+1));
		getLine(artist,"Name of artist");
		int songLength=getInt("Length of song (seconds): ");
		tmpSong.setTitle(songTitle);
		tmpSong.setArtist(artist);
		tmpSong.setTime(songLength);
		album.addSong(tmpSong);
		printPrompt("Song added");
	}
	albums.push_back(album);
}

//------------------------------------------------------------------------------
// Delete album from vector using keyboard input.
//------------------------------------------------------------------------------

void Jukebox::deleteAlbum()
{
	string searchFor;
	getLine(searchFor,"Enter name of album to delete: ");
	unsigned int result = search(searchFor);
	if (result!=albums.size())
	{
		printPrompt("Are you sure you want to delete: ");
		albums[result].print();
		if(sure(1))
		{
			albums.erase(albums.begin()+result);
		}
	}
	else
		printPrompt(searchFor+" was not found!","Error",false,false);
}

//------------------------------------------------------------------------------
//  submenu switch print
//------------------------------------------------------------------------------


void Jukebox::print()
{
	do
	{
	switch(printMenu.getMenuChoice())
	{
		case 1:
			searchPrint();
			break;
		case 2:
			print(BYNAME);
			break;
		case 3:
			print(BYTIME);
			break;
		case 4:
			print(BYNAME,true);
			break;
		case 5:
			print(BYTIME,true);
			break;
		case 6:
			return;	 // exiting in case 5
	}
	systemPause ();
	}while(true);
}

//------------------------------------------------------------------------------
// Prints single album that matches albumName
//------------------------------------------------------------------------------

void Jukebox::searchPrint(bool simplePrint) const
{
	string searchFor;
	getLine(searchFor,"Enter name of album to print: ");
	unsigned int result = search(searchFor);
	cout << result;
	if (result!=albums.size())
	{
		albums[result].print();
	}
	else
		printPrompt(searchFor+" was not found!");
}

//------------------------------------------------------------------------------
// Printing function takes sorting algorithm and printing setting (simple bool)
//------------------------------------------------------------------------------

void Jukebox::print(Sorts sortBy,bool simple)
{
	Sort(sortBy);
	printAll(simple);
}

//------------------------------------------------------------------------------
// submenu switch play
//------------------------------------------------------------------------------

void Jukebox::play()
{
	do
	{
		switch (playMenu.getMenuChoice())
		{
			case 1:
				createPlayList();
				break;
			case 2:
				createRandomList();
				break;
			case 3:
				playList();
				playMenu.toggle(3); //disabling playList when list is empty
				break;
			case 4:
				return;				// exit condition
		}
		if (!queue.isEmpty())
			playMenu.toggle(3); //enabling play choice when queue not empty
	}while(true);
}

//------------------------------------------------------------------------------
// Create playlist using keyboard input.
//------------------------------------------------------------------------------

void Jukebox::createPlayList()
{
	printPrompt("Add song to playlist","Playlist",false,false);
	int amountSongs = printSongList();
	string s;
	vector <int> choices;
	int songNr;
	size_t a;
	getLine(s,"Enter song choices: ");
	while ((a = s.find(',')) && a!=string::npos)
		s.replace(a,1," ");
	istringstream S(s);
	vector <string> unidentified;
	while(S >> songNr)
	{
		choices.push_back(songNr);	//Just testing whether all input is valid
		S.clear();
	}
	printPrompt("Songs added: ","info!",false,false);
	for (auto songNr:choices)
	{
		Song song;
		if(songNr < amountSongs && songNr > 0)
		{
			song=getSong(songNr);
			queue.push_back(song);
			song.print();
		}
		else
			unidentified.push_back(toString (songNr));
	}
	return;
}

//------------------------------------------------------------------------------
// Create a playlist using default random engine. user inputs amount of songs
//------------------------------------------------------------------------------

void Jukebox::createRandomList()
{
	int amount;
	getInt(amount,"Enter amount of songs to be added for album");
	default_random_engine generator((signed short int) time(0));
	uniform_int_distribution<int> distribution(1,getAmountSongs ());

	for (int i=0;i<amount;++i)
	{
		queue.push_back(getSong( distribution(generator)));
	}

	printPrompt(toString(amount)+" Songs added to playlist.");
}

//------------------------------------------------------------------------------
// Play list. uses queue play memeberfunction
//------------------------------------------------------------------------------

void Jukebox::playList()
{
	queue.play();
	systemPause("Playlist reached end...");
}

//------------------------------------------------------------------------------
// Utility functions. (functions used by main functions.
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
// Function to print list of all songs to chose from. With choice number.
//------------------------------------------------------------------------------

const int Jukebox::printSongList() const
{
	int i=0;
	for (auto a:albums)
		for (auto s:a.getSongs())
			s.print(++i);
	return i;
}

//------------------------------------------------------------------------------
// Get song with number corresponding to "printSongList()" functions output
//------------------------------------------------------------------------------

const Song Jukebox::getSong(int i) const
{
	int n=0;
	for (auto a:albums)
		for (auto s: a.getSongs())
			if(++n==i)
				return s;
	return Song(); //returning empty song if choice is invalid.
}

//------------------------------------------------------------------------------
// used to print list of songs of all albums. Takes option to print simple output
//------------------------------------------------------------------------------

void Jukebox::printAll(bool simple) const
{
	for (auto a:albums)
		a.print(simple);
}

//------------------------------------------------------------------------------
// returns total amount of songs in jukebox. Used for random creation of list
// and filtering user input.
//------------------------------------------------------------------------------

const int Jukebox::getAmountSongs() const
{
int amountSongs=0;
	for (auto album:albums)
		amountSongs+=album.getAmount();
	return amountSongs;
}

//------------------------------------------------------------------------------
// Sorting functions Takes enum of sort.
//------------------------------------------------------------------------------

void Jukebox::Sort(Sorts sortBy)
{
	switch(sortBy)
	{
		case BYNAME:
			sort(albums.begin(),albums.end(),
				[](const Album & a,const Album & b)
				{
					return toCase(a.getName()) < toCase(b.getName());
				});
			break;
		case BYTIME:
			sort(albums.begin(),albums.end());
			break;
		default:
			printPrompt("No such sort");
	}
}

//------------------------------------------------------------------------------
// Searches for album using album name as search string
//-----------------------------------------------------------------------------

unsigned int Jukebox::search (const string & albumName) const
{
	auto it = find_if(albums.begin(),albums.end(),
		[&albumName](const Album & a)
		{
			return toCase(a.getName())==toCase(albumName);
		});
	if(it == albums.end())
		return albums.size();
	return it-albums.begin();
}