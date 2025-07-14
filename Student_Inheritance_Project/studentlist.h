#include <fstream>
 using namespace std;

#ifndef _STUDENTLIST_H
#define _STUDENTLIST_H

enum Major {BIOLOGY, THEATER, COMPUTERSCI};


class Student // info common to all students
{
public: 
Student(); // student object
Student(const char* l, const char* f, Major x);
void PrintInfo()const;
virtual void FilePrint(ofstream& x)=0;
virtual Major GetMajor() const;

protected:
char LastName[20];
char FirstName[20];
Major current;

private:     

};

class Bio: public Student
{
public:
Bio();
Bio(const char* l, const char* f, Major x, int Lab1, int T1, int T2, int T3, int T4);
void FilePrint(ofstream& x);

protected:
double Lab, Test1, Test2, Test3, Test4;

};

class CompSci: public Student
{

public:
CompSci();
CompSci(const char* l, const char* f, Major x, double p, int t1, int t2, int t3);
 void FilePrint(ofstream& x);

protected:
double Paverage, Test1, Test2, Final;


};

class Theater: public Student
{
public:
Theater();
Theater(const char* l, const char* f, Major x, int s, int M, int F);
 void FilePrint(ofstream& x);

protected:
double Scenes, Midterm, Final;

};


class StudentList
{
public:
   StudentList();               // starts out empty
   ~StudentList();              // cleanup (destructor)

   bool ImportFile(const char* filename);
   bool CreateReportFile(const char* filename);
   void ShowList() const;       // print basic list data

private:
int MaxSize;
int ListSize;
void grow(int n);
Student* List;
};


#endif
