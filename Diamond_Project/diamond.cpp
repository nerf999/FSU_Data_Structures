
  
#include <iomanip>
#include <iostream>
#include "diamond.h"
#include <cmath>

using namespace std;


Diamond::Diamond()
// default constructor to intialize diamond side length
// default constructor initializes border and fill characters 
{
SideLength = 1;
Border = '#';
Fill = '*';

}


Diamond::Diamond(int L, char B, char F)
// initializes SideLength, Border and Fill to the given parameters 
{
  SideLength = L ; 
  Border = B  ; 
  Fill = F;

     // sets side length to mimimum if given value is too small  
   if (SideLength < 1)
      SideLength = 1;
 
     // sets sidelength to maximum if given value is too large 
   if (SideLength > 39)
       SideLength = 39;
}


  // sets border character to given parameter 
void Diamond::SetBorder(char B)
{
 Border = B;
if (int(Border)<33)
   {Border = '#';}

if (int(Border) > 126)
   {Border = '#';}

}


// sets fill character to given parameter
void Diamond::SetFill(char F)
{
Fill = F;

if (int(Fill)< 33 )
 {Fill = '*';}

if (int(Fill) > 126)
{Fill = '*';}

}

// returns side length of diamond 
int Diamond::GetSize()const 
{

return SideLength;  

}

// shrinks sidelength by 1 if value is over 1
// can not go below 1  
void Diamond::Shrink()
{

if (SideLength > 1)
SideLength --; 

}


// grows sidelength by 1 if value is under 39
// can not go over 39 
void Diamond::Grow()
{

if (SideLength < 39)
SideLength ++;

}

int Diamond::Perimeter() const
// calculates perimeter of diamond from Sidelength. 
{

return SideLength * 4;
}

double Diamond::Area() const
// calculates area of the diamond from SideLength 
{

return (sqrt(3)/4*(SideLength*SideLength))*2 ;
}


// draws diamond with loops
void Diamond::Draw() const 
{

int Trilength; // height of triangle that forms half of the diamond
 
char Space = ' '; // empty space used to seperate characters that make up diamond 

 // rounds value to int 
Trilength = round((SideLength * sqrt(3))/2);


       // top half of diamond 
       for (int i = 0; i < Trilength; i++)
       {
          for (int k = 0; k < ((SideLength) - (i - 1)); k++) 
         {
           cout << Space;

         }
         for (int u = 0; u < i; u++)
         {
                 if (( u == 0)|| (u == (i - 1)))
                 {cout << Border <<  Space;} 
                 
                 else 
                 { cout << Fill << Space;}          
 
         }  
         cout << endl;
      
     } 

     // bottom half of diamond 
    for (int t  = Trilength; t > 0; t--)
    {

        for (int g = 0; g < ((SideLength) - (t - 1)); g++) 
        {cout << Space;}

        for (int p = 0; p < t; p++)
        {
         
              if ((p == 0)||(p == (t - 1)))
               {cout  << Border << Space; } 
                 
               else 
                   
               {cout << Fill << Space; }
          
        }
        cout << endl;
    }
}

// prints out summary and picture of diamond 
void Diamond::Summary()
{
cout << "Size of diamond's side = " << SideLength << endl; 
cout << "Perimeter of diamond = " << SideLength * 4 << endl; 
cout << " Area of diamond = " << setprecision(5)<< (sqrt(3)/4*(SideLength*SideLength))*2 << endl;
cout << "Diamond looks like: " << endl;

int Trilength;
char Space = ' ';

 // rounds value to int 
Trilength = round((SideLength * sqrt(3))/2);

       for (int i = 0; i < Trilength; i++)
       {
          for (int k = 0; k < ((SideLength) - (i - 1)); k++) 
         {
           cout << Space;

         }
         for (int u = 0; u < i; u++)
         {
                 if (( u == 0)|| (u == (i - 1)))
                 {cout << Border <<  Space;} 
                 
                 else 
                 { cout << Fill << Space;}          
 
         }  
         cout << endl;
      
     } 

     // bottom diamond 
    for (int t  = Trilength; t > 0; t--)
    {

        for (int g = 0; g < ((SideLength) - (t - 1)); g++) 
        {cout << Space;}

        for (int p = 0; p < t; p++)
        {
         
              if ((p == 0)||(p == (t - 1)))
               {cout  << Border << Space; } 
                 
               else 
                   
               {cout << Fill << Space; }
          
        }
        cout << endl;
    }
  
 
}
