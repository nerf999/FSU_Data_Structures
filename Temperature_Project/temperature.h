//---------------------------- temperature.h ----------

// decleration of temperature class



class Temperature 
{

public:
Temperature(); // default constructor

//constructor with parameters
Temperature( double T = 0, char S = 'C'); 

void Input(); // user input for Temp and Scale  

void Show();// outputs current values 


bool Set(double deg, char s); // sets Temp and Scale 

// Compares temps of different objects 
int Compare(const Temperature& d); 


double GetDegrees()const; // outputs Temp 

char GetScale ()const; // outputs Scale 

// converts temp based on parameters 
bool Convert(char sc); 

bool SetFormat(char f); // setsformat based on parameter

private:

double Temp; // given temperature number 
char Scale; // temperature scale
int defaultprecision; // stores default I/O precision  
char ScaleFormat; // used to change scale 


};
