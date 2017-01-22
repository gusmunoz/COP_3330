//Gustavo J. Munoz
//Assignment 3 - Distance.h
//October 3, 2014

#include <iostream>
#include "distance.h"

// Default constructur ---------------------------------------------------------------------------
Distance::Distance()
{
    miles = 0;
    yards = 0;
    feet = 0;
    inches = 0; 
}

// Conversion constructor ------------------------------------------------------------------------
Distance::Distance(int d)
{
    //any raw number thrown in such as 123456 is in 'inches' and is then simplified to mi,yd,ft,in
    miles = 0;
    yards = 0;
    feet = 0;
    inches = 0; 
    
    if (d >= 0){
	Convert(d, *this); 
    }
}

// 4-parameter constructor -----------------------------------------------------------------------
Distance::Distance(int mi, int yd, int ft, int in)
{
    if (!SetDistance(mi,yd,ft,in)){
	SetDistance(0,0,0,0);
    }
}

// Destructor ------------------------------------------------------------------------------------
Distance::~Distance()
{
  
}

// Setter ----------------------------------------------------------------------------------------
bool Distance::SetDistance(int mi, int yd, int ft, int in)
{  
    bool d = false;
    
    if (mi >= 0){
	miles = mi;
	d = true;
    }
    else {
	d = false;
    }

    if (yd >= 0 && yd < 1760){
	yards = yd;
    }
    else if (yd >= 1760){
	while( yd >= 1760 ){
	    yd = yd - 1760;
	    miles = miles + 1;
	}
	yards = yd;
	d = true;
    }
    else{
	d = false;
    }

    if (ft >= 0 && ft < 3){
	feet = ft;
    }
    else if (ft >= 3){
	while (ft >= 3) 
	{
	    ft = ft - 3;
	    yards = yards + 1;
	}
	feet = ft;
	d = true;
    }
    else{
	d = false;
    }

    if (in >= 0 && in < 12){
	inches = in;
	d = true;
    }
    else if (in >= 12){
	while (in >= 12) 
	{
	    in = in - 12;
	    feet = feet + 1;
	}
	inches = in;
	d = true;
    }
    else{
	d = false;
    }
    return d;
}

// Convert distance from inches to appropriate measurement --------------------------------------
void Convert(int d, Distance &D)
{
  while (d >= 12){
      d = d - 12;
      D.feet = D.feet + 1;
      while (D.feet >= 3){
	  D.feet = D.feet - 3;
	  D.yards = D.yards + 1;
	  if (D.yards >= 1760){
	      D.yards = D.yards - 1760;
	      D.miles = D.miles + 1;
	  }
      }
      D.inches = d;
  }
}

// Print function ------------------------------------------------------------------------------
void Distance::Show() const
{
    cout << *this << endl;
}

// Postfix increment ---------------------------------------------------------------------------
Distance Distance::operator++(int) 
{
    Distance temp = *this;
    inches = inches + 1;
    Convert(inches, *this);
    return temp;
}

// Prefix increment ----------------------------------------------------------------------------
Distance Distance::operator++()
{
    inches = inches + 1;
    Convert(inches, *this);
    return *this;
}

// Postfix decrement ---------------------------------------------------------------------------
Distance Distance::operator--(int) 
{
    Distance temp = *this;
    inches = inches - 1;
    Convert(inches, *this);
    return temp;
}

// Prefix decrement ----------------------------------------------------------------------------
Distance Distance::operator--()
{
    inches = inches - 1;
    Convert(inches, *this);
    return *this;
}

// Extraction operator -------------------------------------------------------------------------
ostream &operator<<(ostream &output, const Distance &D)
{
    output.fill('0');
    if (D.miles == 0){
	if(D.yards == 0){
	    if(D.feet == 0){
		output << "(" << D.inches << '"' << ")" << endl;
	    }
	    else{
		output << "(" << D.feet << "' " << D.inches << '"' << ")" << endl;
	    }
	}
	else{
	    output << "(" << D.yards << "y " << D.feet << "' " << D.inches << '"' << ")" << endl;
	}
    }
    else{
	output << "(" << D.miles << "m " << D.yards << "y " << D.feet << "' " << D.inches << '"' << ")" << endl;
    }
    return output;
}

// Insertion operator --------------------------------------------------------------------------
istream &operator>>(istream &input, Distance &D)
{
    int mi, yd, ft, in;
    char C;
    
    input >> mi >> C;
    input >> yd >> C;
    input >> ft >> C;
    input >> in;
    D.SetDistance(mi,yd,ft,in);
    return input;
}

// Addition operator ---------------------------------------------------------------------------
Distance operator+(const Distance& D1, const Distance& D2)
{
    Distance ans;
    
    ans.miles = D1.miles + D2.miles;
    ans.yards = D1.yards + D2.yards;
    ans.feet = D1.feet + D2.feet;
    ans.inches = D1.inches + D2.inches;
    while (ans.feet >= 3){
	ans.feet = ans.feet - 3;
	ans.yards = ans.yards + 1;
	while (ans.yards > 1760){
	    ans.yards = ans.yards - 1760;
	    ans.miles = ans.miles + 1;
	}
    }
    Convert(ans.inches, ans);
    return ans;
}

// Subtraction operator -------------------------------------------------------------------------
Distance operator-(const Distance& D1, const Distance& D2)
{
    Distance ans;
    
    ans.miles = D1.miles - D2.miles;
    ans.yards = D1.yards - D2.yards;
    ans.feet = D1.feet - D2.feet;
    ans.inches = D1.inches - D2.inches;
    if (ans < 0){
	ans = 0; 
    }
    while (ans.feet >= 3){
	ans.feet = ans.feet - 3;
	ans.yards = ans.yards + 1;
	while (ans.yards > 1760){
	    ans.yards = ans.yards - 1760;
	    ans.miles = ans.miles + 1;
	}
    }
    Convert(ans.inches, ans);
    return ans;
}

// Multiplication operator ---------------------------------------------------------------------------
Distance operator*(const Distance& D, int a)
{
    // multiplication with an integer only
    Distance ans;
    
    ans.miles = D.miles*a;
    ans.yards = D.yards*a;
    ans.feet = D.feet*a;
    ans.inches = D.inches*a;
    while (ans.feet >= 3){
	ans.feet = ans.feet - 3;
	ans.yards = ans.yards + 1;
	while (ans.yards > 1760){
	    ans.yards = ans.yards - 1760;
	    ans.miles = ans.miles + 1;
	}
    }
    Convert(ans.inches, ans);
    return ans;
}

// Equality operator ----------------------------------------------------------------------------------
bool operator==(const Distance& D1, const Distance& D2)
{
    return (D1.miles == D2.miles && D1.yards == D2.yards && D1.feet == D2.feet && D1.inches == D2.inches);
}

// Inequality operator ----------------------------------------------------------------------------------
bool operator!=(const Distance& D1, const Distance& D2)
{
    return !(D1 == D2);
}
// > operator -------------------------------------
 bool operator>(const Distance& D1, const Distance& D2)
{
    return (D2 < D1);
}
// < operator -------------------------------------
bool operator<(const Distance& D1, const Distance& D2)
{
    if (D1.miles < D2.miles) {
	return true;
    } 
    else if (D1.miles == D2.miles) {
	if (D1.yards < D2.yards) {
	    return true;
	}
	else if (D1.yards == D2.yards) {
	    if (D1.feet < D2.feet){
		return true;
	    }
	    else if (D1.feet == D2.feet){
		if (D1.inches < D2.inches){
		    return true;
		}
	    }
	}
    }
    return false;
}

// >= operator -------------------------------------
 bool operator<=(const Distance& D1, const Distance& D2)
{
    return (D1 < D2 || D1 == D2);
}
// <= operator -------------------------------------
bool operator>=(const Distance& D1, const Distance& D2)
{
    return (D1 > D2 || D1 == D2);
}



