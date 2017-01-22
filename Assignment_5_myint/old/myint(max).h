//Gustavo J. Munoz
//Assignment 5 - myint.cpp
//November 6, 2014

#include <iostream>

using namespace std;

// starter file for MyInt class header

class MyInt
{

	  friend MyInt operator+(const MyInt& x, const MyInt& y);
	  friend MyInt operator*(const MyInt& x, const MyInt& y);

	  friend bool operator<(const MyInt& x, const MyInt& y);
	  friend bool operator>(const MyInt& x, const MyInt& y);
	  friend bool operator<=(const MyInt& x, const MyInt& y);
	  friend bool operator>=(const MyInt& x, const MyInt& y);
	  friend bool operator==(const MyInt& x, const MyInt& y);
	  friend bool operator!=(const MyInt& x, const MyInt& y);

	  friend ostream &operator << (ostream &output, const MyInt &m);
	  friend istream &operator >> (istream &input, MyInt &m);


    public:
	  MyInt(int n = 0);			// first constructor
      MyInt(const char str[]);		// second constructor
	  MyInt(const MyInt& s);		// copy constructor
	  ~MyInt();				// destructor
	  
	  MyInt& operator=(const MyInt& s); 	// assignment operator overload
	  MyInt operator++();			// prefix
	  MyInt operator++(int);		// postfix    
	  char& operator [] (int index);	// array accessor

	  
    private:

	// member data (suggested:  use a dynamic array to store the digits)
	  int size;
	  int capacity;
	  char* array;
	  char* newArray(int space);
};






















