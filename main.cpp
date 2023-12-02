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
            addCommission(clientList, commissionList);
            break;
        case 'D':
            deleteCommission(clientList, commissionList);
            break;
        case 'P':
            printMenu(clientList, commissionList);
            break;
        case 'U':
            update(clientList, commissionList);
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


// ~~~~ ADD CHECK FOR IF LIST IS EMPTY BEFORE PRINTS

// ~~~~ ADD MENU TO CHOOSE PRINTS

// ~~~~ ADD NEW CLIENT 

// ~~~~ add new commission
// ~~~~  |  need to ask user if they want to see all the client ids when entering an id is required

// need funct to change doiscout and print the clients firsrt

// need to update commis price based on discount
//  | thus need funct to update discounts
//  | update price
//  | update time


// ~~~~ q to quit in add new client

// update active comm automatically
// update total comm

// ~~~~ CALL UPDATES WHEN CALLING PRINT
// ~~~~ auto update the active commissions


// ~~~~ delete commission

// ~~~~ need to  construct active commissions when adding client
// ~~~~   | so when adding a new commission/reading raw file, add it to corresponding client 


// ~~~~ manually update price/ progress
// ~~~~ | if progress == 100, finished status = true;


// ~~~~ DONT JUST END THE FUNCTION IF USER WANTS TO PRINT DEFAULT,  NEED TO PRINT CLIENT