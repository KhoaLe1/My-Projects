#include <iostream>
#include "rps.h"
using namespace std;

void Tool::setStrength(int st)
{
    strength = st;
}
void Tool::setType(char c)
{
    type = c;
}
int Tool::getStrength()
{
   return strength;
}
char Tool::getType()
{
   return type;
}
bool Rock::fight(Tool enemy)
{
  if ( type == 'r')
  {
    if (enemy.getType() == 'r')
    {
      return (strength > enemy.getStrength());
    }
    if (enemy.getType() == 'p'){
      return ! (strength * 0.5 < enemy.getStrength());
    }
    if( enemy.getType() == 's'){
      return (strength * 2 > enemy.getStrength());
    }
  }
}
bool Paper::fight(Tool enemy)
{
  if ( type == 'p')
  {
    if (enemy.getType() == 'p')
    {
      return (strength > enemy.getStrength());
    }
    if (enemy.getType() == 's'){
      return ! (strength * 0.5 < enemy.getStrength());
    }
    if( enemy.getType() == 'r'){
      return (strength * 2 > enemy.getStrength());
    }
  }
 }
bool Scissors::fight(Tool enemy)
{
  if ( type == 's')
  {
    if (enemy.getType() == 's')
    {
      return (strength > enemy.getStrength());
    }
    if (enemy.getType() == 'r'){
      return ! (strength * 0.5 < enemy.getStrength());
    }
    if( enemy.getType() == 'p'){
      return (strength * 2 > enemy.getStrength());
    }
  }
}

Rock::Rock()
{
    setStrength(1);
    setType('r');
}
Rock::Rock(int st)
{
    setStrength(st);
    setType('r');
}
Paper::Paper()
{
    setStrength(1);
    setType('p');
}
Paper::Paper(int st)
{
    setStrength(st);
    setType('p');
}

Scissors::Scissors()
{
    setStrength(1);
    setType('s');
}
Scissors::Scissors(int st)
{
    setStrength(st);
    setType('s');
}
