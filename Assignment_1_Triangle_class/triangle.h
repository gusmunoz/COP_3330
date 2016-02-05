//Gustavo J. Munoz
//Assignment 1 - Triangle Class
//September 12, 2014
//triangle.h

#include <iostream>


using namespace std;

//Class "Triangle"
class Triangle
{

//Declaration of functions
        public:            
		Triangle(int size, char border='#', char fill='*');		//constructor
				
		// accessors
		int GetSize();
		
		
		int Perimeter();
		double Area();
		
		void Grow();
		void Shrink();
		
		void SetBorder(char border);
		void SetFill(char fill);
		
		void Draw();
		
		void Summary();
		
                
	private:
		int sideLength;
		char borderChar;
		char fillChar;
};































