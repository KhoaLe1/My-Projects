#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <string>
#include <algorithm>
#include <ctype.h>
using namespace std;

void removeSpaces(string &str)
{
  int placement = 0;

  int found = str.find(";");
  if (found != string::npos)
  {
    placement = found;
    while (isspace(str[--placement]))
    {    }
    if (placement++ != found-1)
    {
      str.erase(placement+1,found);
    }
    if (str[placement] != ';')
    {
      str[placement] = ';';
    }
  }
}

void adjustSpaces(string &str)
{
  char c;
  char prev;
  int length = str.length();
  char adjust[length];
  int i = 0; 
  int x = 0;
  while ((c = str[i++]) != '\0')
  {
    if (c == ' ')
    {
      if (prev != ' ')
      {
        adjust[x++] = c;
      }
    }
    else 
    {
      adjust[x++] = c;
    }
    prev = c;
  }
  adjust[x] = '\0';
  str.replace(0,x,adjust);
  str.erase(x,length);
}

void organizeSpaces(string &str)
{
  int length = str.length();
  char adjust[length+2];
  char space = ' ';
  int i = 0;
  int j = 0;
  int found = str.find("*");
  if (found != string::npos)
  {
    while (i != found)
    {
      adjust[i] = str[j];
      i++;
      j++;
    }
    adjust[i++] = space;
    adjust[i++] = str[j++];
    adjust[i++] = space;
    while (i != length+2)
    {
      adjust[i++] = str[j++];
    }
    adjust[i] = '\0';
    str.replace(0,i,adjust);
  }
}

void efrainsfunction(istream& output)
{
  string str;
  ofstream out ("newdata.txt");
  int length = 0;
  size_t found, last;
  string array[20];
  int count = 0, i =0;

  while (getline(output,str))
  {
    length = str.length();
    if ((found = str.find("(*")) != string::npos)
    {
      while(true)
      {
        if (found!=string::npos)
        {
          last = str.find("*)");
          if (last!=string::npos)
          {
            str.erase(found,last+2);
            break;
          }
          else
          {
            str.erase(found, length);
            getline(output,str);
          }
        }
      }
    }
    str.erase(remove(str.begin(), str.end(), '\t'), str.end());
    if (isspace(str[0]))
    {
      while (isspace(str[i])) { i++; }
      str.erase(0,i);
    }
    if (str != "")
    {
      array[count++] = str;
    }
  }
  for (int x = 0; x < count; x++)
  {
    removeSpaces(array[x]);
  }
  for (int x = 0; x < count; x++)
  {
    adjustSpaces(array[x]);
  }
  for (int x = 0; x < count; x++)
  {
    organizeSpaces(array[x]);
  }
  cout << "This is the array based doc\n" << count << endl;
  for (int y = 0; y < count; y++)
  {
    cout << array[y] << endl;
    out << array[y] << endl;
  }
}

int main ()
{
  string name;
  cout << "Enter filename: ";
  cin >> name;
  ifstream f (name);
  if (f.is_open())
  {
    //Rspaces (f);
    efrainsfunction(f);
  }
  else
  {
    std::cerr << "error: file open failed.\n";
    return 1;
  }
  f.close();
  return 0;
}
