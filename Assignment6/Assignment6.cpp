#include <iostream>
#include <fstream>  //allows istream/ostream
#include <string>
#include <stdlib.h> //allows atoi
#include "HashTable.h"
using namespace std;


void displayMenu();

int main(int argc, char*argv[])
{
    int input;

    // Create a new communication network
    HashTable myHash;

    // Flag used for exiting menu
    bool quit = false;

    // Used for input
    string input1;
    string input2;
    //int year;

    while(quit != true)
    {
        displayMenu();
        cin >> input;

        //clear out cin
        cin.clear();
        cin.ignore(10000,'\n');

        switch (input)
        {
        // Insert a movie
        case 1:
            cout << "Enter title:" << endl;
            getline(cin,input1);
            cout << "Enter year:" << endl;;
            getline(cin,input2);
            //year = atoi(input2.c_str());
            myHash.insertMovie(input1,atoi(input2.c_str()));
            break;
        // Delete a movie
        case 2:
            cout << "Enter title:" << endl;
            getline(cin,input1);
            myHash.deleteMovie(input1);
            break;
        // Find a movie
        case 3:
            cout << "Enter title:" << endl;
            getline(cin,input1);
            myHash.findMovie(input1);
            break;

        // Print table contents
        case 4:
            myHash.printTableContents();
            break;

        // Quit
        case 5:
            cout << "Goodbye!" << endl;
            quit = true;
            break;

        // invalid input
        default:
            cout << "Invalid Input" << endl;
            cin.clear();
            cin.ignore(10000,'\n');
            break;
        }
    }
    return 0;
}

void displayMenu()
{
    cout << "======Main Menu======" << endl;
    cout << "1. Insert movie" << endl;
    cout << "2. Delete movie" << endl;
    cout << "3. Find movie" << endl;
    cout << "4. Print table contents" << endl;
    cout << "5. Quit" << endl;
    return;
}
