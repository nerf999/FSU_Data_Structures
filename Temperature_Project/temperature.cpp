#include <iomanip>
#include <iostream>
#include "temperature.h"

using namespace std;

//  default constructor to initialize variables
Temperature::Temperature()
{
defaultprecision = cout.precision(); // int to reset output precision 
Temp = 0; // default value of 0 
Scale = 'C'; // default scale of C for celsius 
ScaleFormat = 'D'; // used to set format settings 
}

Temperature::Temperature(double T, char S)
{
Scale = S; // sets scale to S 

 // error checks Scale and sets it to C if a invalid character is found 
if (((Scale != 'F')&&(Scale != 'f')&&(Scale != 'C')&&(Scale != 'c')&&(Scale != 'K')&&(Scale != 'k')))
(Scale = 'c');

Temp = T;  //sets Temp to T 

// Error checks for valid temp. if number is invalid sets it to 0
if(((Scale == 'F')|(Scale == 'f'))&&((-459.67) >= Temp))
 Temp = 0;

// Error checks for temp. If invalid is set to 0 
else if(((Scale == 'C')|(Scale == 'c'))&&((-273.15) >= Temp))
 Temp = 0;

// error checks for temp. if invalid is set to 0
else if(((Scale == 'K')|(Scale == 'k'))&&(0 >= Temp))
 Temp = 0;

}

//  Function for user input of temp 
// Error checks with loop
// Reprompts user if invalid info is entered 
void Temperature::Input()
{

// seta loop control variable to zero 
bool ValidInfo = false;


while (ValidInfo == false)
{

// prompts user ot enter temp 
cout << "Please enter Temperature" << endl;
cin >>  Temp;
// prompts user to enter Scale 
cout << "Please enter temperature scale as F, C, or K" << endl;
cin >>  Scale;

// checks if temp is valid for Fahrenheit  
if(((Scale == 'F')|(Scale == 'f'))&&(Temp >= (-459.67)))
 ValidInfo = true;

// checks if temp is valid for Celsius 
 else if(((Scale == 'C')|(Scale == 'c'))&&(Temp >= (-273.15))) 
   ValidInfo = true;

// checks if temp is valid for Kelvin 
 else if(((Scale == 'K')|(Scale == 'k'))&&(Temp >= 0)) 
  ValidInfo = true;

// Validinfo stays false 
 else ValidInfo = false;

//tells user that invalid info was entered 
if (ValidInfo == false)
cout << " you have entered invalid data please reinput" << endl;

}


}

// outputs temp and scale 
void Temperature::Show() 
{
if (Scale == 'f')  // sets Scale to capital letter
Scale = 'F';

else if (Scale == 'c')
Scale = 'C';

else if (Scale == 'k')
Scale = 'K';


// If scale format is D outputs default formatting 
if (ScaleFormat == 'D') 
cout <<  Temp << " " <<  Scale << endl;

if (ScaleFormat == 'P') // if scale format is P outs precise format 
cout <<  Temp << " " <<  Scale << endl;


// if Scale format is long outputs long format
if ((ScaleFormat == 'L')&&(Scale == 'F'))  
cout <<  Temp << " " << "Fahrenheit" << endl; 

if ((ScaleFormat == 'L')&&(Scale == 'C'))
cout <<  Temp << " " << "Celsius" << endl;

if ((ScaleFormat == 'L')&&(Scale == 'K'))
cout <<  Temp << " " << "Kelvin" << endl;


}


// sets Temp and Scale from deg and s
// Error checks for invalid info 
bool Temperature::Set(double deg, char s)
{

bool ValidInfo;

 // If s is invalid char Scale is set to C
if (((s != 'F')&&(s != 'f')&&(s != 'C')&&(s != 'c')&&(s != 'K')&&(s != 'k')))
(Scale = 'c');

else Scale = s;
 

 // if Scale and temp are valid Validinfo is set to true 
if (((Scale == 'F')|(Scale == 'f'))&&(deg >= (-459.67)))
  (ValidInfo = true)&&(Temp = deg);


if (((Scale == 'C')|(Scale == 'c'))&&(deg >= (-273.15)))
  (ValidInfo = true)&&(Temp = deg);


if(((Scale == 'K')|(Scale == 'k'))&&(deg >= 0))
 (ValidInfo = true)&&(Temp = deg);



return (ValidInfo);
}

// returns Temp double  
double Temperature::GetDegrees() const
{

return (Temp);
}


// returns Scale char 
char Temperature::GetScale() const
{

return (Scale);
}


//Sets format setting for output
// changes stay until called again 
bool Temperature::SetFormat (char f)

{ 
bool ValidInfo = true;

  // f is set to D ScaleFormat is set to D 
if (f == 'D')
    cout.precision(defaultprecision)&& (ScaleFormat == 'D'); 

 // if f is set to P scale format is set to P 
 // precision is also set to 1 and fixed 
else if (f == 'P')
     cout.precision(1)&&(ScaleFormat == 'P') && cout << fixed; 

 // if f is set to L ScaleFormat is set to L
else if (f == 'L')
     cout.precision(defaultprecision)&&(ScaleFormat == 'L');

 // invalid info set to false if f is invalid 

else ValidInfo = false;

return(ValidInfo);	
}


 // converts Temp to different scale 
 // sc entered as F,C,K will determine how the value changes
bool Temperature:: Convert(char sc)

{
bool ValidInfo = true;

  // if sc is F and Scale is C converts temp  
  if (((sc == 'F')|(sc == 'f'))&&((Scale == 'C')|(Scale == 'C')))
     (Temp = (Temp* (9.0/5.0))+ 32);

   // if sc is F and Scale is K converts temp
  if (((sc == 'F')|(sc == 'f'))&&((Scale == 'K')|(Scale == 'k')))
     (Temp = ((Temp -273.15)*(9.0/5.0)+32));

    // if sc is C and Scale is F converts temp 
  if (((sc == 'C')|(sc == 'c'))&&((Scale == 'F')|(Scale == 'f')))
     (Temp = ((Temp - 32)*(5.0/9.0))); 

     // if sc is C and Scale is K  converts temp
  if (((sc == 'C')|(sc == 'c'))&&((Scale == 'K')|(Scale == 'k')))
      (Temp = (Temp - 273.15));
      
       // if sc is K and Scale is F converts temp
  if (((sc == 'K')|(sc == 'k'))&&((Scale == 'F')|(Scale == 'f')))
     (Temp = ((Temp - 32)*(5.0/9.0)+273.15));

       // if sc is K and Scale is C converts temp
  if (((sc == 'K')|(sc == 'k'))&&((Scale == 'C')|(Scale == 'c')))
      (Temp = (Temp + 273.15));


  // if sc is invalid ValidInfo is set to false 
if (((sc != 'F')&&(sc != 'f')&&(sc != 'C')&&(sc != 'c')&&(sc != 'K')&&(sc != 'k')))
ValidInfo = false;

return (ValidInfo);
}


 // compares temperatures from the calling abject and a parameter 
int Temperature::Compare(const Temperature& d) 
{
   // number used to compare temps  
  double T;

 // takes 1 , 0 , or -1 depending on values 
 int EqualStat;


   // checks if Scales are different. T will take the converted value  
    if  (((Scale == 'F')|(Scale == 'f'))&& ((d.Scale == 'C')|(d.Scale == 'c')))
           (T  = (d.Temp* (9.0/5.0))+ 32);

   if  (((Scale == 'F')|(Scale == 'f'))&& ((d.Scale == 'K')|(d.Scale == 'k')))
         (T  = ((d.Temp -273.15)*(9.0/5.0)+32));

   if  (((Scale == 'C')|(Scale == 'c'))&& ((d.Scale == 'F')|(d.Scale == 'f')))
         (T = ((d.Temp - 32)*(5.0/9.0)));

   if  (((Scale == 'C')|(Scale == 'c'))&& ((d.Scale == 'K')|(d.Scale == 'k')))
         (T = (d.Temp - 273.15));

  if  (((Scale == 'K')|(Scale == 'k'))&& ((d.Scale == 'F')|(d.Scale == 'f')))
        (T = ((d.Temp - 32)*(5.0/9.0)+273.15));        
 
  if  (((Scale == 'K')|(Scale == 'k'))&& ((d.Scale == 'C')|(d.Scale == 'c')))
       (T  = (d.Temp + 273.15));



       // checks equalty if scales are the same 
  if  ((Scale == d.Scale)&&(Temp == d.Temp))
      EqualStat = 0;

  if ((Scale == d.Scale)&&(Temp > d.Temp))
     EqualStat = 1;

  if ((Scale == d.Scale)&&(Temp < d.Temp)) 
      EqualStat = -1;
  

   // Checks if the differences in temp 
   // sets EqualStat 
  if (Temp > T) 
   EqualStat = 1;

  if (Temp <  T )
   EqualStat = 1;

  if (Temp == T)
   EqualStat = 1;


 // returns int EqualStat 
return (EqualStat);
}
