//Khoa Le
//CPSC 121-15
//HW02
//Code Sort
#include <iostream>
#include <string>
using namespace std;

int main()
{
 string foo;
 int length;
 int bar;
 cout <<"Enter something in: " <<endl;
 cin >> foo;
 if(foo[0]=='-' && isdigit(foo[1]))
 {
   cout << foo <<" is Negative! " << endl;
 }
 else if(isdigit(foo[0]))
 {
   if(foo[0]=='0')
   {
   cout << foo  <<" is Zero! " << endl;
   }
  else if(foo[0] > 0)
  {
   int bar = stoi(foo);
   cout << bar << " is Positive! " << endl;
  }
}

//String or Character
  else
  {
    length= foo.length();
    if(length > 1)
    {
      cout << foo <<" is a String!" <<endl;
    }
    else if(length == 1)
    {
      cout << foo << " is a Character!" << endl;
    }
  }

  return 0;
}
