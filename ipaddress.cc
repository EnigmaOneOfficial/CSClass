/*
  Author: Damon Gillombardo
  Date: 10/25/2018
  Description: Formats and calculates unique IP addresses per site.
*/

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <fstream>

using namespace std;

bool alreadyExists(string ip, string iplist[]) { // checks if within the array, the given ip already exists
  for (int i = 0; i < 100; i++){
    if (ip == iplist[i]) {
      return true; // if the ip already exists
    }
  }
  return false; // if the ip was never found again
}

void getUniqueIPs(fstream& input, ofstream& output) { // reads and writes from and to files.
  while (!input.eof()) { // check if eof
    int count = 0; //keep track of unique visits
    int totalVisits = 0; //keep track of total visits
    string website; // get the website name
    input >> website;
    if (input.eof()) { // check if its end of file
      return;
    }
    string ipAddresses[100]; // create our array of up to 100 possible ip addresses per website
    string formattedIPs; // format the unique ips into a readable string

    for (int i = 0; i < 100; i++) { // loop through the possible 100 ips
      string placeholder; // placeholder to check if its a legal ip
      input >> placeholder;
      if (placeholder != "-----") { // make sure we arent trying to ge the next website
        if (!alreadyExists(placeholder, ipAddresses)) { // check if it doesnt already exist in our array
          count++; // increase the unique visit count
          ipAddresses[count] = placeholder; // put it in out unique address ip
          formattedIPs += "\t" + placeholder + "\n"; // format our unique ip string
        }
        totalVisits++; // increase the total visits
      } else {
        break; // go on to next website
      }
    }

    output << website << " | Number of visitors: " << totalVisits << " | Unique visitors: " << count << endl << formattedIPs << endl; // write to our output file
    cout << website << " | Number of visitors: " << totalVisits << " | Unique visitors: " << count << endl << formattedIPs << endl; // also print to screen

  }

}

void getFiles() { // get the name of our input and output text files
  cout << "Please enter the name of your input file: "; // initializing variables for input
  fstream input;
  string inputName;
  cin >> inputName;
  input.open(inputName.c_str()); // try to open
  while (input.fail()) { // if it wont open then keep trying
    cout << "You have entered an invalid file name, please input another or type EXIT to exit the program: ";
    cin >> inputName;
    if (inputName == "EXIT") { // let them exit the program if they want
      exit(1);
    } else {
      input.open(inputName.c_str()); // try to open the new file name they gave
    }
  }

  cout << "Please enter the name of your output file: "; // initializing variables for output
  ofstream output;
  string outputName;
  cin >> outputName;
  output.open(outputName.c_str());
  while (output.fail()) {
    cout << "You have entered an invalid file name, please input another or type EXIT to exit the program: ";
    cin >> outputName;
    if (outputName == "EXIT") {
      exit(1);
    } else {
      input.open(outputName.c_str());
    }
  }

  getUniqueIPs(input, output); // call to getting the ips from our input and output filess

  input.close(); //close them after this function finishes (yields)
  output.close();

}

int main() {

  getFiles();

  return 0;
}
