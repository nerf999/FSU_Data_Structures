 
#include <iomanip>
#include <iostream>
#include "book.h"
#include <cstring>

using namespace std;

// default constructor for book object
// sets title and author as blank strings
// sets type to SCIFI and price as 0  
Book::Book()
{ 
strcpy(title," ");
strcpy(author, " ");
type = SCIFI;
price = 0;
}


// returns price of book object 
double Book::GetPrice()const
{
return price;
}

// returns genre of book object 
Genre Book::GetGenre()const
{
return type;
}


// returns book title 
const char* Book::GetTitle() const
{
return title;
}

// returns book author
const char* Book::GetAuthor() const
{
return author;
}


// creates a book object with parameters 
// genre type is set to g, price is set to p
// author is sets to a, title is set to t
void Book::Set(const char* t , const char*  a, Genre g, double p)
{

strcpy(author, a);
strcpy(title, t);
type = g;
price = p;
}


// displays information of a book object 
// changes iostream format for the duration of the function
void Book::Display() const
{

// sets an int for default iostream precision 
int defaultprecision;
defaultprecision = cout.precision();

// sets precision and flags
cout.precision(1);
cout.setf(ios:: fixed);

cout << title <<"\t "  << author<< "\t " << type << "\t " << "$   " << price << endl;

// resets precision and flags 
cout.unsetf(ios:: fixed);
cout.precision(defaultprecision);
}
