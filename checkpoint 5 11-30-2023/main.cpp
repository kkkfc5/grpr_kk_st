// linkedListGroupProject.cpp : This file contains the 'main' function. Program execution begins and ends there.
#pragma once
#include <iostream>

#include "functions.h"
#include "linkedClient.h"
#include "linkedCommission.h"

using namespace std;

int main()
{

    ifstream inFile;
    inFile.open("test.txt");

    if (!inFile.good()) {
        cout << "badfile\n";
        return -1;
    }


    linkedClient clientList;
    linkedCommission commissionList;


    processRawFile(inFile, clientList, commissionList);
    inFile.close();

    
    


    // have one string, and add 1 or 0 to it depending on user input

    char input;

    menuHeader();
    cin >> input;

    //<< "(A)dd new client\n"
    //<< "(I)nput new commission\n"
    //

    while (toupper(input) != 'Q') {
        switch (toupper(input)) {
        case 'A':
            addClient(clientList);
            break;
        case 'C':
            break;
        case 'P':
            printMenu(clientList, commissionList);
            break;
        case 'S':
            save(clientList, commissionList);
            break;
        case 'Q':
            break;
        default:
            cout << "\nYou entered an invalid character. Please try again.\n\n";
        }

        menuHeader();
        cin >> input;
    }


    system("pause");
    return 0;
}


// ADD CHECK FOR IF LIST IS EMPTY BEFORE PRINTS

//ADD MENU TO CHOOSE PRINTS

// ~~ ADD NEW CLIENT 

// add new commission

// need to ask user if they want to see all the client ids when entering an id is required

// need funct to change doiscout and print the clients firsrt

// ~~ q to quit in add new client