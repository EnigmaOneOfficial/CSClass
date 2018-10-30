/*
  Author: Damon Gillombardo
  Date: 10/1/2018
  Description: A program that creates a barcode for a certain zip code.
*/

#include <iostream>
#include <fstream>

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
  int retVal = 0;
  if (sum % 10 == 0) {
    retVal = 0;
  } else {
    retVal = 10 - (sum%10); // An easy algorithm used to detect the leftover of a number and then get what it would need to be divisible by 10
  }
  return retVal;
}

int main() {
  ifstream input;
  string inputFile;

  cout << "Enter the name of your input file: ";
  cin >> inputFile;

  input.open(inputFile);


  if (input.fail()) {
    cout << "File does not exist, exiting program.";
    exit(1);
  }

  while (!input.eof()) { // Loop through until the end of the file

    bool isValid = true; // initializing variables we will use later
    bool is5Digits = true;
    int sum = 0; // sum of digits in zipcode to get final barcode piece
    int numOfChars = 0; // to check if is5Digits
    char zipcode = ' '; // to keep collecting individual zipcodes

    int x;

    string zipToBarcode = "|";

    while (zipcode != '\n') {
      input.get(zipcode); // retrieve each char of the zipcode
      if (zipcode - '0' >= 0 && zipcode - '0' <= 9) { // if its within 0-9 (is valid)
        zipToBarcode += getDigitCode(zipcode) + " ";
        sum += zipcode - '0'; // increase the sum
        numOfChars++; //
      } else if (zipcode != '\n') {
        isValid = false;
      }
      if (input.eof()) { // check if end of file again
        return (EXIT_SUCCESS);
      }
    }

    if (numOfChars != 5) { //if there are only 5 digits
      is5Digits = false;
    }

    if (is5Digits && isValid) { // If we have a valid zipcode
      cout << "Code: " + zipToBarcode << getDigitCode('0' + getCheckDigitValue(sum)) + "|" << endl;
    } else if(!isValid) { // If one of the "digits" were invalid
      cout << "Error: Code is invalid" << endl; // Read the more in depth error of whether the digits are valid
    } else if(!is5Digits) { // If we have valid "digits" but we don't have 5
      cout << "Error: zip code must be 5 digits" << endl; // Read a more simple error that checks if theres 5 digits
    }


  }
  input.close(); // close the file
  return 0;
}
