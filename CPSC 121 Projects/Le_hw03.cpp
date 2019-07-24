// Khoa Le
// CPSC 121-15
// HW 03
#include <iostream>
using namespace std;
int main()
{
  double first_1, second_1, answer_1;
  double first_2, second_2, answer_2;
  double first_3, second_3, answer_3;
  double first_4, second_4, answer_4;
  int choice;
   do {
    cout << " Please make a selection: " << endl;
    cout << " 1) Addition\n";
    cout << " 2) Subtraction\n";
    cout << " 3) Multiplication\n";
    cout << " 4) Division\n";
    cout << " 5) Quit\n" << endl;

    cin >> choice;

    if(choice == 1)
    {
      cout << " Addition\n";
      cout << " First term:";
      cin >> first_1;
      cout << " Second term:";
      cin >> second_1;
      answer_1 = first_1 + second_1;
      cout << " Answer: " << answer_1 << endl << endl;

    }
    if(choice == 2)
    {
      cout << " Subtraction\n";
      cout << " First term:";
      cin >> first_2;
      cout << " Second term:";
      cin >> second_2;
      answer_2 = first_2 - second_2;
      cout << " Answer: " << answer_2 << endl << endl;

    }
    if(choice == 3)
    {
      cout << " Multiplication\n";
      cout << " First term:";
      cin >> first_3;
      cout << " Second term:";
      cin >> second_3;
      answer_3 = first_3 * second_3;
      cout << " Answer: " << answer_3 << endl << endl;
    }
    if(choice == 4)
    {
      cout << " Division\n";
      cout << " First term:";
      cin >> first_4;
      cout << " Second term:";
      cin >> second_4;
      answer_4 = first_4/second_4;
      cout << " Answer: " << answer_4 << endl << endl;
    }
    if(choice == 5)
    {
      cout << " Quitting.\n";
      return 0;
    }
   } while( choice <= 5);
}
