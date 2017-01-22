//Gustavo J. Munoz
//Assignment 4 - song.cpp

#include <iostream>
#include "song.h"
#include <cstring>

#ifndef _SONG_CPP
#define _SONG_CPP

using namespace std;

// default constructor, sets up blank song object --------------------------------------------------
Song::Song()
{
    strcpy(title, " ");
    strcpy(artist, " ");
    
    size = 0;
}

// Set() -------------------------------------------------------------------------------------------
void Song::Set(const char* t, const char* a, Style st, int sz)
{
    strcpy(title, t);
    strcpy(artist, a);
    category = st;
    size = sz;
}

// GetTitle() --------------------------------------------------------------------------------------
const char* Song::GetTitle() const	
{
    return title;	
}

// GetArtist() -------------------------------------------------------------------------------------
const char* Song::GetArtist() const	
{
    return artist;
}

// GetSize() ---------------------------------------------------------------------------------------
int Song::GetSize() const	
{
    return size;
}

// GetCategory() -----------------------------------------------------------------------------------
Style Song::GetCategory() const
{
    return category;
}

// Display() ---------------------------------------------------------------------------------------
void Song::Display() const
{  
    cout << '\t' << title;
    for (int i = strlen(title) + 1; i < 36; i++)
	cout.put(' ');
    
    cout << '\t' << artist;
    for (int i = strlen(artist) + 1; i < 21; i++)
	cout.put(' ');
    
    //cout << '\t' << category;
    if(category == 0)
    {
	cout << '\t' << "Pop";
    }
    else if(category == 1){
	cout << '\t' << "Rock";
    }
    else if(category == 2){
	cout << '\t' << "Alternative";
    }
    else if(category == 3){
	cout << '\t' << "Country";
    }
    else if(category == 4){
	cout << '\t' << "Hip Hop";
    }
    else if(category == 5){
	cout << '\t' << "Parody";
    }
    else{
	cout << '\t' << "Wrong Input";
    }

    cout << '\t' << static_cast<double>(static_cast<double>(size)/1000);
    cout << '\n' << '\n';
}

#endif





