/*
  Author: Damon Gillombardo
  Date: 10/1/2018
  Description: A program that creates a barcode for a certain zip code.
*/

#include <iostream>
#include <typeinfo>

using namespace std;

string getDigitCode(char digit) { // A switch function that will give a certain character a given barcode
  switch(digit){
    case '1':
      return ":::||";
    case '2':
      return "::|:|";
    case '3':
      return "::||:";
    case '4':
      return ":|::|";
    case '5':
      return ":|:|:";
    case '6':
      return ":||::";
    case '7':
      return "|:::|";
    case '8':
      return "|::|:";
    case '9':
      return "|:|::";
    case '0':
      return "||:::";
  }
}
int getCheckDigitValue(int sum) { // Function to get a number that is divisible by 10 for the last part of the barcode
  return 10 - (sum%10); // An easy algorithm used to detect the leftover of a number and then get what it would need to be divisible by 10
}

int main() {
  char answer = 'y';
  while (answer == 'y') { // Loop through until the user does not want to enter any more barcodes

    cout << "Enter a zipcode: ";
    char zipcode[5] = {0,0,0,0,0}; // Separate the zipcode into an array of 5 characters
    cin >> zipcode;

    int sum = 0; // A variable to be used later on that will be the sum of all the individual digits
    int numOfDigits = 0; // A check of how many digits there are to calculate a different error
    bool is5Digits = true; // If there are 5 digits
    bool isValid = true; // If the digits are valid

    for (int i = 0; i <= 4; i++) { // The loop to check how many spaces of the array are actually filled (not necessarily for a digit, due to error checking something different)
      if(zipcode[i] == 0) {
        is5Digits = false;
      } else {
        numOfDigits++;
      }
    }

    for (int i = 0; i <= numOfDigits - 1; i++) { // The loop to check how many of the spaces that are filled are actually valid digits
      if(!(zipcode[i] - 48 <= 9 && zipcode[i] - 48 >= 0)) { // I use -48 to convert from a char to an int
        isValid = false;
      } else {
        sum += zipcode[i] - 48;
      }
    }

    if (is5Digits && isValid) {
      cout << "Code: |" << getDigitCode(zipcode[0]) << " " << getDigitCode(zipcode[1]) << " " << getDigitCode(zipcode[2]) << " " << getDigitCode(zipcode[3]) << " " << getDigitCode(zipcode[4]);
      cout << " " << getDigitCode('0' + getCheckDigitValue(sum)) << "|" << endl; // Call the functions in order to convert a digit to a code
    } else if(!isValid) {
      cout << "Error: Code is invalid" << endl; // Read the more in depth error of whether the digits are valid
    } else if(!is5Digits) {
      cout << "Error: zip code must be 5 digits" << endl; // Read a more simple error that checks if theres 5 digits
    }

    cout << "More codes (y/n)?";
    cin >> answer; // Asking if the user would like to use another code
  }
}
