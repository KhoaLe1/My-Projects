//Khoa Le
//CPSC 121-15
//Lab 01
//Change in coins
#include <iostream>
using namespace std;

int main ()
{
  int input = 0;
  int dimes = 0;
  int nickels = 0;
  int quarters = 0;
  int pennies = 0;


  cout << "Please enter a given amount of change in cents: " << endl;
  cin >> input;

  if(quarters = input/25)
  {
    cout << "Quarters: " << quarters << endl;
  }
       input = input%25;

  if(dimes = input/10)
  {
    cout <<"Dimes: " << dimes << endl;
  }
       input = input%10;

  if(nickels = input/5)
  {
    cout << "Nickels: " << nickels <<endl;
  }
       input= input%5;

 if(pennies = input%5)
 {
  cout << "Pennies: " << pennies << endl;
 }

  return 0;
}
