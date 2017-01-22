//Gustavo J. Munoz
//Assignment 4 - menu.cpp

// An object of type Song will store information about a single
// digitally recorded song file.  

#include <iostream>
#include "song.h"
#include "playlist.h"
#include <cctype>

using namespace std;

//ShowMenu() --------------------------------------------------------------------------------------
void ShowMenu()
{
    cout << " *** Playlist Menu *** " << '\n';
    cout << "\tA or a \tAdd a song to the playlist" << '\n'; 			
    cout << "\tF or f \tFind a song on the playlist" << '\n';			
    cout << "\tD or d \tDelete a song from the playlist" << '\n';
    cout << "\tS or s \tShow the entire playlist" << '\n';
    cout << "\tC or c \tCategory summary" << '\n';
    cout << "\tZ or z \tShow playlist size" << '\n';
    cout << "\tM or m \tShow this Menu" << '\n';
    cout << "\tX or x \teXit the program" << '\n';
}

//GetChar() ---------------------------------------------------------------------------------------
char GetAChar(const char* promptString)
{
    char response;			// the char to be returned
	    
    cout << promptString;		// Prompt the user
    cin >> response;			// Get a char,
    response = toupper(response);	// and convert it to uppercase
    cin.get();				// Discard newline char from input.
    return response;
}

// Legal()-----------------------------------------------------------------------------------------
char Legal(char c) 
{
    return ((c == 'A') || (c == 'F') || (c == 'D') || (c == 'S') ||
	    (c == 'C') || (c == 'Z') || (c == 'M')|| (c == 'X') || 
	    (c == 'a') || (c == 'f') || (c == 'd') || (c == 's') ||
	    (c == 'c') || (c == 'z') || (c == 'm')|| (c == 'x'));
}

//GetCommand() ------------------------------------------------------------------------------------
char GetCommand()
{
    char cmd = GetAChar("\n\n>");	// Get a command character.
	    
    while (!Legal(cmd)){		// As long as it's not a legal command,display menu and try again.
	    cout << "\nIllegal command, please try again . . ." << '\n';
	    ShowMenu();
	    cmd = GetAChar("\n\n>");
    }
    return cmd;
}

//GetInput()--------------------------------------------------------------------------------------
void GetInput(Song& song)
{
    char t[36];
    char a[21];
    Style c;
    char tempStyle; 		//to read in Style
    int s = 0;

    cout << "Enter a song title: " << endl;
    cin.getline(t, 36);
    //cin >> t;
    //cin.ignore(36, '\n');  

    cout << "Enter a song artist: " << endl;
    cin.getline(a, 21);
    //cin >> a;
    //cin.ignore(21, '\n');


    cout << "Enter a song category: " << endl;
    cout << "(P = pop, R = rock, A = alternative, C = country, H = hiphop, Y = parody)" << endl;
    cin >> tempStyle;
    while (tempStyle != 'P' && tempStyle != 'p' && tempStyle != 'R' && tempStyle != 'r' && 
	tempStyle != 'A' && tempStyle != 'a' && tempStyle != 'C' && tempStyle != 'c' && 
	    tempStyle != 'H' && tempStyle != 'h' && tempStyle != 'Y' && tempStyle != 'y' ){
	cout << "Invalid category.  Please re-enter: " << endl;
	cin >> tempStyle;
    }

    if (tempStyle == 'P' || tempStyle == 'p'){
	c = POP;
    }else if (tempStyle == 'R' || tempStyle == 'r') {
	c = ROCK;
    }else if (tempStyle == 'A' || tempStyle == 'a') {
	c = ALTERNATIVE;
    }else if (tempStyle == 'C' || tempStyle == 'c') {
	c = COUNTRY;
    }else if (tempStyle == 'H' || tempStyle == 'h') {
	c = HIPHOP;
    }else if (tempStyle == 'Y' || tempStyle == 'y') {
	c = PARODY;
    }else {
	cout << "Invalid category.  Please re-enter: " << endl;
    }

    cin.ignore();

    while(s <= 0){
	cout << "Enter a song size (kb): " << endl;
	cin >> s;
	if(s <= 0){
	    cout << "Must enter a positive size.  Please re-enter: " << endl;
	}
    }    
    song.Set(t,a,c,s);
}

// main() -----------------------------------------------------------------------------------------
int main()
{
    Playlist p;

    char command;
    do{
	ShowMenu();
	Song song;
	char lookupString[36];

	command = GetCommand();
	switch (command){
	    case 'A': 
		GetInput(song);
		p.Insert(song);
		break;
	    case 'F':
		cout << "\tType a SONG TITLE or ARTIST to be searched, followed by <Enter>: ";
		cin.getline(lookupString, 36);
		p.Lookup(lookupString);				break;
	    case 'D': 
		cout << "\nType name to be removed, followed by <Enter>: ";
		cin.getline(lookupString, 36);
		p.Remove(lookupString);
		break;
	    case 'S': 
		p.DisplayPlaylist();			
		p.ShowPlaylistSize();
		break;
	    case 'C': 
		cout << " Please enter category: " << '\n';
		cin.getline(lookupString, 36);
		p.DisplayPlaylistCategory(lookupString);
	    ;	break;
	    case 'Z': p.ShowPlaylistSizeKB();			break;
	    case 'M': ShowMenu();				break;	  
	    case 'X':						break;

	    case 'a': 
		GetInput(song);
		p.Insert(song);
		break;
	    case 'f': 
		cout << "\tType a SONG TITLE or ARTIST to be searched, followed by <Enter>: ";
		cin.getline(lookupString, 36);
		p.Lookup(lookupString);				break;
	    case 'd': 
		cout << "\nType name to be removed, followed by <Enter>: ";
		cin.getline(lookupString, 36);
		p.Remove(lookupString);				
		break;
	    case 's': p.DisplayPlaylist();			break;
	    case 'c': 
		cout << " Please enter category: " << '\n';
		cin.getline(lookupString, 36);
		p.DisplayPlaylistCategory(lookupString);
		break;
	    case 'z': p.ShowPlaylistSizeKB();			break;
	    case 'm': ShowMenu();				break;	  
	    case 'x':						break;
	    default: 						break;
	}
    }
    while(command != 'X' && command != 'x');
    return 0;
}
       