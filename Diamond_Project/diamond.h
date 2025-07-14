//--------------- diamond.H ---------------

class Diamond
{

public:
Diamond();    // default constructor 
  
// constructor with parameters
// L mus be an int between 0  and 40
// asicii value of characters must be in range of 33 through 126 
Diamond(int L = 1 , char B = '#'  , char F = '*' );


void SetBorder(char B);  // setter function to change border character 
void SetFill(char F); // setter function to change fill character 
void Summary();// prints out summary of Diamond

void Shrink(); // shrinks diamond by 1 unless side of diamond is 1 
void Grow();    // grows diamond by 1 unless side of diamond is 39 
void Draw()const ; // draws diamond 
int GetSize() const;  //getter function for side length 
int Perimeter() const; // getter function to get perimeter 
double Area() const;   // getter fuction to get area 



private:

int SideLength; // sidelength of diamond 
char Border;    // character for border of diamond 
char Fill;     // character for inside of diamond

};
   
