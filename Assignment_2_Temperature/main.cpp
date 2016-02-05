/////////////////////////////////////////////////////////
// Bob Myers
//
// sample.cpp -- sample test program starter for Temperature class
/////////////////////////////////////////////////////////

#include <iostream>
#include "Temperature.h"

using namespace std;

int main()
{
    Temperature t1;		// should default to 0 Celsius
    Temperature t2(34.500, 'F');  // should init to 34.5 Fahrenheit 
    Temperature t3(-1, 'Z');  // should init to 0 Celcius 
    cout << "\nTemperature t3 is: ";
    t3.Show();	
    
    
    
    // display dates to the screen
    cout << "\nTemperature t1 is: ";
    t1.Show();			
    cout << "\nTemperature t2 is: ";
    t2.Show();

    t1.Input();			// Allow user to enter a temperature for t1
    cout << "\nTemperature t1 is: ";
    t1.Show();			
    
    t2.SetFormat('L');		// change format of t1 to "Long" format
    cout << "\nTemperature t2 is: ";
    t2.Show();			

    // and so on.  Add your own tests to fully test the class' 
    //   functionality.
}
