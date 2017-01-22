//Gustavo J. Munoz
//Assignment 4 - playlist.cpp

#include <iostream>
#include <cstring>
#include "playlist.h"
#include <iomanip>
#include <stdio.h>
#include <ctype.h>

// Default constructer -----------------------------------------------------------------------------
Playlist::Playlist()
{
    maxSize = 5;
    currentSize = 0;
    songList =  new Song[maxSize]; 
}

// Destructor --------------------------------------------------------------------------------------
Playlist::~Playlist()
{
    delete [] songList;
}

// Insert() ----------------------------------------------------------------------------------------
void Playlist::Insert(Song& song)
/* since the variables being passed in the */
{
    if(currentSize == maxSize){
	Resize();
    }
    songList[currentSize++] = song; //implicity calls songList[currentSize++]'s defaul constructor before assigning song into that element
}

// Lookup() ----------------------------------------------------------------------------------------
void Playlist::Lookup(char* aName) const
{  
    int titleEntry = FindSongbyTitle(aName);	// Locate the name in the directory.
    int artistEntry = FindSongbyArtist(aName);	// Locate the name in the directory.
    
    if (titleEntry == -1 && artistEntry == -1){
	cout << aName << " not found in current directory\n";
    }
    else {
	if(titleEntry != -1) {
	    //at this point, aName, the SONG TITLE found in playlist
	    cout << "\nEntry found: ";
	    songList[titleEntry].Display();	// display entry.
	}
	
	if (artistEntry != -1) {
	    cout << "\nEntry found: ";
	    for (int i = 0; i < currentSize; i++){		// For each entry,
	    if(strcmp(songList[i].GetArtist(), aName) == 0){  
		songList[i].Display();	
	    }
	    }
	}
      
    }
}

// Remove() ----------------------------------------------------------------------------------------
void Playlist::Remove(char* aName)
{
    int thisEntry = FindSong(aName);	// Locate the name in the directory.
	    
    if (thisEntry == -1)
	    cout << aName << " not found in directory" << '\n';
    else{
	    // Shift each succeding element "down" one position in the
	    // Entry array, thereby deleting the desired entry.
	    for (int j = thisEntry + 1; j < currentSize; j++)
		    songList[j - 1] = songList[j];
			    
	    currentSize--;		// Decrement the current number of entries.
	    cout << "Entry removed.\n";
    }
    if(maxSize >= currentSize + 6){
	//maxSize <  currentSize + 6
	Resize();
    }
}


// DisplayPlaylist() -------------------------------------------------------------------------------
void Playlist::DisplayPlaylist() const
{
    if (currentSize == 0){
	cout << "\nCurrent playlist is empty.\n";
	return;
    }
	    
    // Display a header.
    cout << "\n\t***Title***\t\t\t***Artist***\t\t***Style***\t\t***Size (MB)***\n\n";
	    
    for (int i = 0; i < currentSize; i++)		// For each entry,
	songList[i].Display();			// send it to output
}


// DisplayPlaylistCategory() -------------------------------------------------------------------------------
void Playlist::DisplayPlaylistCategory(char* cat) const
{
    int originalPrecision = cout.precision();

    if (currentSize == 0){
	cout << "\nCurrent playlist is empty.\n";
	return;
    }

    // Display a header.
    cout << "\n\t***Title***\t\t\t***Artist***\t\t***Style***\t\t***Size (MB)***\n\n";

    double sumSize(0);
    int numSongs(0);
    
    for (int i = 0; i < currentSize; i++){		
	Style style = songList[i].GetCategory();
	
	char temp = ' ';
	
	//P, R, A, C, H, and Y 
	if (style == POP){
	    temp = 'P';
	}else if (style == ROCK){
	    temp = 'R';
	}else if (style == ALTERNATIVE){
	    temp = 'A';
	}else if (style == COUNTRY){
	    temp = 'C';
	}else if (style == HIPHOP){
	    temp = 'H';
	}else if (style == PARODY){
	    temp = 'Y';
	}else{
	    cout << "Invalid category." << '\n';
	}
	
	//at this point cat variable is all uppercase
	if( temp == toupper(cat[0]) ){  
	    songList[i].Display();
	    sumSize += songList[i].GetCategory();
	    numSongs++;
	}
    }
    cout << "Total size of playlist: " << setprecision(2) << static_cast<double>(sumSize/1000) 
	<< setprecision(originalPrecision) << '\n';
    cout << numSongs << '\n';
}
     
// Resize() ------------------------------------------------------------------------------------------
void Playlist::Resize()
{
    maxSize = currentSize + 5;
    Song* newList = new Song[maxSize];
    
    for(int i = 0; i < currentSize; i++)
    {
	newList[i] = songList[i];
    }
    delete [] songList;
    
    songList = newList;
    cout << "Array is being resized to " << maxSize << "allocated slots." << '\n';
}

// FindSongbyTitle() --------------------------------------------------------------------------------------
int Playlist::FindSongbyTitle(char* aName) const
// Locate a name in the directory.  Returns the
// position of the entry list as an integer if found.
// and returns -1 if the entry is not found in the directory.
{
    for (int i = 0; i < currentSize; i++){	// Look at each entry.
	
	// make both the database song name and search song name uppercase for proper matching 
	int j=0;
	char* songList_song=const_cast<char*>(songList[i].GetTitle());
	char c;
	while (songList_song[j]){
	    c = songList_song[j];
	    c = toupper(c);
	    songList_song[j] = c;
	    j++;
	}
	int k=0;
	char* search_song=const_cast<char*>(aName);
	char d;
	while (search_song[k]){
	    d = search_song[k];
	    d = toupper(d);
	    search_song[k] = d;
	    k++;
	}
	
	if (strcmp(songList_song, search_song) == 0){
	    return i;		// If found, return position and exit.
	    
	}
    }
    return -1;				// Return -1 if never found.
}

// FindSongbyArtist() --------------------------------------------------------------------------------------
int Playlist::FindSongbyArtist(char* aName) const
// Locate a name in the directory.  Returns the
// position of the entry list as an integer if found.
// and returns -1 if the entry is not found in the directory.
{
    for (int i = 0; i < currentSize; i++){	// Look at each entry.
	
	// make both the database song name and search song name uppercase for proper matching 
	int j=0;
	const char* songList_artist = songList[i].GetArtist();
	char* songList_artist2=const_cast<char*>(songList_artist);
	char c;
	while (songList_artist2[j]){
	    c = songList_artist2[j];
	    c = toupper(c);
	    songList_artist2[j] = c;
	    j++;
	}
	int k=0;
	char* search_artist = aName;
	char d;
	while (search_artist[k]){
	    d = search_artist[k];
	    d = toupper(d);
	    search_artist[k] = d;
	    k++;
	}
	
	if (strcmp(songList_artist2, search_artist) == 0)
	    return i;		// If found, return position and exit.
    }
    return -1;				// Return -1 if never found.
}

// FindSong() --------------------------------------------------------------------------------------
int Playlist::FindSong(char* aName) const
// Locate a name in the directory.  Returns the
// position of the entry list as an integer if found.
// and returns -1 if the entry is not found in the directory.
{
    for (int i = 0; i < currentSize; i++){	// Look at each entry.
	if ((strcmp(songList[i].GetTitle(), aName)) == 0 || (strcmp(songList[i].GetArtist(), aName) == 0))
	    return i;		// If found, return position and exit.
    }
    return -1;				// Return -1 if never found.
}

void Playlist::ShowPlaylistSize()
{
    int originalPrecision = cout.precision();
    double sum = 0;
    cout << "Total no. of songs in playlist: " << currentSize << '\n';
    
    for(int i = 0; i < currentSize; i++){
	sum = sum + songList[i].GetSize();
    }    
    cout << "Total size of playlist: " << setprecision(2) << static_cast<double>(sum/1000) 
	<< setprecision(originalPrecision) << '\n';
    cout << '\n';
}

void Playlist::ShowPlaylistSizeKB()
{
    int sum = 0;
    
    for(int i = 0; i < currentSize; i++){
	sum = sum + songList[i].GetSize();
    }    
    cout << "Total size of playlist: " << sum << '\n';
    cout << '\n';
}
