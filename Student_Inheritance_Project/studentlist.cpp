#include <iostream>
#include <cstring>
#include "studentlist.h"
#include <fstream>
#include <string>
#include <iomanip>

 using namespace std;

StudentList::StudentList() // default constructor for student list 
{

MaxSize = 1;
ListSize = 0;
List[ListSize];

}

// destructor for student list 
StudentList::~StudentList()
{

delete[]List;

}


Major Student::GetMajor() const // returns current student major
{

return current;

}

bool StudentList::ImportFile (const char* filename) // gets student info from input file 
{
 ifstream FList;
 FList.open(filename); // opens file 

 if (!FList) 
 return false;   // failstate check for file 

else 
{int x;

FList >> x; // number of new students gotten from file 
 grow(x);

for( int i = 0; i < x; i++) // put new students into array 
{
 string Lname;
 string Fname;
 string major; 
 Major f;

 // getws names and major from file 
 getline(FList, Lname, ',');
 getline(FList, Fname);
 getline(FList, major, ' ');

if (major == "Computer");
{ getline(FList, major, ' '); 

f = COMPUTERSCI;
   
// gets program grades and finds average
double p1, p2, p3, p4, p5, p6, Average; 
FList >> p1;
FList >> p2;
FList >> p3;
FList >> p4;
FList >> p5;
FList >> p6;

Average = (p1+p2+p3+p4+p5+p6)/6;

int t1, t2, final;

FList >> t1;
FList >> t2;  // gets test grades and final 
FList >> final; 

List[ListSize] =  CompSci(Lname.c_str(), Fname.c_str(), f, Average, t1, t2, final);// creates CompSci student object 
}

if (major == "Biology")
{
 f = BIOLOGY;

 int Lab, t1, t2, t3, t4; // gets lab and test grades from file 
 
 FList >> Lab;
 FList >> t1;
 FList >> t2;
 FList >> t3;
 FList >> t4;

List[ListSize] = Bio(Lname.c_str(), Fname.c_str(), f, Lab, t1, t2, t3, t4);  // creates CompSci student object 
}

if (major == "Theater")
{
 
 f = THEATER;
 
 int Scene, Midterm, Final;

 FList >> Scene; // gets scene grades and test grades from file 
 FList >> Midterm;
 FList >> Final;

  Theater* t = new Theater(Lname.c_str(), Fname.c_str(), f, Scene, Midterm, Final);

 List[ListSize] = t;

}
ListSize++; // grows size of list 


}

}
FList.close();
return true;
}

 // grows student list based on file input 
void StudentList::grow(int n)
{
MaxSize = ListSize + n; // new size of array

Student* TempList[MaxSize]; // new temp array

for (int i = 0; i < ListSize; i++) // sets new array elemetns to old array elements
TempList[i] = &List[i];


delete [] List; 
List = *TempList;

}

 // prints out student information to file 
bool StudentList::CreateReportFile(const char* filename)
{
 ofstream RList;  // opens file 
 RList.open(filename);

 if (!RList) // failsafe for file opening
 return false;
 

else
 {
  RList<< "Student Grade Summary" << endl;
 RList<< "---------------------" << endl;

 RList << "Biology Class" << endl;
 RList<< endl;

 RList<< left << setw(60)<< " Student" << "Final " << "Final " << "Letter" <<
 endl;

 RList<< left << setw(60)<< " Name" << "Exam  " << "Avg   " << "Grade" <<
 endl;
RList << "----------------------------------------------------------------------" << endl;

for (int i=0; i < ListSize; i++) // checks if array position is a bio student 
{                                // prints out bio info if true

if (List[i].GetMajor() == BIOLOGY)
List[i].FilePrint(RList);
}
RList << endl;

 RList << "Theater Class" << endl;
 RList<< endl;

 RList<< left << setw(60)<< " Student" << "Final " << "Final " << "Letter" <<
 endl;

 RList<< left << setw(60)<< " Name" << "Exam  " << "Avg   " << "Grade" <<
 endl;
RList << "----------------------------------------------------------------------" << endl;

for (int i=0; i < ListSize; i++)
{

if (List[i].GetMajor() == THEATER) // checks if array position is a theater student 
List[i].FilePrint(RList);          // prints out info if true 
}

 RList << "CompSci Class" << endl;
 RList<< endl;

 RList<< left << setw(60)<< " Student" << "Final " << "Final " << "Letter" <<
 endl;

 RList<< left << setw(60)<< " Name" << "Exam  " << "Avg   " << "Grade" <<
 endl;
RList << "----------------------------------------------------------------------" << endl;

for (int i=0; i < ListSize; i++)
{

if (List[i].GetMajor() == COMPUTERSCI) // checks if student position is a compsci student 
List[i].FilePrint(RList);              // prints out info if true 
}



  }
return true;
 }

  // prints out general information about student 
void Student::PrintInfo() const
{
cout.width(20); cout << left << LastName <<" ";
cout.width(20); cout << left << FirstName;

if (current == BIOLOGY) 
 cout << left << "Bio" << endl;

if (current == COMPUTERSCI)
 cout << left << "Computer Science" << endl; 

if (current == THEATER)
 cout << left << "Theater" << endl;
}


  // prints out grade information to file 
void Bio::FilePrint(ofstream& x)
{ double Grade;
  
 Grade = Lab*.3 + Test1*.15 + Test2*.15 + Test3*.15 + Test4*.25;

x << left << setw(20) << FirstName << " " << left << setw(40)<< LastName;
x << left << setw(5) << Test4 << left << setw(6) << Grade;

if (Grade >= 90)
x << "A" << endl;

else if (Grade >= 80)
x << "B" << endl;

else if (Grade >= 70)
x << "C" << endl;

else if (Grade >= 60)
x << "D" << endl;

else 
x << "F" << endl;

}

// prints out grade information to file 
void CompSci::FilePrint(ofstream& x)
{ double Grade;

Grade = Paverage*.30 + Test1*.20 + Test2*.20 + Final*.30;

x << left << setw(20) << FirstName << " " << left << setw(40)<< LastName;
x << left << setw(5) << Final << left << setw(6) << Grade;

if (Grade >= 90)
x << "A" << endl;

else if (Grade >= 80)
x << "B" << endl;

else if (Grade >= 70)
x << "C" << endl;

else if (Grade >= 60)
x << "D" << endl;

else             
x << "F" << endl;
}


 // prints out grade information to file 
void Theater::FilePrint(ofstream& x)
{
 double Grade;

 Grade = Scenes*.40 + Midterm*.25 + Final*.35;

x << left << setw(20) << FirstName << " " << left << setw(40)<< LastName;
x << left << setw(5) << Final << left << setw(6) << Grade;

if (Grade >= 90)
x << "A" << endl;

else if (Grade >= 80)
x << "B" << endl;

else if (Grade >= 70)
x << "C" << endl;

else if (Grade >= 60)
x << "D" << endl;

else             
x << "F" << endl;

}

// default student constructor 
Student::Student()
{

strcpy(LastName," ");
strcpy(FirstName, " ");

}

// stuent constructor with parameters
Student::Student(const char* l, const char* f, Major x)
{

strcpy(LastName, l);
strcpy(FirstName, f);
current = x;

}

// default bio student constructor 
Bio::Bio()
{
Lab = 0;
Test1 = 0;
Test2 = 0;
Test3 = 0;
Test4 = 0;

}


// bio student constructor with parameters
Bio::Bio(const char* l, const char* f, Major x, int Lab1, int T1, int T2, int T3, int T4):Student(l,f,x)
{
Lab = Lab1;
Test1 = T1;  
Test2 = T2;
Test3 = T3;
Test4 = T4;

}

// deafult constructor for compsci student 
CompSci::CompSci()
{
Paverage = 0;
Test1 = 0;            
Test2 = 0;
Final = 0; 
}


// constructor for copmsci student 
CompSci::CompSci(const char* l, const char* f, Major x, double p, int t1, int t2, int t3):Student(l,f,x)
{
Paverage = p;
Test1 = t1;
Test2 = t2;
Final = t3;
}

// default constructor for theater student 
Theater::Theater()
{
Scenes = 0;
Midterm = 0;
Final = 0;
}

// constructor for theater students 
Theater::Theater(const char* l, const char* f, Major x, int s, int M, int F):Student(l,f,x)
{
 Scenes = s;
 Midterm = M;
 Final = F;

}

