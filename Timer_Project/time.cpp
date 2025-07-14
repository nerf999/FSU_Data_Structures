#include <iostream>
#include "time.h"

using namespace std;

// default constructor 
// intializes all ints to 0 
Time::Time()
{

 seconds = 0; // 

 minutes = 0;

 hours = 0;

 days = 0;

}

// constructor for seconds 
// error checks for out of range values 
Time::Time(int S)
{
days = 0;
hours = 0;
minutes = 0;

if (S < 0 )  // error checks for negative int 
 seconds = 0; // sets seconds to 0 if S is negative

else
 seconds = S;  


         // if any variable is above the allowed limit 
         // it will be converted to the next kind of time variable 
         // example (121 minutes will be conveted to 2 houts 1 minute)
   if (seconds >= 60)
       (minutes = (minutes  + (seconds / 60))) , (seconds = seconds % 60);


   if (minutes >= 60 )
       (hours = (hours  + (minutes / 60))) , (minutes = minutes % 60);


   if ( hours >= 24)
       (days = (days +(hours/24))) , ( hours = hours % 24); 
}

    // constructor for all variable 
    // time variables out of bounds will be convertedd to next highest variable 
    // example (121 minutes will be converted to 2 hours and 1 minute)
Time::Time(int D, int H, int M, int S)
{

   // error checks for negative ints
 if ( S < 0 ||  M < 0 ||  H < 0 || D < 0)
    days = 0, hours = 0, minutes = 0, seconds = 0;

 else 
   days = D, hours = H, minutes = M, seconds = S;


     // converts out of data variable to next highest variable 
   if (seconds >= 60)
       (minutes = (minutes  + (seconds / 60))) , (seconds = seconds % 60);


   if (minutes >= 60 )
       (hours = (hours  + (minutes / 60))) , (minutes = minutes % 60);


   if ( hours >= 24)
       (days = (days +(hours/24))) , ( hours = hours % 24);

}


  // ostream operator 
 // allows cout statements for Time objects 
 ostream& operator<<(ostream& s, const Time& t)
{

s << t.days << "~" << t.hours << ":" << t.minutes << ":" << t.seconds;

return s;

}


  // istream operator
  // allows for cin statements of Time objects 
istream& operator >> (istream& is, Time& T)
{
   char symbol, colon1, colon2;


   is >> T.days >> symbol >> T.hours >> colon1 >> T.minutes >> colon2 >> T.seconds;


          // error checks for for negative ints 
          // sets all variables to 0 if any passed values are negative 
   if ( T.days < 0 ||  T.hours < 0|| T.minutes < 0 ||  T.seconds < 0)
       (T.days = 0 , T.hours = 0, T.minutes = 0, T.seconds < 0);


        // converts out of range variables to next highest variable
        // example ( 121 minutes will be converted to 2 hours and 1 mintute)
   if (T.seconds >= 60)
       (T.minutes = (T.minutes  + (T.seconds / 60))) , (T.seconds = T.seconds % 60);


   if (T.minutes >= 60 )
       (T.hours = (T.hours  + (T.minutes / 60))) , (T.minutes = T.minutes % 60);
    

   if ( T.hours >= 24)
       (T.days = (T.days +(T.hours/24))) , ( T.hours = T.hours % 24);

return is;
}


     // operator for addition of Timie objects 
Time operator+(const Time& t1, const Time& t2)
{
  Time L; // creates Time object for addition 

  L.seconds = t1.seconds + t2.seconds;

  L.minutes = t1.minutes + t2.minutes;

  L.hours = t1.hours + t2.hours; 

  L.days = t1.days + t2.days; 



           // converts out of range variables to next highest variable 
        // example ( 121 minutes will be converted to 2 hours and 1 mintute)
   if (L.seconds >= 60)
       (L.minutes = (L.minutes  + (L.seconds / 60))) , (L.seconds = L.seconds % 60);


   if (L.minutes >= 60 )
       (L.hours = (L.hours  + (L.minutes / 60))) , (L.minutes = L.minutes % 60);


   if ( L.hours >= 24)
       (L.days = (L.days +(L.hours/24))) , ( L.hours = L.hours % 24);

// returns L object
return L;
}


  // operator for subtracting 
Time operator-(const Time& t1, const Time& t2)
{

  Time F; // creates Time object to hold t1 variable 
  Time S; // creates Time object to hold t2 variable 
  Time L; // creates time object to hold final variable 

// sets F values to t1 values and converting them all to seconds 
  F.days = t1.days;  

  F.hours = t1.hours + (F.days * 24); 

  F.minutes = t1.minutes + (F.hours * 60);

  F.seconds = t1.seconds + (F.minutes * 60);

// sets S values to t2 values and converts them all to seconds 
  S.days = t2.days;

  S.hours = t2.hours + (S.days * 24);

  S.minutes = t2.minutes + (S.hours * 60);

  S.seconds = t2.seconds + (S.minutes * 60);


// if S.seconds is greater than F.seconds sets all L values to 0 
  if (S.seconds >  F.seconds)
    (L.seconds = 0, L.minutes = 0, L.hours = 0, L.days = 0);


// if values are valid subtracts S.second from F.seconds 
else L.seconds = (F.seconds - S.seconds);


   if (L.seconds >= 60)
       (L.minutes = (L.minutes  + (L.seconds / 60))) , (L.seconds = L.seconds % 60);


   if (L.minutes >= 60 )
       (L.hours = (L.hours  + (L.minutes / 60))) , (L.minutes = L.minutes % 60);


   if ( L.hours >= 24)
       (L.days = (L.days +(L.hours/24))) , ( L.hours = L.hours % 24);

return L;
}


// operator for multiplicatoiin of Time objects
Time operator*(const Time& t1 , int m)
{

 Time r; // creates r for multiplication 


  // sets t1 values to r values and converts them all to seconds 
 r.hours = t1.hours + (t1.days * 24);

r.minutes = t1.minutes + (r.hours * 60);

r.seconds = t1.seconds + (r.minutes * 60);
 
// multiplies r seconds by int m 
r.seconds = (r.seconds * m);


          // converts out of range variables to next highest variable 
        // example ( 121 minutes will be converted to 2 hours and 1 mintute)
if (r.seconds >= 60)
       (r.minutes = (r.minutes  + (r.seconds / 60))) , (r.seconds = r.seconds % 60);


   if (r.minutes >= 60 )
       (r.hours = (r.hours  + (r.minutes / 60))) , (r.minutes = r.minutes % 60);


   if ( r.hours >= 24)
       (r.days = (r.days +(r.hours/24))) , ( r.hours = r.hours % 24);


return r;
}


 // operator for comparing time object values 
 // returns false or true based on values 
 bool operator<(const Time& t1 , const Time& t2)
{

Time F; // creates F objects to hold t1 values
Time S; // creates S objects to hold t2 variables 
bool TruthStatus; // bool statement to be returned 

 // sets F values as t1 values and converts them to seconds 
  F.hours = t1.hours + (t1.days * 24);

  F.minutes = t1.minutes + (F.hours * 60);

  F.seconds = t1.seconds + (F.minutes * 60);

  // sets S values to t2 values and converts them to seconds 
  S.hours = t2.hours + (t2.days * 24);

  S.minutes = t2.minutes + (S.hours * 60);

  S.seconds = t2.seconds + (S.minutes * 60);
  
   // if F is less than S truth status is true 
  if (F.seconds < S.seconds)
      TruthStatus = true;

  else  // if above statement is false sets TruthStatus to flase
    TruthStatus = false; 


return TruthStatus;
}

 // operator for comparing time object values
 // returns false or true based on values
bool operator>(const Time& t1 , const Time& t2)
{

Time F; // creates F object to hold t1 values 
Time S; // creates S object to hold t2 values 
bool TruthStatus; // bool statment returned 

// sets F values to t1 values and converts it to seconds 
F.hours = t1.hours + (t1.days * 24);

F.minutes = t1.minutes + (F.hours * 60);

F.seconds = t1.seconds + (F.minutes * 60);

// converts S values to t2 values and converts them all to seconds 
S.hours = t2.hours + (t2.days * 24);

S.minutes = t2.minutes + (S.hours * 60);

S.seconds = t2.seconds + (S.minutes * 60);

   // checks if F seconds is larger than S seconds
  if (F.seconds > S.seconds)
      TruthStatus = true;

  else
    TruthStatus = false;


return TruthStatus;
}


 // operator for comparing time object values
 // returns false or true based on values 
bool operator<=(const Time& t1 , const Time& t2)
{

Time F; // creates F time object to hold t1 values
Time S; // creats S time object to hold t2 values 
bool TruthStatus; // bool variable returned 

// sets F values to t1 values and converts them to seconds 
F.hours = t1.hours + (t1.days * 24);

F.minutes = t1.minutes + (F.hours * 60);

F.seconds = t1.seconds + (F.minutes * 60);


// sets S values to t2 values and converts them to seconds 
S.hours = t2.hours + (t2.days * 24);

S.minutes = t2.minutes + (S.hours * 60);

S.seconds = t2.seconds + (S.minutes * 60);

  // checks if F seconds is less then or equal to S seconds
  if (F.seconds <= S.seconds)
      TruthStatus = true;

  else
    TruthStatus = false;


return TruthStatus;
}

 // operator for comparing time object values
 // returns false or true based on values 
bool operator>=(const Time& t1 , const Time& t2)
{

Time F; // creates F object to hold t1 values
Time S; // creates s object to hold t2 values 
bool TruthStatus;

// sets F values to t1 values and converts them to seconds 
F.hours = t1.hours + (t1.days * 24);

F.minutes = t1.minutes + (F.hours * 60);

F.seconds = t1.seconds + (F.minutes * 60);

 // sets S values to t2 values and converts them to seconds 
S.hours = t2.hours + (t2.days * 24);

S.minutes = t2.minutes + (S.hours * 60);

S.seconds = t2.seconds + (S.minutes * 60);

  // checks if F seconds  is greater than or equal to S seconds
  if (F.seconds >= S.seconds)
      TruthStatus = true;

  else
    TruthStatus = false;


return TruthStatus;
}


 // operator to check for equality of two time objects
 // returns true on success and false on failiure 
bool operator==(const Time& t1 , const Time& t2)
{

Time F; // creates F object to hold t1 values
Time S; // creates S object to hold t2 values
bool TruthStatus; // bool variable returned 
 
// sets F values to t1 objects and converts them to seconds 
F.hours = t1.hours + (t1.days * 24);

F.minutes = t1.minutes + (F.hours * 60);

F.seconds = t1.seconds + (F.minutes * 60);

// sets S values to t2 values and converts them to seconds 
S.hours = t2.hours + (t2.days * 24);

S.minutes = t2.minutes + (S.hours * 60);

S.seconds = t2.seconds + (S.minutes * 60);

  // checks if F seconds and S seconds are equal 
  if (F.seconds == S.seconds)
      TruthStatus = true;

  else
    TruthStatus = false;


return TruthStatus;
}

 // operator for equality of two time objects 
 // if objects are not equal returns true, returns false otherwise 
bool operator!=(const Time& t1 , const Time& t2)
{

Time F; // creates F object to hold t1 values 
Time S; // creates S object to hold t2 values 
bool TruthStatus; // bool variable returned 

// sets F values to t1 values and converts them to seconds 
F.hours = t1.hours + (t1.days * 24);

F.minutes = t1.minutes + (F.hours * 60);

F.seconds = t1.seconds + (F.minutes * 60);

// sets S values to t2 values and converts them to seconds 
S.hours = t2.hours + (t2.days * 24);

S.minutes = t2.minutes + (S.hours * 60);

S.seconds = t2.seconds + (S.minutes * 60);

  // checks if  F seconds is not equal to S seconds 
  if (F.seconds != S.seconds)
      TruthStatus = true;

  else
    TruthStatus = false;


return TruthStatus;
}

 // pre fix operator for incrementing 1 to time object value
 // will add 1 to seconds 
Time& Time::operator++()
{
seconds = seconds + 1; // adds 1 to seconds 


   // converts out of range variables to next highest variable
   // example ( 121 minutes will be converted to 2 hours and 1 mintute)
if (seconds >= 60)
       (minutes = (minutes  + (seconds / 60))) , (seconds = seconds % 60);


   if (minutes >= 60 )
       (hours = (hours  + (minutes / 60))) , (minutes = minutes % 60);


   if ( hours >= 24)
       (days = (days +(hours/24))) , ( hours = hours % 24);


return *this; // returns Time object 
}


 // post fix operator for increment   
Time Time::operator++(int)
{
 Time T = *this; // sets T time object to current Time object 

seconds = seconds + 1; // adds 1 to seconds

     // converts out of range variables to next highest variable
        // example ( 121 minutes will be converted to 2 hours and 1 mintute)
   if (seconds >= 60)
       (minutes = (minutes  + (seconds / 60))) , (seconds = seconds % 60);


   if (minutes >= 60 )
       (hours = (hours  + (minutes / 60))) , (minutes = minutes % 60);


   if ( hours >= 24)
       (days = (days +(hours/24))) , ( hours = hours % 24);


 // returns T time object 
return T;

}


 // prefix decrement 
Time& Time:: operator--()
{

 // converts current Time object values to seconds 
hours = hours + (days * 24);

minutes = minutes + (hours * 60);

seconds = seconds + (minutes * 60);

seconds = seconds - 1;

     // converts out of range variables to next highest variable
        // example ( 121 minutes will be converted to 2 hours and 1 mintute)

 if (seconds >= 60)
       (minutes = (minutes  + (seconds / 60))) , (seconds = seconds % 60);


   if (minutes >= 60 )
       (hours = (hours  + (minutes / 60))) , (minutes = minutes % 60);


   if ( hours >= 24)
       (days = (days +(hours/24))) , ( hours = hours % 24);

 // return reference to calling object
return *this;
}

 // post fix decrement 
Time Time::operator--(int)
{

 Time T = *this; // copies current object value to T 

  // converts all values to seconds
hours = hours + (days * 24);

minutes = minutes + (hours * 60);

seconds = seconds + (minutes * 60);

seconds = seconds - 1; // subtracts 1 from seconds 

  // converts out of range variables to next highest variable
        // example ( 121 minutes will be converted to 2 hours and 1 mintute)

 if (seconds >= 60)
       (minutes = (minutes  + (seconds / 60))) , (seconds = seconds % 60);


   if (minutes >= 60 )
       (hours = (hours  + (minutes / 60))) , (minutes = minutes % 60);


   if ( hours >= 24)
       (days = (days +(hours/24))) , ( hours = hours % 24);

return T;

}
