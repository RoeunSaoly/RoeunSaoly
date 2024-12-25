#include <iostream>
using namespace std;
//================================================
//Function to input the value of array by user
void inputArray(int &n,int arr[]){
    cout<<"\n Input the element of Array:";
    cin>>n;
    for(int i=0;i<n;i++){
    cout<<" Array["<<i<<"] = ";
    cin>>arr[i];
    }
    cout<<endl;
}
//=================================================
//function to show the value of Array
void showArray(int n,int arr[]){
    cout<<"\n Array element are: \n";
    for(int i=0; i<n; i++){
        cout<<"index:["<< i <<"]= "<<arr[i]<<"\n";
    }
    cout<<endl;
}
//================================================
// Function to insert an element into the array at a specified position
void insertX(int &n, int arr[], int x, int pos) {
    if (pos < 1 || pos > n + 1) {
        cout << "Invalid position! Please enter a position between 1 and " << n + 1 << "." << endl;
        return;
    }
    else if (n >= 100) {
    cout << "Array is full! Cannot insert more elements." << endl;
    return;
    }
    for (int i = n; i >= pos; i--) {
        arr[i] = arr[i - 1];// Shift elements to the right
    }
    arr[pos - 1] = x;// Insert the element
    n++;// Increase array size
}
//=================================================
// Function to delete an element from the array at a specified position
void deleteElement(int &n, int arr[], int pos) {
    if (pos < 1 || pos > n) {
        cout << "Invalid position! Please enter a position between 1 and " << n << "." << endl;
        return;
    }
    for (int i = pos - 1; i < n - 1; i++) {
        arr[i] = arr[i + 1];// Shift elements to the left
    }
    n--;// Decrease array size
}
//=================================================
// Function to delete all occurrences of a value from the array
void deleteAllOccurrences(int &n, int arr[], int value) {
    int j = 0;  // New index for valid elements
    for (int i = 0; i < n; i++) {
        if (arr[i] != value) {
            arr[j++] = arr[i];// Keep elements not equal to `value`
        }
    }
    n = j; // Update the size of the array
}
//=================================================
//duplicate Element
void duplicateArray(int n, int arr[]){
    int search;
    cout<<"Enter the number of Array to Find duplicate value: \n";
    cin>>search;
    bool found = false;
    cout<<"Duplicate occurrences: \n";
    for(int i=0;i<n;i++){
        if(arr[i] == search){
            cout<<"Index:["<< i <<"] = "<<arr[i]<<"\n";
            found = true;
        }
    }
    if(!found){
        cout<<"No Duplicate found for"<<search<<".";
    }
    cout<<endl;
}
//=================================================
//non_duplicate Element
void nonDuplicateArray(int n, int arr[]){
    int search;
    cout<<"Enter the number of Array to Find duplicate value: \n";
    cin>>search;
    cout<<"Non_Duplicate occurrences: \n";
    for(int i=0;i<n;i++){
        if(arr[i] == search){
            cout<<"First occurrence: \n"<<"Index:["<< i <<"] = "<<arr[i]<<"\n";
            return;// Exit after finding the first occurrence
        }
    }
    cout << "Number " << search << " not found in the array." << endl;
}
//=================================================
//binary search
int binSearch(int arr[], int n, int searchKey) {
    int lowerBound = 0;
    int upperBound = n - 1;
    while (lowerBound <= upperBound) {
        int curIn = (lowerBound + upperBound) / 2;
        if (arr[curIn] == searchKey) {
            return curIn; // Found it
        } else if (arr[curIn] < searchKey) {
            lowerBound = curIn + 1;
        } else {
            upperBound = curIn - 1;
        }
    }
    return -1; // Element not found
}
//=================================================
// Driver Code
int main() {
    int arr[100] = {0};
    int i, x, pos, n = 10;
    int ch;
    do {
        // Menu options
        cout << "\n===============Menu===================";
        cout << "\n1. Input the value of array.";
        cout << "\n2. Show the value of array.";
        cout << "\n3. Insert an element.";
        cout << "\n4. Delete an element.";
        cout << "\n5. Delete all occurrences.";
        cout << "\n6. Duplicate Element.";
        cout << "\n7. Non_Duplicate Element.";
        cout << "\n8. Binary search.";
        cout << "\n9. Exit";
        cout << "\nEnter your choice: ";
        cin >> ch;

        switch (ch) {
            case 1:
                inputArray(n,arr);
                break;
            case 2:
                showArray(n,arr);
                break;
            case 3:
                // Insert an element
                cout << "\nEnter the value to insert: ";
                cin >> x;
                cout << "Enter the position (1-based index) to insert the value: ";
                cin >> pos;
                insertX(n, arr, x, pos);
                break;
           case 4:
            // Delete an element
            cout << "Enter the position (1-based index) of the element to delete: ";
            cin >> pos;
            deleteElement(n, arr, pos);
            break;
            case 5:
                // Delete all element
                cout << "Enter the position value of array that you want to delete all currently: ";
                cin >> pos;// Correct input for the value
                deleteAllOccurrences(n, arr, pos);
            break;
            case 6:
                // duplicate value
                duplicateArray(n,arr);
            break;
            case 7:
                // non_duplicate value
                nonDuplicateArray(n,arr);
            break;
            case 8:
            cout << "Enter the value to search for: ";
            cin >> x;
            pos = binSearch(arr, n, x);
            if (pos != -1) {
            cout << "Value found at index: " << pos << endl;
            } else {
            cout << "Value not found in the array." << endl;
            }
            break;
            case 9:
                // Exit
                cout << "Exiting program." << endl;
                break;

            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while (ch != 9);
    return 0;
}
