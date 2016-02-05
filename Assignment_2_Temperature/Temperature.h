//Gustavo J. Munoz
//Assignment 2 - Temperature.h
//September 25, 2014

#include <iostream>

using namespace std;

class Temperature
{

//Declaration of functions
        public:            
		Temperature();				//default constructor
		Temperature(double deg, char s);	//2-parameter constructor
		Temperature(const Temperature& d);	//copy constructor
		
		 
		void Input();
		void Show() const;
		
		// Settors
		bool Set(double deg, char s);
		bool SetFormat(char f);
		
		bool Convert(char sc);
		int Compare(const Temperature& d);
		
		// Gettors
		double GetDegrees() const;
		char GetScale() const;
		char GetFormat() const;
		double GetTempCelsius() const;
		double GetTempKelvin() const;
		double GetTempFarenheit() const;

		void Increment(int deg, char sc);
		
		  
	private:
		double temp;
		char scale;
		bool valid(double tempValue, char scaleValue);
		char Format;
		double tempCelsius;
		double tempKelvin;
		double tempFarenheit;
};






























