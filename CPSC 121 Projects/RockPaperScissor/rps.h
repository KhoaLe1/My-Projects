#include <iostream>
using namespace std;

class Tool
{
  protected:
    int strength;
    char type;

  public:
        void setStrength(int st);
        int getStrength();
        char getType();
        void setType(char c);
        bool fight(Tool Fight);
};

class Rock: public Tool
{
public:
    Rock();
    Rock(int st);
    bool fight(Tool enemy);
};

class Paper: public Tool
{
public:
    Paper();
    Paper(int st);
    bool fight(Tool enemy);
};

class Scissors: public Tool
{
public:
    Scissors();
    Scissors(int st);
    bool fight(Tool enemy);
};
