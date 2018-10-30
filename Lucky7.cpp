/*
  Author: Damon Gillombardo
  Date: 9/26/2018
  Description: Calculate a user's statistics with two dice adding up to 7
*/

#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std;

int main() {
  srand(time(NULL)); // Generate a seed for random number
  char answer = 'y';

  while (answer == 'y') { // Keep the program running until user says not
    double money; // Initialize money variable
    cout << "Enter the amount of money you have: ";
    cin >> money;

    int rolls = 0; // Keep track of total rolls
    double maximum = money; // Keep track of maximum amount of money possessed
    int bestRoll = 0; // Keep track of the number of rolls when maximum amount of money was possessed
    while (money >= 1) { // Keep rolling until you are out of money
      rolls++;
      int firstRandom = rand()%6; // Generate first dice number
      int secondRandom = rand()%6; // Generate second dice number
      if(firstRandom + secondRandom == 7) { // Check if they won
        money += 4;
        if (money > maximum) {
          maximum = money;
          bestRoll = rolls;
        }
      } else { // If they lost
        money -=1;
      }
    }
    cout << endl << "It took " << rolls << " rolls to lose all your money." << endl;
    cout << fixed << setprecision(2);
    cout << "Your maximum was $" << maximum << " and was reached after " << bestRoll << " rolls." << endl << endl;

    cout << "Play again? (y/n)";
    cin >> answer;
  }

}
