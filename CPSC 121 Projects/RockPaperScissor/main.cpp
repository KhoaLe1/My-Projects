#include <iostream>
#include "rps.h"
using namespace std;

int main()
{
  	Scissors s1(5);
  	Paper p1(7);
  	Rock r1(15);
  	cout << s1.fight(p1)<< endl << p1.fight(s1) << endl;
  	cout << p1.fight(r1)<< endl << r1.fight(p1) << endl;
  	cout << r1.fight(s1)<< endl << s1.fight(r1) << endl;

  	return 0;
}
