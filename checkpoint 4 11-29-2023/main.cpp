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

    //processRawFile(inFile, clientList);
    processRawFile(inFile, clientList, commissionList);
    inFile.close();

    //commissionList.printList();
    commissionList.sortPrice('y');
    commissionList.sortPrice('n');
    commissionList.sortPriority('y');
    commissionList.sortPriority('n');
    clientList.print();
    //commissionList.saveFile();
    clientList.saveFile();
    //cout << "\n\nbouta deconstruct\n\n";


    system("pause");
    return 0;
}


// ADD CHECK FOR IF LIST IS EMPTY BEFORE PRINTS