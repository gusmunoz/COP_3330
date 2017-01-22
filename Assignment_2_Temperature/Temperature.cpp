//Gustavo J. Munoz
//Assignment 2 - Temperature.cpp
//September 25, 2014

#include "Temperature.h"
#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

//Default constructor-----------------------------------------------------
Temperature::Temperature()
{    
    temp = 0;
    tempCelsius = 0;
    tempKelvin = 273;
    tempFarenheit = 32;
    scale = 'C';
    Format = 'D';  
}

//2-parameter constructor ------------------------------------------------
Temperature::Temperature(double deg, char s)
{    
    Format = 'D';

    if (!Set(deg, s)) {
	cout << "This is an invalid temperature." << endl;
	temp = 0;
	tempCelsius = 0;
	tempKelvin = 273;
	tempFarenheit = 32;
	scale = 'C';
	Format = 'D';
    }
  
}
// Copy Constructor ------------------------------------------------------
Temperature::Temperature(const Temperature& d)
{    
    temp = d.GetDegrees();
    tempCelsius = d.GetTempCelsius();
    tempKelvin = d.GetTempKelvin();
    tempFarenheit = d.GetTempFarenheit();
    scale = d.GetScale();
    Format = d.GetFormat();
}

// Function checks that input temperatures -------------------------------
// and scales are valid temps and scales ---------------------------------
bool Temperature::valid(double tempValue, char scaleValue)
{
    bool isValid = true;
    if (scaleValue == 'k' || scaleValue == 'K') {
	if (tempValue < 0){
	    isValid = false;
	}
    }
    else if (scaleValue == 'c' || scaleValue == 'C') {
	if (tempValue < -273.15){
	    isValid = false;
	}
    }
    else if (scaleValue == 'f' || scaleValue == 'F') {
	if (tempValue < -459.67){
	    isValid = false;
	}  
    }
    else{
	isValid = false;  
    }
    return isValid;
  
}

// Input function---------------------------------------------------------
void Temperature::Input()
{
 
    char scaleValue = 'k';
    double tempValue = -1;

    cout << "Enter a temperature: ";
    cin >> tempValue >> scaleValue;
    
    while (!valid(tempValue, scaleValue)) {
	cout << "Invalid Temperature: Enter again: ";
	cin >> tempValue >> scaleValue;
    }
    scale = scaleValue;
    temp = tempValue;
    
    //cout << temp << ' ' << scale << endl;
  
}

// Output temperature to screen -----------------------------------------
void Temperature::Show() const
{
    int oldprecision = cout.precision();
  
    if (Format == 'D'){
	cout << temp << ' ' << scale << endl;
    }
    else if (Format == 'P'){
	cout << temp << setprecision(1) << ' ' << scale << endl;
    }
    else if (Format == 'L'){
	string word = "";
	if (scale == 'k' || scale == 'K'){
	    word = "Kelvin";
	}
	if (scale == 'c' || scale == 'C'){
	    word = "Celsius";
	}
	if (scale == 'f' || scale == 'F'){
	    word = "Faranheit";
	}
	cout << temp << ' ' << word << endl;     
    }
    else{
	cout << "Invalid format."; 
    }
    cout.precision(oldprecision);
  
}

// Set temperature to specified valid values ----------------------------
bool Temperature::Set(double deg, char s)
{
    scale = s;
    if (valid(deg, s)){
	switch (s) {
	    //celcius user input
	    case 'c':
	    case 'C':
		temp = deg;
		tempCelsius = deg;
		tempKelvin = deg+273.0;
		tempFarenheit =  1.8*(deg) + 32.0;
		break;
	    //kelvin user input
	    case 'k':
	    case 'K':
		temp = deg;
		tempCelsius = deg-273;
		tempKelvin = deg;
		tempFarenheit =  1.8*(deg - 273.0) + 32.0;
		break;
	    //farenheit
	    case 'f':
	    case 'F':
		temp = deg;
		tempCelsius = .55*(deg - 32.0);
		tempKelvin = .55*(deg - 32.0) + 273.0;
		tempFarenheit = deg;
	}
	return true;
    }
    return false;
}

// Accessor for temperature ---------------------------------------------
double Temperature::GetDegrees() const
{
    return temp;
}
// Accessor for scale ----------------------------------------------------
char Temperature::GetScale() const
{
    return scale;
}
// Accessor for Format ----------------------------------------------------

char Temperature::GetFormat() const
{
    return Format;
}

// Accessor for Celcius ----------------------------------------------------

double Temperature::GetTempCelsius() const
{
    return tempCelsius;
}

// Accessor for Kelvin ----------------------------------------------------

double Temperature::GetTempKelvin() const
{
    return tempKelvin;
}

// Accessor for Farenheit ----------------------------------------------------

double Temperature::GetTempFarenheit() const
{
    return tempFarenheit;
}

// Change format of scale ------------------------------------------------
bool Temperature::SetFormat(char f)
{
    bool isValid = false;
    if (f == 'D'){
	Format = 'D';
	isValid = true;
    }
    else if (f == 'P'){
	Format = 'P';
	isValid = true;
    }
    else if (f == 'L'){
	Format = 'L';
	isValid = true;
    }
    else{
	isValid = false;
    }
    return isValid;
}

// Convert current temperature to scale given in parameter----------------
bool Temperature::Convert(char sc)
{
    scale = sc;
    switch (sc){
	case 'c':
	case 'C':
	    temp = tempCelsius;
	    return true;
	case 'k':
	case 'K':
	    temp = tempKelvin;
	    return true;
	//farenheit
	case 'f':
	case 'F':
	    temp = tempFarenheit;
	    return true;
    }
    return false;
}
  
// Compare two temperature objects (calling object & parameter) -------------
int Temperature::Compare(const Temperature& d) 
{
    Temperature _temp(d.GetDegrees(), d.GetScale());

    //needed to check if calling object is lower temperature 
    _temp.Convert(scale);
    bool same = (temp == _temp.GetDegrees() && scale == _temp.GetScale());  
    if (same) {
	return 0;   
      
    }
    else if (temp < _temp.GetDegrees()) {
	return -1;
    }
    else if (temp > _temp.GetDegrees()) {
	return 1;
    }
}
