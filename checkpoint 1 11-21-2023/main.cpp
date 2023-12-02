// linkedListGroupProject.cpp : This file contains the 'main' function. Program execution begins and ends there.
#pragma once
#include <iostream>

#include "functions.h"
#include "linkedClient.h"

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
    //Linked<Commission> commissionList;


    processRawFile(inFile, clientList);
    
    clientList.printList();

    cout << "\n\nbouta deconstruct\n\n";
    system("pause");
    return 0;
}
