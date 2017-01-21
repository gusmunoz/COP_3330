// Sample main program to test a few Distance class features
//  Write your own calls to test more thoroughly!!
// Author:  Bob Myers

#include <iostream>
#include "distance.h"

using namespace std;

int main()
{
   cout << "\nTesting constructor(s) with different no. of arguments" << endl;
   Distance d1, d2, d3(123456), d4(987654321), d5(5,400,2,4);
   cout << "d1 = " << d1 << '\n';
   cout << "d2 = " << d2 << '\n';
   cout << "d3 = " << d3 << '\n';
   cout << "d4 = " << d4 << '\n';
   cout << "d5 = " << d5 << '\n';

   int a = 12; //mi
   int b = 12; //yd
   int c = 12; //ft
   int d = 12; //in
   Distance d10(a,b,c,d);
   cout << "Distance object: \n" << a << "mi, " << b << "yd, " << c << "ft, " 
      << d << "in " << "is simplified to:\n" << d10 << endl;

   cout << "___________________________________________________________________" << endl;    
   cout << "DISTANCE CALCULATOR: " << endl;
   cout << "___________________________________________________________________" << endl;    
   cout << "Entry format: "  << "To enter (1 mi, 3 yd, 10 ft, 11in), type: 1,3,10,11" << endl;
   cout << "\n\n"; 

   cout << "    Enter first Distance object (MILES,YDS,FT,IN):  ";
   cin >> d1;

   cout << "    Enter second Distance object (MILES,YDS,FT,IN):  ";
   cin >> d2;

    cout << "\n\n"; 
    cout << "Results: " << endl;
    cout << "\n"; 
    cout << "Addition, subtraction, multiplication of 1st and 2nd distances: " << endl;
    cout << d1 << " + " << d2 << " = " << d1 + d2 << '\n';
    cout << d1 << " - " << d2 << " = " << d1 - d2 << "\n";
    cout << d1 << " * " << "2" << " = " << d1 * 2 << '\n';
    
    cout << "Comparison Operators: " << endl;

    if (d1 < d2) 	cout << d1 << " <  " << d2 << " is TRUE\n";
    if (d1 > d2) 	cout << d1 << " >  " << d2 << " is TRUE\n";
    if (d1 <= d2) 	cout << d1 << " <= " << d2 << " is TRUE\n";
    if (d1 >= d2) 	cout << d1 << " >= " << d2 << " is TRUE\n";
    if (d1 == d2) 	cout << d1 << " == " << d2 << " is TRUE\n";
    if (d1 != d2) 	cout << d1 << " != " << d2 << " is TRUE\n\n";

    
    cout << "Adding integers to distances(integers are read as 'IN' and simplified to (MI,YD,FT,IN): " 
    << endl;
    cout << d1 << " + 654321 = " << d1 + 654321 << '\n';
    cout << d2 << " + 15263748 = " << d2 + 15263748 << '\n';
}

