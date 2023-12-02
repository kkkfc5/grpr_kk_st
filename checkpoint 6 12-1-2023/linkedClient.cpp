#include "linkedClient.h"


bool linkedClient::hasClientID(int searchID) {
    if (headPtr == nullptr) {
        return false;
    }
    else {
        //cout << "            (entered else)\n";
        Node<Client>* tempPtr = headPtr;
        while (tempPtr != nullptr) {
            //cout << "== checking ID of: " << tempPtr->data.getClientName() << "\n";
            if (tempPtr->data.getClientID() == searchID) {
                return true;
            }
            else {
                tempPtr = tempPtr->nextPtr;
            }
        }// end while
        return false;
    }
}



void linkedClient::addCommission(int clientID, int comisID) {
    if (headPtr != nullptr) { // if the linked list isn't empty
        Node<Client>* tempPtr = headPtr; 
        while (tempPtr != nullptr) { 
            if (tempPtr->data.getClientID() == clientID) { // if there is a clientID in the list that matches the clientID being searched for
                tempPtr->data.addNewCommission(comisID); // add the commissionID to the Client's list of active commissions
                break; // no need to check the rest of the list, there can only be one clientID
            }
            else { // else, continue the search
                tempPtr = tempPtr->nextPtr;
            }
        }
    }
}


void linkedClient::delCommission(int comisID) {
    Node<Client>* tempPtr = headPtr;
    vector<int> tempVect;

    while (tempPtr != nullptr) {
        tempVect.clear();
        for (int i = 0; i < tempPtr->data.getClientCommissions().size(); i++) { // for every extra cmmission in the vector
            //cout << "- " << i << "\n";
            if (tempPtr->data.getClientCommissions()[i] != comisID) { // if the ID != the one to delete, add it to a vector.
                tempVect.push_back(tempPtr->data.getClientCommissions()[i]); // very roundabout way of doing it but I couldn't get below code to work.
            }
            
            //if (tempPtr->data.getClientCommissions()[i] == comisID) {
                //tempPtr->data.getClientCommissions().erase(tempPtr->data.getClientCommissions().begin()+(i-1)); // odd way of listing it, but theres some sort of error between int i and what it needs to take
            //}
        }
        tempPtr->data.setClientComm(tempVect); // assign the vector without the specified ID onto the object
        tempPtr = tempPtr->nextPtr;
    }
}






void linkedClient::incrementTotComm(int clientID) {
    if (headPtr != nullptr) { // if the linked list isn't empty
        Node<Client>* tempPtr = headPtr;
        while (tempPtr != nullptr) {
            if (tempPtr->data.getClientID() == clientID) { // if there is a clientID in the list that matches the clientID being searched for
                tempPtr->data.incTotComm();
                break; // no need to check the rest of the list, there can only be one clientID
            }
            else { // else, continue the search
                tempPtr = tempPtr->nextPtr;
            }
        }
    }
}







void linkedClient::print() {
    if (headPtr == nullptr) {
        cout << "The list is empty\n";
    }
    else {
        Node<Client>* tempPtr = headPtr;
        cout << "v_______________v_______v_______v_______v_______v________________________________________________vVv\n";
        cout << "|Client Name    |Clie.ID|Discou.|Act.Com|Tot.Com|Active Commissions' IDs:                        |||\n";
        cout << "|---------------|-------|-------|-------|-------|------------------------------------------------UUU\n";
        while (tempPtr != nullptr) {
            //cout << tempPtr->data.fname << " " << tempPtr->data.lname << endl; // << -- will error out (we only need prints for commissions, no?)
            //cout << "########## " << tempPtr->data.getClientName() << "\n";
            
            cout << "|" << left << setw(15) << tempPtr->data.getClientName()
                << "|" << right << setw(4) << setfill('0') << tempPtr->data.getClientID() << setfill(' ') << "   "
                << "|" << left << setw(7) << tempPtr->data.getDiscount()
                << "|" << left << setw(7) << tempPtr->data.getNumActiveComm()
                << "|" << left << setw(7) << tempPtr->data.getNumTotalComm() << "| ";
            
            
            for (auto i : tempPtr->data.getClientCommissions()) {
                cout << setw(4) << right << setfill('0') << i << " | ";
            }
            cout << "\n" << setfill (' ');
            //cout << "|______|______|______|______|______|______|\n";
            cout << "|===============================================| ~~~~ + ~~~~ + ~~~~ + ~~~~ + ~~~~ + ~~~~ + ~~~~ +\n";
            //cout << "|---------------|-------|-------|-------|-------|\n";
            
            tempPtr = tempPtr->nextPtr;
        }
    }
}




void linkedClient::saveFile() {
    ofstream outFile("test.txt", ios::app);

    Node<Client>* tempNode = headPtr;
    while (tempNode != nullptr) {
        outFile << "client,"
            << tempNode->data.getClientName() << ","
            << tempNode->data.getClientID() << ","
            << tempNode->data.getDiscount() << ","
            << tempNode->data.getNumActiveComm() << ","
            << tempNode->data.getNumTotalComm();

        for (int i = 0; i < tempNode->data.getClientCommissions().size(); i++) {
            outFile << "," << tempNode->data.getClientCommissions()[i];
        }

        /*
        for (auto i : tempNode->data.getClientCommissions()) { // add a variable amount of commissions to the line.
            outFile << "," << i; // the comma is before the i, because we dont want to end the line with a comma. ((though i suppose that doesnt quite matter, hm?))
        }
        */
        outFile << "\n";

        tempNode = tempNode->nextPtr;
    }
        outFile.close();
    
}

bool linkedClient::hasCommisID(int clientID, int searchID) {
    if (headPtr == nullptr) { return false; }

    Node<Client>* tempNode = headPtr;
    bool hasComis = false;

    while (tempNode != nullptr) {
        if (tempNode->data.getClientID() == clientID) { // if the client is the one we are searching for
            for (int i = 0; i < tempNode->data.getClientCommissions().size(); i++) { // for every value in the vector of comis IDs
                if (tempNode->data.getClientCommissions()[i] == searchID) { hasComis = true; break; } // set the flag to true if it is equal to the search ID
            }
            if (hasComis) { return true; } // if it has the commission
        }
        tempNode = tempNode->nextPtr;
    }
    if (!hasComis) { return false; }
}


void linkedClient::updateActiveCommissions() {
    if (headPtr == nullptr) { return; }

    Node<Client>* tempNode = headPtr;
    while (tempNode != nullptr) {
        tempNode->data.setNumActiveComm(tempNode->data.getClientCommissions().size()); // set the num of active commissions to be the size of the vector holding the active commissions
        tempNode = tempNode->nextPtr;
    }

}