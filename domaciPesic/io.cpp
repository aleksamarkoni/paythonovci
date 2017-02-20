#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib> // for exit()

using namespace std;

int main() {

  ifstream inf("input.txt");
  if (!inf) {
        // Print an error and exit
        cerr << "Uh oh, input.txt could not be opened for reading!" << endl;
        exit(1);
  }
  // While there's still stuff left to read
  while (inf) {
        // read stuff from the file into a string and print it
        string strInput;
        //inf >> strInput;
        getline(inf, strInput);
        cout << strInput << endl;
    }

    return 0;

    // When inf goes out of scope, the ifstream
    // destructor will close the file
}
