/*
  Author: Damon Gillombardo
  Date: 9/17/2018
  Description: A program that takes points on an x,y plane and gives information about it.
*/

#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>

using namespace std;

int main() {
  char choice = 'y';
  while(choice == 'y') { // Make the loop for repeating the program if a user wants to continue
    cout << "Enter a point (values for x and y)" << endl;
    double x, y; // Declare variables for x and y
    cin >> x >> y; // Input variables for x and y

    string pointPlace;// Declare variable to store string for output for if statement
    if(x == 0) { // If statement checking axes and quadrants
      pointPlace = "Point is on the y-axis ";
      if(y == 0) {
        pointPlace = "Point is on the origin ";
      }
    } else if(y == 0) {
      pointPlace = "Point is on the x-axis (";
    } else if(y > 0 && x > 0) {
      pointPlace = "Point is in quadrant I ("; // Quadrant I
    } else if(y > 0 && x < 0) {
      pointPlace = "Point is in quadrant II ("; // Quadrant II
    } else if(y < 0 && x < 0) {
      pointPlace = "Point is in quadrant III ("; // Quadrant III
    } else if(y < 0 && x > 0) {
      pointPlace = "Point is in quadrant IV ("; //Quadrant IV
    }
    cout << fixed << setprecision(1) << pointPlace << x << ", " << y << ")" << endl; // Output the point's position on the graph
    cout << fixed << setprecision(3) << "distance from the origin is " << sqrt(pow(x,2) + pow(y,2)) << endl; // Output distance from the origin
    cout << "Continue (y/n)?";
    cin >> choice; // Input user's decision of wether or not to continue
  }


  return 0;
}
