//using this code to read the file
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main () {
  // Create a text string, which is used to output the text file
  string myText;

  // Read from the text file
  ifstream MyReadFile("filename.txt");
  //ifstream is reads from filse

  // Use a while loop together with the getline() function to read the file line by line
  while (getline (MyReadFile, myText))
  //using getling to catch the filename.txt
    {
        // Output the text from the file
        cout << myText;
    }

  // Close the file
  MyReadFile.close();
}