//Gustavo J. Munoz
//Assignment 1 - Triangle Class
//September 12, 2014
//triangle.cpp

#include "triangle.h"
#include <iostream>
#include <math.h>

#define numSides 3

using namespace std;

//constructor for triangle class
Triangle::Triangle(int size, char border, char fill){
    //border and fill illustrative chars
    borderChar = border;
    fillChar = fill;
	
    //set limits on triangle side length
    if (size < 1) {
	size = 1;
    }
    else if (size > 39) {
	size = 39;
    }
    else {
	      
    }
    sideLength = size;
}  

// GetSize() - getter to retrieve length of triangle size
int Triangle::GetSize()
{
    return sideLength;
}

// Perimeter() - compute perimeter of triangle
int Triangle::Perimeter()
{
    return (sideLength*numSides);
}
     
// Area() - compute area to 2 decimal places(double)  
double Triangle::Area()
{
    // cast sideLength(int) to a double for computational purposes
    double s = static_cast<double>(sideLength);
    return ((sqrt(3)/4.0)*pow(s, 2));
  
}

// Grow() - increment side length of triangle; respecting length limits
void Triangle::Grow()
{
    if((sideLength >= 1) && (sideLength < 39))
	++sideLength;
      
}

// Shrink() - decrement side length of triangle; respecting length limits
void Triangle::Shrink()
{
    if((sideLength > 1) && (sideLength < 40)){
	--sideLength;
    }
     
}

// SetBorder - set border char (change after initial border char type made during obj initialization)
void Triangle::SetBorder(char border)
{
    borderChar = border;

}

// SetFill - set fill char (change after initial border char type made during obj initialization)
void Triangle::SetFill(char fill)
{
    fillChar = fill;
  
}
// Draw() - draw triangle
void Triangle::Draw()
{
    if(sideLength == 1){
	cout << borderChar;
	return;
    }
  
    int numFillChars(1);  
  
    for(int i = 1; i <= sideLength; i++) { 
	for(int j = sideLength-1; j >=i; j--){
	  cout << " ";
	}
	for(int k = 0; k < numFillChars; ++k){
	    if(k > 0 && k < numFillChars-1) {
	      if(i==sideLength){
		  cout << borderChar;
	      }else{
		  cout << fillChar;
	      }
	    }else{
		cout << borderChar;
	    }
	    
	}
    cout << endl;
    numFillChars +=2;  
    }
}

// Summary() - summarize details of triangle(s)
void Triangle::Summary(){

    cout << "Size of triangles side = " << sideLength << "\n";
    cout << "Perimeter of triangle = " << sideLength*numSides << "\n";
    cout << "Area of triangle = " << (sqrt(3)/4.0)*pow(sideLength, 2) << "\n";
    cout << "Triangle looks like:\n";
    Draw();
  
}






































