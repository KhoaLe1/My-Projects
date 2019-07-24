#include "PriceListItem.h"

PriceListItem::PriceListItem(const string &itemName, const string &code, double price, bool taxable)
{
  name = itemName;
  bar_code = code;
  cost = price;
  tax = taxable;
}

PriceListItem::PriceListItem()
  {
  name = " ";
  bar_code = " ";
  cost = 0.0;
  tax = false;
  }

string PriceListItem::getItemName()
  {
  return name;
  }

string PriceListItem::getCode()
  {
  return bar_code;
  }

double PriceListItem::getPrice()
  {
  return cost;
  }

bool PriceListItem::isTaxable()
  {
    return tax;
  }
