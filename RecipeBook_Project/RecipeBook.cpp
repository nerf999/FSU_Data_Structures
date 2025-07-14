
#include <iostream>
#include <cstring>
#include "RecipeBook.h"

using namespace std;

Recipe::Recipe(){
id = 0;
Name = new char[1];
Name[0] = '\0';

Description = new char[1];
Name[0] = '\0';
}

Recipe::~Recipe(){

delete[] Name;
delete[] Description;

}

Recipe::Recipe(const char* _Name){ 
id = 0;
int NameSize = strlen(_Name)+1;

Name = new char[NameSize];
strcpy(Name, _Name);

}

Recipe::Recipe(const char* _Name, const char* _Description, int _id){

id = _id;

Description = new char[strlen(_Description)+1];
strcpy(Description, _Description);

Name = new char[strlen(_Name)+1]; 
strcpy(Name, _Name);

}

Recipe::Recipe(Recipe& r){

Description = new char[strlen(r.Description)+1];
strcpy(Description, r.Description);

Name = new char[strlen(r.Name)+1];
strcpy(Name, r.Name);
}

Recipe& Recipe::operator=(const Recipe& r){

id = r.id;

delete[] Description;
Description = new char[strlen(r.Description)+1];
strcpy(Description, r.Description);

delete [] Name;
Name = new char[strlen(r.Name)+1];
strcpy(Name, r.Name);


return *this;
}


char* Recipe::GetName() const{

return Name;

}

char* Recipe::GetDescription() const{

return Description;

}


int Recipe::GetId()const {

return id;
}

// ==========================RecipeBook================//

RecipeBook::RecipeBook(){

RecipeList = new Recipe[5];
numRecipes = 0;

}

RecipeBook::RecipeBook(RecipeBook& r){

numRecipes = r.numRecipes;

RecipeList = new Recipe[numRecipes]; 

for (int i = 0; i < numRecipes; i++)
RecipeList[i] = r.RecipeList[i];

}


RecipeBook::~RecipeBook(){

delete[]RecipeList;

}

void RecipeBook::Add(const Recipe& r){

 if (numRecipes < 5)
 {RecipeList[numRecipes] =  r; }
 
 else

 { cout << "resizing book" << endl;
   Recipe* temp = new Recipe [numRecipes +1];
   for(int i = 0; i < numRecipes; i++)
      temp[i] = RecipeList[i];

   temp[numRecipes] = r;

   delete [] RecipeList;
   RecipeList = temp;
   }
    
   numRecipes++;
 }
   
 
Recipe* RecipeBook::GetRecipes() const{


return RecipeList;
}

void RecipeBook:: remove(int r){

for (int i = r; i < numRecipes - 1; i++)
RecipeList[i]= RecipeList[i+1];

numRecipes--;

}

void RecipeBook::Update(Recipe& r, int _id  ){

for (int i = 0; i < numRecipes; i++)
if (RecipeList[i].GetId() == _id)
    RecipeList[i] = r;

}


int  RecipeBook::returnIndex(int _id)const {

for (int i = 0; i < numRecipes; i++)
  if (RecipeList[i].GetId() == _id) 
      return i;

 return -1;
}


ostream& operator<<(ostream& o, const RecipeBook& r){

for(int i = 0; i < r.numRecipes; i++)
{


 o << "id: " << r.RecipeList[i].GetId() << endl;
  
 o << " Name:" << r.RecipeList[i].GetName() << endl;

 o << "Description: " << r.RecipeList[i].GetDescription() << endl;

  

 o << " ===========================================================" << endl;
}


return o;
}
