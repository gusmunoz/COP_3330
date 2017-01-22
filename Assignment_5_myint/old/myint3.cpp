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
        //cout << "Succeeded!\n";
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
MyInt::MyInt(const char str[]){
    int length = strlen(str);
    char localstr[length];
    strcpy(localstr,str);
    bool badChars = false;
    for(int i=0; i < length; i++){
        if(localstr[i] < '0' || localstr[i] > '9'){
            badChars = true;
        }else{

        }
    }

    if (!badChars){
        size = length;
        capacity = length + 5;
        array = newArray(capacity);
        reverseString(localstr);
        strcpy(array, localstr);

    }else{
        size = 1;
        capacity = size +5;
        array = newArray(capacity);
        array[0] = '0';
    }
}

// third constructor -----------------------------------------------------------
MyInt::MyInt(int size, char fill){
    this->size=size;
    capacity =size+5;
    array = newArray(capacity);
    for(int i=0;i<capacity;i++)
        array[i] = fill;
}


// copy constructor -----------------------------------------------------------------------------------
MyInt::MyInt(const MyInt& s){   
    size = s.size;
    capacity = s.capacity;
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
	capacity = s.capacity;
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
    MyInt s((x.capacity<y.capacity)?y:x); //array which is the size of larger of both arrays
//     // x = 15
//     // y = 12345 (greater)
//     int xSize = x.size;
//     int ySize = y.size;
//     cout<< "size of array x: " << xSize << endl;
//     cout<< "size of array y: " << ySize << endl;
//     
//     if(xSize > ySize){
// 	//add zeroes to y
// 	y.size = x.size;
// 	for(int i = 0; i<x.size; i++){
// 	    if(x.array[i] != '0'){
// 	      
// 	    }
// 		
// 	}
//       
//     }
//     else if (xSize < ySize){
// 	//add zeroes to x
//       
//     }
//     
//     int largerSize = max(xSize, ySize);
//     
//     
    int remainder = 0, columnTotal = 0;
    int i;
    for(i = 0; i < s.size; i++){		//iterate from end to begin of array
       // cout << "sumTotal: " << columnTotal <<'\n';

        //if the summation is larger than 1 digit
	columnTotal = remainder + C2I(x.array[i])+C2I(y.array[i]);
        if(columnTotal > 9){
            remainder = columnTotal / 10;		//store remainder
            columnTotal = columnTotal % 10;
        }
        else {
	    remainder = 0; 
	}
	char convertChar =  I2C(columnTotal);
        s.array[i] = convertChar;

    }
    if(remainder > 0){
        s.size++;
        s.array[i] = I2C(remainder);
    }
    //cout << "sumTotal: " << endl;

    return s;
}

MyInt lshift(MyInt a, int k) { // returns a shifted left by k digits
    MyInt c(a.capacity+k,'0');
    int i;
    for (i = 0; i<a.size ; i++) {
        c[i+k] = a[i];
    }
    return c;
}

// multiplication overload * --------------------------------------------------------------------------
MyInt multiplyOneByMany(const MyInt& x, const char y){
    MyInt s(x.capacity+1,'0');

    int remainder = 0, columnTotal = 0;
    int i;
    for(i = 0; i<x.size; i++){		//iterate from end to begin of array
        //cout << "sumTotal: " << columnTotal <<'\n';

        //if the summation is larger than 1 digit
        if((columnTotal = remainder + C2I(x.array[i])*C2I(y)) > 9){
            remainder = columnTotal / 10;		//store remainder
            columnTotal = columnTotal % 10;
        }
        else {
	    remainder =0; 
	}
        char convertChar = I2C(columnTotal);
        s.array[i] = convertChar;

    }
    
   
    
    if(remainder>0){
	s.size++;
        s.array[i] = I2C(remainder);
    }
    //cout << "sumTotal: " << endl;

    return s;

}

MyInt operator*(const MyInt& x, const MyInt& y){
    MyInt c((x.capacity<y.capacity)?2*y.capacity:2*x.capacity,'0'); //initialized to all zeroes
    int i;
    for (i=0; i < y.size; i++) {
        if (C2I(y.array[i]) != 0) { //if it is zero, nothing to do
            c = c + lshift(multiplyOneByMany(x,y.array[i]), i);
        }
    }
    return c;
}

// less than operator < -------------------------------------------------------------------------------
bool operator<(const MyInt& x, const MyInt& y){   

}

// greater than operator > ----------------------------------------------------------------------------
bool operator>(const MyInt& x, const MyInt& y){   
//     return (y < x);
}

// less than or equal to operator <= ------------------------------------------------------------------
bool operator<=(const MyInt& x, const MyInt& y){   
//     return (x < y || x == y);
}

// greater than or equal to operator >= ---------------------------------------------------------------
bool operator>=(const MyInt& x, const MyInt& y){   
//     return (x > y || x == y);
}

// equality operator == -------------------------------------------------------------------------------
bool operator==(const MyInt& x, const MyInt& y){   
    if (x.size != y.size)
	return 0;
    for (int i = 0; i < x.size; ++i)
	if (x.array[i] != y.array[i])
	  return 0;
    return 1;
}

// not equal operator != ------------------------------------------------------------------------------
bool operator!=(const MyInt& x, const MyInt& y){   
    return !(x == y);

}

// extraction operator << -----------------------------------------------------------------------------
ostream &operator << (ostream &output, const MyInt &m){   
    for(int i=m.size-1;i>=0; --i){
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
	if (nextChar == '\n') {
	  input.get();  		//consume newline
	  break;
	}
        if (nextChar < '0' || nextChar > '9'){
            break;
        }
    }

    //oldArray at this point contains "12345"

    if (arraySize > 0){
        m.capacity = arraySize + 5;
        m.array = m.newArray(m.capacity);
        m.size = arraySize;
        reverseString(oldArray);
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
































