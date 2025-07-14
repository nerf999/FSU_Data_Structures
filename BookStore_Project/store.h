#include "book.h"
#include <iostream>

using namespace std;

class Store 
{

public:
 Store(); // default constructor 
 ~Store(); // dealocate BooksList


 // mutator functions 
 void AddBook(const char* t ,const char*  a,Genre g,double p ); // adds book 
 void MakeSale(int b); // Sells a book from inventory 

 // accessors
 void DisplayList() const; // Displays book entries and cash 
 int FindTitle(char* bTitle) const; // Finds a book by title 
 int FindAuthor(char* bAuthor) const; // finds a book by author 
 void GenreList(char g) const; // finds a book from genre 
 void DisplayBook(int E) const;  // displays book info 

private:
int ListSize; // current size of array
double CashAmount; // amount of cash in store register 
Book * BooksList; // array of book objects 
int MaxSize; // maximum array size


void Grow();  // grows array size 
};
