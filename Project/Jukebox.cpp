#include "Jukebox.hpp"
#include <algorithm>

//------------------------------------------------------------------------------
// Default constructor
//------------------------------------------------------------------------------

Jukebox::Jukebox() // Default initializer
{
	//main menu
	mainMenu.setMenuTitle("Main menu");
	mainMenu.addItem("File", true);
	mainMenu.addItem("Add an album", false);
	mainMenu.addItem("Delete an album", false);
	mainMenu.addItem("Print",false);
	mainMenu.addItem("Play",false);
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
// Function to to ask whether user's sure about deletion
//------------------------------------------------------------------------------

bool sure(bool all=true)
{
	while (true)
	{
		printPrompt("You will loose all current albums!","WARNING!",false,true,35);
		printPrompt("0:Abort, 1:continue","are you sure?",false,false,35);
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
		if(sure(true))
			albums.erase(albums.begin()+result);
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
	if (result!=albums.size())
		albums[result].print();
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
				playMenu.disable(3); //disabling playList when list is empty
				break;
			case 4:
				return;				// exit condition
		}
		if (!queue.isEmpty())
			playMenu.enable(3); //enabling play choice when queue not empty
	}while(true);
}

//------------------------------------------------------------------------------
// remove everything that's not an integer from string.
//------------------------------------------------------------------------------

string removeNonInt(string & s)
{
	string newS, unRecognized;
	int i=-1;
	while(unsigned(++i)<s.size())
	{
		if(isdigit(s[i]) || s[i]==' ')
			newS.push_back(s[i]);
		else
			unRecognized.push_back(s[i]);
	}
		s=newS;
	return unRecognized;
}

//------------------------------------------------------------------------------
// replace a delim with another delim. In this case ',' with space
//------------------------------------------------------------------------------

void replaceDelim (string & s ,const char oldDelim = ',',const string newDelim=" ")
{
	size_t a = 0;
	while ((a = s.find(oldDelim)) && a!=string::npos)
		s.replace(a,1,newDelim);
}

//------------------------------------------------------------------------------
// extract all integers from string with space as delim
//------------------------------------------------------------------------------

vector <int> getIntegers(string & s)	//no reference in case string must be reused
{
	size_t a;
	vector <int> integers;
	while((a = s.find(' ')) && !(s.empty())) // while s is not empty
	{
		integers.push_back(toInt(s.substr(0,a)));
		if (a!=string::npos)	// delete found space as well.
			++a;
		s.erase(0,a);
	}
	return integers;
}

//------------------------------------------------------------------------------
// Create playlist using vector of integers representing song-numbers.
//------------------------------------------------------------------------------

vector <string> Jukebox::createPlayList(vector <int> & choices)
{
	vector <string> notSongs;				// for error message
	for (auto c :choices)
	{
		if(c<=getAmountSongs() && c>0)
			queue.push_back(getSong(c));
		else
			notSongs.push_back(toString(c));
	}
	return notSongs;
}

//------------------------------------------------------------------------------
// Create playlist using keyboard input.
//------------------------------------------------------------------------------

void Jukebox::createPlayList()
{
	string s, error;
	printPrompt("Add song to playlist","Playlist",false,false,80);
	printSongList();

	getLine(s,"Enter list of songs separated by comma:");
	replaceDelim(s);						// replace all commas with spaces.
	edgeTrim(s);							// remove excessive spaces.
	error = removeNonInt(s);				// removing wrong characters and return them
	vector <int> choices=getIntegers(s);	//getting all integers in list.
	vector <string> wrong = createPlayList(choices);

	if(!error.empty() || !wrong.empty())
	{
		if(!error.empty())
		{
			printPrompt("Unrecognized input's: ","error",false,true);
			centerText("non integers: "+error,' ');
		}
		if(!wrong.empty())
		for (auto error :wrong)
			centerText("Not valid choice: "+error,' ');
		cout << endl;
	}
		printPrompt(toString(queue.size())+" songs where added to queue","Songs added",true,false);
}

//------------------------------------------------------------------------------
// Create a playlist using default random engine. user inputs amount of songs
//------------------------------------------------------------------------------

void Jukebox::createRandomList()
{
	int amount;
	getInt(amount,"Enter amount of songs to be added to playlist: ");
	default_random_engine generator((signed short int) time(0));
	uniform_int_distribution<int> distribution(1,getAmountSongs ());

	for (int i=0;i<amount;++i)
		queue.push_back(getSong( distribution(generator)));

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
	centerText("",'_','_',0,80);
	Song().print(0);
	int i=0;
	for (auto a:albums)
		for (auto s:a.getSongs())
			s.print(++i);
	centerText("",'_','_',0,80);
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
// used to print list of albums and its' songs. Takes option to print simple output
//------------------------------------------------------------------------------

void Jukebox::printAll(bool simple) const
{
	for_each(albums.begin(),albums.end(), //the mandatory for_each usage.
	[simple](const Album & a)
	{
		a.print(simple);
	});	
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
			sort(albums.begin(),albums.end()); //using default '<' overloading
			break;
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