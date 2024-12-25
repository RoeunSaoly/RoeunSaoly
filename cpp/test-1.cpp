#include<iostream>
using namespace std;
// // To read data from File to variable in our program
// void ReadDataFromFile()
// {
//     //To Do
// }
// //================================================
// void WriteDataToFile(){
//     //To do
// }
// //================================================
int main()
{
    int choice=0;
    //ReadDataFromFile();
    //Program Executes
    while(choice!=1){
    //show data Monitor, Example: contact, book, hotel room

    // ShowData();
    cout<<"1.Add contact";
    cout<<"2.Remove contact";
    cout<<"3.Edit contact";
    cout<<"4.Save cotact";
    cout<<"-1.Exit";
    scanf("%d",choice);

    switch(choice){
        case 1:
        //Request to User to make imput intormation
        //Add the input info, to Array
        //AddNewRecord();
        break;
        case 2:
        //Show all contact
        //Request User to input the contact. which will be edite
        //EditeRecord();
        break;
        case 3:
        //Request User to input which contact, they want to edit
        //Request to input new information
        //Remove();
        break;
        case 4:
        //Save Data Array
        //SaveContact();
        break;
        case -1:
        //Show message to User ,our progam is turned -off
        //CloseApp();
        break;

    }
    exit(1);
    }//Exit while loop

    //WriteDataToFile();
    return 0;
}