#include "GroceryBill.h"
#include <iostream>

using namespace std;

GroceryBill::GroceryBill(const PriceList *priceList, double taxRate)
{
  price_list = *priceList;
  tax_rate = taxRate;
}


void GroceryBill::scanItem(string scanCode, double quantity) {
	PriceListItem temp = price_list.getItem(scanCode);
	EntryList[size] = temp;
	if(price_list.isValid(scanCode)== false){
		throw invalid_argument(" Invalid code " + scanCode);
	}
  if(price_list.isValid(scanCode)){
    PriceListItem Scanned = price_list.getItem(scanCode);
    if(Scanned.isTaxable()){
      total += ( quantity * Scanned.getPrice()) + ((quantity *Scanned.getPrice()) * tax_rate)/100;
    }
    else{
      total += (quantity * Scanned.getPrice() );
    }
  }
	size++;
	// To be completed
}

// Scan multiple codes and quantities from the given text file
// Each line contains two numbers separated by space: the first is the code (an integer), the second the quantity (a float/double)
// Example line from text file:
// 15000000 1.5
void GroceryBill::scanItemsFromFile(string filename) {
	// To be completed
	// HINT: Look at code in PriceList::createPriceListFromDatafile(string filename)
	 ifstream myfile(filename);

	if (myfile.is_open()) {
		cout << "Successfully opened file " << filename << endl;
		string name;
		string code;
		double price;
		bool taxable;
		while (myfile >> name >> code >> price >> taxable)
		  {
			   cout << code << " " << taxable << endl;
		  }
		myfile.close();
	}
	else
		throw invalid_argument("Could not open file " + filename);
}

// return the total cost of all items scanned
double GroceryBill::getTotal()
{
  return total;
}

// Print the bill to cout. Each line contains the name of an item, total price, and the letter "T" if tax was addded.
// The last line shows the total.
// An example:
//Plastic_Wrap	1.60547 T
//Sugar_white	5.475
//Waffles_frozen	5.16
//Oil_Canola_100%_pure	2.69
//Potatoes_red	13.446
//TOTAL 	28.3765
void GroceryBill::printBill() {
	// To be completed

}
