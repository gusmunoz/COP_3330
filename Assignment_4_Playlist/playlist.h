//Gustavo J. Munoz
//Assignment 4 - playlist.h

// An object of type Song will store information about a single
// digitally recorded song file.  

#include <iostream>
#include "song.h"


using namespace std;


class Playlist 
{
  
public:
	Playlist();
	~Playlist();
	
	void Insert(Song& song);
	void Lookup(char* aName) const;
	void Remove(char* aName);
	void DisplayPlaylist() const;
 	void DisplayPlaylistCategory(char* cat) const;
	void ShowPlaylistSize();
	void ShowPlaylistSizeKB();

	
	
private:
	int maxSize;
	int currentSize;
	Song* songList;
	void Resize();
	int FindSong(char* aName) const;
	int FindSongbyTitle(char* aName) const;
	int FindSongbyArtist(char* aName) const;

};

