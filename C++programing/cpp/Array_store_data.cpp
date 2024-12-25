// Create array functions to store data
#include<iostream>
using namespace std;

int main(){
    int n;
    string name[n];
    int id[n];
    int age[n];

    cout<<"Please enter number of user  :"; cin>>n; fflush(stdin); cin.ignore();

    for(int i=0; i<n; i++){
        cout<<"Enter Name   :"; getline(cin, name[n]);
        cout<<"Enter ID     :"; cin>>id[n] ;
        cout<<"Enter Age    :"; cin>>age[n] ;
        cin.ignore();
    }
    for(int i=0; i<n; i++){
        cout<<name[n]<<endl;
        cout<<id[n]<<endl;
        cout<<age[n]<<endl;
    }
    return 0;
}