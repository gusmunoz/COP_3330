//Gustavo J. Munoz
//Assignment 5 - myint.cpp
//November 6, 2014

#include "myint.h"
#include <iostream>
#include <math.h>
#include <cstring>
#include <stdlib.h>


using namespace std;

void reverseString (char *s) {
    char t, *d = &(s[strlen (s) - 1]);
    while (d > s) {
        t = *s;
        *s++ = *d;
        *d-- = t;
    }
}

int C2I(char c)
// converts character into integer (returns -1 for error)
{
    if (c < '0' || c > '9'){	
	return -1;				// error
    }
    return (c - '0');				// success
}


char I2C(int x)
// converts single digit integer into character (returns '\0' for error)
{
    if (x < 0 || x > 9){		
	return '\0';				// error
    }
    return (static_cast<char>(x) + '0'); 	// success
}

// newArray() -----------------------------------------------------------------------------------------
// Container space allocator
char* MyInt::newArray(int space)
{
  char* oldArray = 0;
  oldArray = new (nothrow) char[space];
  if (oldArray == 0)
  {
    cout << "Failed!\n";
  }
  else
  {
    cout << "Succeeded!\n"; 
  }
    return oldArray;
}

// first constructor ----------------------------------------------------------------------------------
// pass in int n and create object with it if >= 0
MyInt::MyInt(int n){
    if(n > 0){
	int len = 0;
	size = len;
	int x = n;
	
	while (n > 0) {
		n = n / 10;
		len++;
	}
	size = len;
      
	capacity = (len + 5);
	array = newArray(capacity);
	
	//5230/10^3
	int m = 0;
	for(int i = len - 1; i >= 0; i--){
	    int y = pow(10, i); // y =10^3
	    int z = x/y;	//5620/100 = 56
	    while(z > 10) {
	     z = z % 10;
	    }
	    
	    char newInt = I2C(z); 
	    array[i] = newInt;		// array = ['5', '6', '2', '0']
	}

    }
    else{
	size = 1;
	capacity = 6;
	array = newArray(capacity);
	array[0] = '0';	
    }

}

// second constructor ---------------------------------------------------------------------------------
MyInt::MyInt(char* str){
    int length = strlen(str);
    bool badChars = false;
    for(int i=0; i < length; i++){
	if(str[i] < '0' || str[i] > '9'){
	  badChars = true;
	}else{
	  
	}
    }
    if (!badChars){
	size = length;
	capacity = length + 5;
	array = newArray(capacity);
	reverseString(str);
	strcpy(array, str);
	 
    }else{
	size = 1;
	capacity = size +5;
	array = newArray(capacity);
	array[0] = '0';
    }
}

// copy constructor -----------------------------------------------------------------------------------
MyInt::MyInt(const MyInt& s){   
    size = s.size;
    array = new char[size + 1];
    strcpy(array,s.array);
}

// destructor -----------------------------------------------------------------------------------------
MyInt::~MyInt(){   
    if (array != 0){ 
	delete [] array;
    }
}

// assignment operator = ------------------------------------------------------------------------------
MyInt& MyInt::operator=(const MyInt& s){   
    if (this != &s)
    {
	delete [] array;

      size = s.size;
      array = new char[size + 1];
      strcpy(array,s.array);
    }

    return *this;
}

// prefix ++ ------------------------------------------------------------------------------------------
MyInt MyInt::operator++(){   

}

// postfix ++ -----------------------------------------------------------------------------------------
MyInt MyInt::operator++(int){   

}

// addition operator + --------------------------------------------------------------------------------
MyInt operator+(const MyInt& x, const MyInt& y){
    MyInt s;
    s.array = s.newArray(s.capacity);			//array which holds sum of 2 arrays 
    int sumCounter = 0;					//counter for summation array
    int remainder = 0;					//initialize remainder after mod 
    int singleInt = 0;					//initialize 0-9 digits (singleInt = 14-14mod10 = 9) **fix
    
    for(int i = s.size - 1; i >= 0; i--){		//iterate from end to begin of array
	int tempX = C2I(x.array[i]);			//convert char to int in order to add
	int tempY = C2I(y.array[i]);			
	int sumTotal = tempX + tempY;			//virgin sum of ith element
	cout << "sumTotal: " << sumTotal <<'\n';
	
	//if the summation is larger than 1 digit
	if(sumTotal > 9){
	    char fullValue = sumTotal + remainder;	//store full value
	    int remainder = sumTotal % 10;		//store remainder
	    singleInt = fullValue - remainder;		
	    s.array[i] = singleInt;		//add single int to array representing sum
	    sumCounter++;				//next element in array representing sum
	}
	//if the summation is 1 digit
	else{
	    s.array[sumCounter] = sumTotal;		//add digit to array
	    sumCounter++;
	}
	s.size = sumCounter;
    }
    cout << "sumTotal: " << endl;

    return s;
}
	


// multiplication overload * --------------------------------------------------------------------------
MyInt operator*(const MyInt& x, const MyInt& y){   

}

// less than operator < -------------------------------------------------------------------------------
bool operator<(const MyInt& x, const MyInt& y){   
    
}

// greater than operator > ----------------------------------------------------------------------------
bool operator>(const MyInt& x, const MyInt& y){   
    return (y < x);
}

// less than or equal to operator <= ------------------------------------------------------------------
bool operator<=(const MyInt& x, const MyInt& y){   
    return (x < y || x == y);
}

// greater than or equal to operator >= ---------------------------------------------------------------
bool operator>=(const MyInt& x, const MyInt& y){   
    return (x > y || x == y);
}

// equality operator == -------------------------------------------------------------------------------
bool operator==(const MyInt& x, const MyInt& y){   
    if (x.size != y.size)
	return 0;
    for (int i = 0; i < x.size; ++i)
	if (x[i] != y[i])
	  return 0;
    return 1;
}

// not equals than operator != ------------------------------------------------------------------------
bool operator!=(const MyInt& x, const MyInt& y){   
    return !(x == y);
}

// extraction operator << -----------------------------------------------------------------------------
ostream &operator << (ostream &output, const MyInt &m){   
    for(int i = m.size - 1; i >= 0; i--){
	output << m.array[i];
    }
    return output;
}

// insertion operator >> ------------------------------------------------------------------------------
istream &operator >> (istream &input, MyInt &m){   
 char c;
 bool startedReading = false;
 int arraySize = 0;
 char* oldArray;		//increases in size by 1
				//each time digit read in
 
 while (true) {
    c = input.get();
    
    //skip over leading whitespace
    if (c == ' '){
      if (startedReading) {
	  break;
      }
      else {
	  continue;
      }
    }
    
    if (c >= '0' || c <= '9') {
	startedReading = true;
	arraySize++;
	
	//copy the current digit read in from input
	//stream 
	
	//create new array that holds one more element
	//and copy previously read digits into it
	char* emptyArray = m.newArray(arraySize); //2
	if (arraySize > 1) {
	  strcpy(emptyArray, oldArray);
	}

	oldArray = emptyArray; //1
	oldArray[arraySize -1 ] = c;
    }
    
    char nextChar  = input.peek();
    if (nextChar < '0' || nextChar > '9' || nextChar == '\n'){
      break;
    }
 }
 
 //oldArray at this point contains "12345"
 
 if (arraySize > 0){
    m.capacity = arraySize + 5;
    m.array = m.newArray(m.capacity);
    m.size = arraySize;
    strcpy(m.array, oldArray);
 }
  
  return input;
}

// operator[] - accessor ---------------------------------------------------------------------
char& MyInt::operator[](int index){
	if(index >= capacity){
		cout << "Accessing out of bounds" << endl;
		exit(EXIT_FAILURE);
	}else{
		return array[index];
	}
}
































