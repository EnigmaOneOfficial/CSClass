/*
  Author: Damon Gillombardo
  Date: 9/6/2018
  Description: Calculate discounts for inputted customer name and inputted item amount/price.
*/

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main() {
  const double tax = 6.5; /// Declare the constant of tax
  string firstName, lastName; // Customer's first and last name initialization
  int quantity; // Quantity of item initialization
  double price, discount; // Price per item and discount initialization
  cout << "Enter the customer's first name, last name, quantity, & price" << endl; // Tell user what to input
  cin >> firstName >> lastName >> quantity >> price; // Input the first name, last name, quantity of item, and price per item
  cout << "Enter the discount percentage: "; // Tell user what to input
  cin >> discount; // Input the discount

  cout << fixed << setprecision(2); // Using iomanip to fix the precision of numbers to 2 decimal places

  double origPrice = price * quantity; // Calculate the total price of items
  double discountPrice = origPrice/discount; // Calculate the discount amount for the items
  double afterDiscount = origPrice - discountPrice; // Calculate the price after the discount
  double totalTaxes = (afterDiscount/100) * tax; // Calculate the price of taxes
  double taxedPrice = afterDiscount + totalTaxes; // Calculate the price after tax

  // Here is where we will print all of our calculations and format the output
  cout <<  "_____________________________________\nCust. Name:\t " + firstName + " " + lastName + "\nItem Price:\t $" << price << "\nQuantity:\t " << quantity << "\nDiscount %:\t " << discount << "%\nOrig. Price:\t $" << origPrice << "\nDiscount Amount: $" << discountPrice << endl;
  cout << "======================================\nSubtotal:\t $" << afterDiscount << "\nTaxes:\t\t $" << totalTaxes << "\nTotal Due:\t $" << taxedPrice << "\n======================================";

  return 0;
}
