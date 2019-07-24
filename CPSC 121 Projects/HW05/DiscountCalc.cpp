#include <iostream>
#include "DiscountCalc.h"
using namespace std;


float originalPrice( DiscountCalc original)
{
  float originalPrice_1;
  originalPrice_1= original.price + original.tax;
  return originalPrice_1;
}
float discountedPrice( DiscountCalc discount)
{
  float discountedPrice_1;
  float discountedPrice_2;
  float foo;
  float bar;
  discountedPrice_1 = discount.price - discount.dollarsOff;
                foo = discount.price * discount.discountPerc;
                bar = (discount.price * discount.additionalPerc);
  discountedPrice_2 = discountedPrice_1 - foo - bar + discount.tax;
  return discountedPrice_2;
}
DiscountCalc displayMenu()
{
  DiscountCalc menu;
  cout << "Enter intitial price: ";
  cin >> menu.price;
  cout << "How many dollars off? ";
  cin >> menu.dollarsOff;
  cout << "What percentage of a discount in decimals? ";
  cin >> menu.discountPerc;
  cout << "Any additional percentage off in decimals? ";
  cin >> menu.additionalPerc;
  cout << "What is the tax? ";
  cin >> menu.tax;

  return menu;
}
