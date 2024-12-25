//Greate the file with c++
#include<iostream>
#include<fstream>
//fstream a combination of ofstream: creates, reads,and writes to files
using namespace std;
int main()
{
    //create and open atext file
    ofstream myFile("filename.txt");
    //ofstream is creates and writes to files

    //Write to the file
    myFile<<"ITE_M2";


    //close the file
    myFile.close();
}