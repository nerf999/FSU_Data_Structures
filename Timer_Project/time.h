/* class definition for time */

#include <iostream>
using namespace std;

class Time 

{

// friend functions 

friend ostream& operator << (ostream&, const Time&);
friend istream& operator >> (istream&, Time&);
friend Time operator+(const Time&, const Time&);
friend Time operator-(const Time&, const Time&);
friend Time operator*(const Time&, int m);
friend bool operator<(const Time&, const Time&);
friend bool operator>(const Time&, const Time&);
friend bool operator<=(const Time&, const Time&); 
friend bool operator>=(const Time&, const Time&);
friend bool operator==(const Time&, const Time&);
friend bool operator!=(const Time&, const Time&);


 public: 
   
Time();   // default constructor 
Time ( int S ); // constructor for seconds 
Time (int D , int H , int M , int S ); // constructor that takes all variables 
 

// increment and decrement operators 
Time& operator++();
Time operator++(int);
Time& operator--();
Time operator--(int);



private:

int seconds; // can be any positive int
  
int minutes; // can be any positive int

int hours;  // can be any positive int
 
int days;  // can be any positive int

}; 
