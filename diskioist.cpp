#include <iostream>
#include <fstream>  // used for file I/O
#include <string>   

using namespace std;

int main()
{
  string fileName, fileType;
  string input;

  // Ask user for file name and type
  cout << "Enter the file name: ";
  getline(cin, fileName);
  cout << "Enter the file type: ";
  getline(cin, fileType);

  // Create the file name and type
  string fullFileName = fileName + "." + fileType;

  // Open the file in output mode
  ofstream outFile(fullFileName);

  // Check if the file was successfully opened
  if (!outFile) {
    cerr << "Error: unable to open file " << fullFileName << endl;
    return 1;
  }

  // Ask the user for input
  cout << "Enter the some text to save in the file: ";
  getline(cin, input);

  // Write the input to the file
  outFile << input << endl;

  // Close the file
  outFile.close();

  // Open the file in input mode
  ifstream inFile(fullFileName);

  // Check if the file was successfully opened
  if (!inFile) {
    cerr << "Error: unable to open file " << fullFileName << endl;
    return 1;
  }

  // Read the input from the file and display it on the terminal
  string line;
  while (getline(inFile, line)) {
    cout << line << endl;
  }

  // Close the file
  inFile.close();

  return 0;
}
