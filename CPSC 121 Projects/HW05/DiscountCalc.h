struct DiscountCalc
{
  float price;
  float dollarsOff;
  float discountPerc;
  float additionalPerc;
  float tax;
};
float originalPrice(DiscountCalc original);
float discountedPrice(DiscountCalc discount);
DiscountCalc displayMenu();
