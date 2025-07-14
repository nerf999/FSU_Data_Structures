#include <iostream>

using namespace std;



class Recipe 
{

private:
 int id;
 char* Name;
 char* Description;

public:
 Recipe();
 Recipe(const char* _Name);
 Recipe(const char* _Name, const char* _Description, int _id);
 Recipe(Recipe& r);
 ~Recipe();

 char* GetName() const;
 char* GetDescription() const;
 int GetId() const;

 Recipe& operator=(const Recipe& r );

};


class RecipeBook
{

friend ostream& operator<<(ostream&, const RecipeBook&);


private:

  Recipe* RecipeList;
  int numRecipes; 

public:
  RecipeBook();
  ~RecipeBook();
  RecipeBook(RecipeBook& r);
  void Add(const Recipe& r);
  void remove(int r);
  Recipe* GetRecipes() const;
 int returnIndex(int _id) const;  
 void Update(Recipe& r, int _id);


};
