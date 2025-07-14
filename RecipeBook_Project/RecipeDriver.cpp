#include <iostream>
#include <cstring>
#include <string>
#include "RecipeBook.h"

using namespace std;

int Length;

int main()
{

RecipeBook book;
Recipe one("one", "Chicken soaked in broth" , 2856);
Recipe two("two", "Chicken soaked in broth" , 2856);
Recipe three("three", "Chicken soaked in broth" , 2856);
Recipe four("removetest", "earaeraer" , 1);
Recipe five("five", "Chicken soaked in broth" , 2856);
Recipe six("six", "Chicken soaked in broth" , 2856);
Recipe seven("seven", "Chicken soaked in broth" , 2856);

book.Add(one);
book.Add(two);
book.Add(three);
book.Add(four);
book.Add(five);
book.Add(six);
book.Add(seven);






char choice;
bool status = true;

while (status != false)
{
cout << " Recipe book program " << endl;
cout << "============================================== " << endl;
cout << " a to add recipe to book" << endl;
cout << " l to list all entries "<< endl; 
cout << " u to update a listing " << endl;
cout << " d too delete a listing " << endl;
cout << " x to exit program " << endl;
cout << "============================================= " << endl;

cin >> choice;

 if (choice == 'x')
  {


  status = false;

  }



   if (choice == 'l')
  {

  cout << book << endl;
  
  }


   if (choice == 'a')
   {
   
   
   string name;
   string description;

    cout << "Enter a name " << endl;
    getline(cin.ignore(), name);   


    cout << "Enter a description " << endl;
    getline(cin , description); 

 const char* _Name = name.c_str();
  const char* _Description  = description.c_str();

 cout << " please enter recipe Id" << endl;
  

  Recipe two(_Name, _Description, 5);

book.Add(two);


   }

  if (choice == 'u')
  {
  
  int _id;
  int id;   
   cout << " Please enter id of Recipe you would like to update " << endl;     

    cin >> id;
   
    string name;
    string description;

    cout << "Enter a new name " << endl;
    getline(cin.ignore(), name);


    cout << "Enter a new description " << endl;
    getline(cin , description);

   const char* _Name = name.c_str();
   const char* _Description  = description.c_str();

   cout << "please enter a new id " <<  endl;

   cin >> _id; 

   Recipe two(_Name, _Description, _id);

  book.Update(two, id);

  }
  

  if (choice == 'd')
  {

  int _id;

  cout  << " Please enter id of recipe you would like to remove " << endl;
  cin >> _id;
 
 int index = book.returnIndex(_id);
  
if (index > -1)
 book.remove(index);

 else cout << " No Recipe was found with the given id" << endl;

  }



 }

return 0;
}
