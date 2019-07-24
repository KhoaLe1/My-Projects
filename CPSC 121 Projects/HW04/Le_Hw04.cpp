
//Khoa Le
//CSPS 121-15
//Shuffle Sort
#include <iostream>
#include <ctime>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <chrono>
#include <thread>
#include "logfile.h"
#include "Le_Hw04.h"
using namespace std;
using namespace std::this_thread;
using namespace std::chrono;

int main()
{
  logf use;
// Storing txt file into array
  use.logOpen();
  ifstream in_file;
  string foo[235886];
  in_file.open("shuffled.txt");
  use.logWrite("Event","Opened shuffled.txt",__LINE__,__PRETTY_FUNCTION__);
  for(int k; k < 235886; k++)
    {
      getline(in_file,foo[k]);
    }
  use.logWrite("Event","Reading in txt file",__LINE__,__PRETTY_FUNCTION__);
  in_file.close();
  use.logWrite("Event","Closed shuffled.txt",__LINE__,__PRETTY_FUNCTION__);

// Sorting
    int bar = sizeof(foo)/sizeof(foo[0]);
    sorting(foo,bar);
    use.logWrite("Event","Sorting through text file",__LINE__,__PRETTY_FUNCTION__);

// Writing array into a new file
    ofstream out_file ("sorted.txt");
    expo(foo,bar);
    use.logWrite("Event","Output the sorted txt into sorted.txt",__LINE__,__PRETTY_FUNCTION__);

// Searching for words
    search(foo);
    use.logWrite("Event","Searching to find the correct word",__LINE__,__PRETTY_FUNCTION__);
    int b=10,c=0;
    int a = b/c;
    use.logWrite("Warning","Dividing by zero will cause a crash",__LINE__,__PRETTY_FUNCTION__);
    use.logFlush();
    cout << a << endl;

    use.logClose();
    use.logRead();



return 0;
}
