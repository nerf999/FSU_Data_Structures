#include <iomanip>
#include <iostream>
#include "store.h"
#include <cstring>

using namespace std;

 // default constructor for store object 
Store::Store()
{
MaxSize = 5; 
ListSize = 0;
CashAmount = 0;
BooksList = new Book[ListSize];
}
 
Store::~Store()
{
  delete[] BooksList;
}

 // addes a book to the Store object BooksList array
void Store::AddBook(const char* t , const char*  a, Genre g, double p)
{
 if (ListSize == MaxSize) // grows array if needed
      Grow(); 

 BooksList[ListSize++].Set(t, a, g, p); // adds entry to BooksList with Set

}

   // Displays  Cash amount and Book inventory 
void Store::DisplayList() const
{
  cout << "Store has $" << CashAmount << " in the register" << endl;

    // prints all book entrys using the Display function 
  for (int i = 0; i < ListSize; i++)
       BooksList[i].Display();

    // outputs amount of stored books 
   cout << "there are " << ListSize << "Books in the store" << endl;
}


 // will grow the maxsize of the BooksList array 
void Store::Grow()
{

// adds 5 to  to listsize and sets it as maxsize 
MaxSize = ListSize + 5;  
cout << "Array now has "<< MaxSize << "slots" << endl;   
 
  // creates an array to take the values of BooksList
 Book* TempList = new Book[MaxSize];

 // Sets TempList to same values as ListSize
for (int i = 0; i < ListSize; i++)
  TempList[i] = BooksList[i];

delete [] BooksList; // deletes previous array 
BooksList = TempList; // BooksList now has values of TempList 
}

  // finds a book object by searching array for title 
int Store::FindTitle(char* bTitle) const 
{

  // searches all entrys for a title match 
  // returns a 1 on success 
for (int i = 0; i < ListSize; i++)
   if(strcmp(BooksList[i].GetTitle(), bTitle) ==0)  
                return i;

// if title not found returns -1
return -1;
}


 // finds a book by searching for matching author 
 // prints all mathcing info 
int Store::FindAuthor(char* bAuthor) const
{
 
 // sets result to -1
 int result = -1;

 // checks for matching author and prints all matches 
// if any matches are found result is set to 1 
 for (int i = 0; i < ListSize; i++)
    if(strcmp(BooksList[i].GetAuthor(), bAuthor) ==0)
          {BooksList[i].Display();  
            result = 1;}

 return result;
}

 // Displays a book information 
void Store::DisplayBook (int E) const
{

BooksList[E].Display();

}

// makes a sale and removes the book from array 
void Store::MakeSale(int b)
{
 // adds money to register from book price 
CashAmount = CashAmount + BooksList[b].GetPrice(); 

cout << "Book price is $" << BooksList[b].GetPrice() << endl;

 // removes book from array 
for (int d = b + 1; d < ListSize; d++)
     BooksList[d-1] = BooksList[d];

 // shrinks list size 
  ListSize--;
 
   // prints new arrys size and money in register 
 cout << "Array is now has  " << ListSize << " slots" << endl; 
cout << "Register now has $" << CashAmount << endl;
}


 // searches array for all books from specific genre 
void Store::GenreList(char g) const
{
  double TotalPrice; // total price of listed books 
  Genre x;  // genre 
  int BookAmount; // total amount of listed books 

       // checks for passed in character for genre type 
   if ( g == 'F'|| g == 'f')
         x = FICTION;

   if ( g == 'M'|| g == 'm')
         x = MYSTERY;

   if ( g == 'S'|| g == 's')
         x = SCIFI;

   if ( g == 'C'|| g == 'c')
         x = COMPUTER;  

    // checks books for matching genres 
  for (int i = 0; i < ListSize; i++)
     if(BooksList[i].GetGenre() == x)

    // lists all matching books 
   // calculates price and book amount 
   {
    BookAmount++;
    BooksList[i].Display();
    TotalPrice = TotalPrice + BooksList[i].GetPrice();
   }     
    

 // outputs price of matching books and amount of matching books 
 cout << "Total price for all books is $" <<  TotalPrice << endl;
 cout << "Total books for this genre is " << BookAmount << endl; 

}
