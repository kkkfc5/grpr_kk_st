#include "linkedCommission.h"

void linkedCommission::addByPrice(Commission d) {
    //Create a new node (set data & pointer values)
    Node<Commission>* newNode = new Node<Commission>;
    newNode->data = d;
    newNode->nextPtr = nullptr;

    //check for empty list
    if (headPtr == nullptr) {
        headPtr = newNode;
        tailPtr = newNode;
    }
    //check to see if newNode goes before headPtr
    // if so adjust headptr
    else if (newNode->data.getPrice() < headPtr->data.getPrice()) {
        newNode->nextPtr = headPtr;
        headPtr = newNode;
    }
    else {
        //loop through to find where to insert new node
        Node<Commission>* tempPtr = headPtr;
        while (tempPtr->nextPtr != nullptr && tempPtr->nextPtr->data.getPrice() < newNode->data.getPrice()) { // << -- THIS WILL ERROR BECAUSE FNAME/LNAME FIELDS DONT EXIST 
            tempPtr = tempPtr->nextPtr;
        }
        //tempPtr is pointing to the node prior to where newNode will go
        newNode->nextPtr = tempPtr->nextPtr;
        tempPtr->nextPtr = newNode;
        //adjust tailptr if newNode is the last node
        if (tempPtr == tailPtr) {
            tailPtr = newNode;
        }
    }
}


void linkedCommission::addByPriority(Commission d) {
    //Create a new node (set data & pointer values)
    Node<Commission>* newNode = new Node<Commission>;
    newNode->data = d;
    newNode->nextPtr = nullptr;
    //check for empty list
    if (headPtr == nullptr) {
        headPtr = newNode;
        tailPtr = newNode;
    }
    //check to see if newNode goes before headPtr
    // if so adjust headptr
    else if (newNode->data.getPriority() < headPtr->data.getPriority()) {
        newNode->nextPtr = headPtr;
        headPtr = newNode;
    }
    else {
        //loop through to find where to insert new node
        Node<Commission>* tempPtr = headPtr;
        while (tempPtr->nextPtr != nullptr && tempPtr->nextPtr->data.getPriority() < newNode->data.getPriority()) { // << -- THIS WILL ERROR BECAUSE FNAME/LNAME FIELDS DONT EXIST 
            tempPtr = tempPtr->nextPtr;
        }
        //tempPtr is pointing to the node prior to where newNode will go
        newNode->nextPtr = tempPtr->nextPtr;
        tempPtr->nextPtr = newNode;
        //adjust tailptr if newNode is the last node
        if (tempPtr == tailPtr) {
            tailPtr = newNode;
        }
    }
}













void linkedCommission::sortPrice(char filterFinished) {
    Node<Commission>* tempNode = headPtr;
    linkedCommission tempComm;
    while (tempNode != nullptr) {
        tempComm.addByPrice(tempNode->data);


        tempNode = tempNode->nextPtr;

    }

    //need to print this now after it just got sorted
    tempComm.printPrice(filterFinished);

    //cout << "Ending queue print\n";
};





void linkedCommission::sortPriority(char filterFinished) {
    Node<Commission>* tempNode = headPtr;
    linkedCommission tempComm;
    while (tempNode != nullptr) {
        tempComm.addByPriority(tempNode->data);
        tempNode = tempNode->nextPtr;
    }

    //need to print this now after it just got sorted
    tempComm.printPriority(filterFinished);
}













void linkedCommission::printPrice(char filterFinished) {
    Node<Commission>* tempNode = headPtr;
    cout << "v_______v_______v_______v_______v_______v_______v_______v \n";
    cout << "|Price  |Comm.ID|Clie.ID|Priort.|Time   |Finish |Progr. | \n";
    cout << "|-------|-------|-------|-------|-------|-------|-------|";
    while (tempNode != nullptr) {
        if (toupper(filterFinished) == 'Y') { // if user wants to filter out the Finished commissions
            if (!tempNode->data.getFinished()) {
                cout << fixed << setprecision(2)
                    << "\n|" << left << setw(7) << tempNode->data.getPrice()
                    << "|" << left << setw(7) << tempNode->data.getCommID()
                    << "|" << left << setw(7) << tempNode->data.getClientID()
                    << "|" << left << setw(7) << tempNode->data.getPriority()
                    << "|" << left << setw(7) << tempNode->data.getTime();

                // below: if the status is finished, print a yes. [[NOTE :: if you try to print a boolean, it prints a 1 or 0]]
                if (tempNode->data.getFinished()) { cout << "|" << left << setw(7) << "Yes" << "|"; }
                else { cout << "|" << left << setw(7) << "No" << "|"; }

                cout << left << setw(7) << tempNode->data.getProgress() << "|";

            }
        }
        else { // else, print everything regardless.
            cout << fixed << setprecision(2)
                << "\n|" << left << setw(7) << tempNode->data.getPrice()
                << "|" << left << setw(7) << tempNode->data.getCommID()
                << "|" << left << setw(7) << tempNode->data.getClientID()
                << "|" << left << setw(7) << tempNode->data.getPriority()
                << "|" << left << setw(7) << tempNode->data.getTime();


            // below: if the status is finished, print a yes. [[NOTE :: if you try to print a boolean, it prints a 1 or 0]]
            if (tempNode->data.getFinished()) { cout << "|" << left << setw(7) << "Yes" << "|"; }
            else { cout << "|" << left << setw(7) << "No" << "|"; }

            cout << left << setw(7) << tempNode->data.getProgress() << "|";

        }
            tempNode = tempNode->nextPtr;

        
    }

    cout << "\n|=======|=======|=======|=======|=======|=======|=======|";
    cout << "\n^       ^       ^       ^       ^       ^       ^       ^\n\n\n";
};


void linkedCommission::printPriority(char filterFinished) {
    Node<Commission>* tempNode = headPtr;
    cout << "v_______v_______v_______v_______v_______v_______v_______v \n";
    cout << "|Price  |Comm.ID|Clie.ID|Priort.|Time   |Finish |Progr. | \n";
    cout << "|-------|-------|-------|-------|-------|-------|-------|";
    while (tempNode != nullptr) {
        if (toupper(filterFinished) == 'Y') { // if user wants to filter out the Finished commissions
            if (!tempNode->data.getFinished()) {
                cout << fixed << setprecision(2)
                    << "\n|" << left << setw(7) << tempNode->data.getPriority()
                    << "|" << left << setw(7) << tempNode->data.getCommID()
                    << "|" << left << setw(7) << tempNode->data.getClientID()
                    << "|" << left << setw(7) << tempNode->data.getPrice()
                    << "|" << left << setw(7) << tempNode->data.getTime();

                // below: if the status is finished, print a yes. [[NOTE :: if you try to print a boolean, it prints a 1 or 0]]
                if (tempNode->data.getFinished()) { cout << "|" << left << setw(7) << "Yes" << "|"; }
                else { cout << "|" << left << setw(7) << "No" << "|"; }

                cout << left << setw(7) << tempNode->data.getProgress() << "|";

            }
        }
        else { // else, print everything regardless.
            cout << fixed << setprecision(2)
                << "\n|" << left << setw(7) << tempNode->data.getPriority()
                << "|" << left << setw(7) << tempNode->data.getCommID()
                << "|" << left << setw(7) << tempNode->data.getClientID()
                << "|" << left << setw(7) << tempNode->data.getPrice()
                << "|" << left << setw(7) << tempNode->data.getTime();


            // below: if the status is finished, print a yes. [[NOTE :: if you try to print a boolean, it prints a 1 or 0]]
            if (tempNode->data.getFinished()) { cout << "|" << left << setw(7) << "Yes" << "|"; }
            else { cout << "|" << left << setw(7) << "No" << "|"; }


            cout << left << setw(7) << tempNode->data.getProgress() << "|";

        }
        tempNode = tempNode->nextPtr;


    }

    cout << "\n|=======|=======|=======|=======|=======|=======|=======|";
    cout << "\n^       ^       ^       ^       ^       ^       ^       ^\n\n\n";
}




void linkedCommission::saveFile() {
    ofstream outFile;
    outFile.open("test.txt");
    cout << "\n\n     - - - -  saving - - - - \n\n";
    Node<Commission>* tempNode = headPtr;
    while (tempNode != nullptr) {
        outFile << "commis" << ","
            << tempNode->data.getClientID() << ","
            << tempNode->data.getCommID() << ","
            << tempNode->data.getPriority() << ","
            << tempNode->data.getFinished() << ","
            << tempNode->data.getPrice() << ","
            << tempNode->data.getTime() << ","
            << tempNode->data.getProgress() << "\n";
        tempNode = tempNode->nextPtr;
    }

    cout << "- - - - saved sucessfully~! - - - -\n\n\n";
    outFile.close();
}