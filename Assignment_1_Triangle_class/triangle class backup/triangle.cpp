#include "triangle.h"
#include <iostream>
#include <math.h>

#define numSides 3

using namespace std;

Triangle::Triangle(int size, char border, char fill){
    borderChar = border;
    fillChar = fill;
	
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

int Triangle::GetSize()
{

    return sideLength;
  
}

int Triangle::Perimeter()
{
  
    return (sideLength*numSides);
      
}
     
double Triangle::Area()
{

    double s = static_cast<double>(sideLength);
    return ((sqrt(3)/4.0)*pow(s, 2));
  
}

void Triangle::Grow()
{

    if((sideLength >= 1) && (sideLength < 39))
      ++sideLength;
      
}

void Triangle::Shrink()
{

if((sideLength > 1) && (sideLength < 40)){
      --sideLength;
    }
     
}

void Triangle::SetBorder(char border){				// void type placeholder --check
    borderChar = border;
  
}

void Triangle::SetFill(char fill){
    fillChar = fill;
  
}
// DRAW FUNCTION DRAW FUNCTION DRAW FUNCTION DRAW FUNCTION DRAW FUNCTION //
void Triangle::Draw(){

  if(sideLength == 1)
  {
    cout << borderChar;
    return;
  }
  
int numFillChars(1);  
  
  for(int i = 1; i <= sideLength; i++) 
  { 
    for(int j = sideLength-1; j >=i; j--)
    {
      cout << " ";
    }
    for(int k = 0; k < numFillChars; ++k)
    {
      if(k > 0 && k < numFillChars-1)
      {
	if(i==sideLength)
	{
	  cout << borderChar;
	}
	else
	{
	  cout << fillChar;
	}
      }
	else
	{
	  cout << borderChar;
	}
      	
      }
    cout << endl;
  
numFillChars +=2;  
  }
}

void Triangle::Summary(){

cout << "Size of triangles side = " << sideLength << "\n";
cout << "Perimeter of triangle = " << sideLength*numSides << "\n";
cout << "Area of triangle = " << (sqrt(3)/4.0)*pow(sideLength, 2) << "\n";
cout << "Triangle looks like:\n";
Draw();
  
}






































