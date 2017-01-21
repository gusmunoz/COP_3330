//Gustavo J. Munoz
//Assignment 3 - Distance.h
//October 3, 2014

//Distance calculator.  Includes an exercise in operator overloading

#include <iostream>


using namespace std;


class Distance {

	friend ostream &operator << (ostream &output, const Distance &D);
	friend istream &operator >> (istream &input, Distance &D);
	friend Distance operator+(const Distance& D1, const Distance& D2);
	friend Distance operator-(const Distance& D1, const Distance& D2);
	friend Distance operator*(const Distance& D, int a);

	friend bool operator>(const Distance& D1, const Distance& D2);
	friend bool operator<(const Distance& D1, const Distance& D2);
	friend bool operator<=(const Distance& D1, const Distance& D2);
	friend bool operator>=(const Distance& D1, const Distance& D2);
	friend bool operator==(const Distance& D1, const Distance& D2);
	friend bool operator!=(const Distance& D1, const Distance& D2);
	
	friend void Convert(int d, Distance &D);

public:

	Distance(); 						// default constructor
	Distance(int d); 					// conversion constructor
	Distance(int mi, int yd, int ft, int in); 		// constructor takes 4 parameters
	~Distance(); 						// destructor
	bool SetDistance(int mi, int yd, int ft, int in);
	void Show() const;
	Distance operator++(); 					// prefix
	Distance operator++(int); 				// postfix
	Distance operator--(); 					// prefix
	Distance operator--(int); 				// postfix


	
private:
	int miles;
	int yards;
	int feet;
	int inches;
};

