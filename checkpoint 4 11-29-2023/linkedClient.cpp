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








void linkedClient::print() {
    if (headPtr == nullptr) {
        cout << "The list is empty\n";
    }
    else {
        Node<Client>* tempPtr = headPtr;
        cout << "v_______________v_______v_______v_______v_______v\n";
        cout << "|Client Name    |Clie.ID|Discou.|Act.Com|Tot.Com|\n";
        cout << "|---------------|-------|-------|-------|-------|\n";
        while (tempPtr != nullptr) {
            //cout << tempPtr->data.fname << " " << tempPtr->data.lname << endl; // << -- will error out (we only need prints for commissions, no?)
            //cout << "########## " << tempPtr->data.getClientName() << "\n";
            
            cout << "|" << left << setw(15) << tempPtr->data.getClientName()
                << "|" << left << setw(7) << tempPtr->data.getClientID()
                << "|" << left << setw(7) << tempPtr->data.getDiscount()
                << "|" << left << setw(7) << tempPtr->data.getNumActiveComm()
                << "|" << left << setw(7) << tempPtr->data.getNumTotalComm() << "|\n";
            cout << "|---------------|-------|-------|-------|-------|\n";
            cout << "|Active Commissions:                     \\ \n";
            cout << "|______|______|______|______|______|______|\n";


            for (auto i : tempPtr->data.getClientCommissions()) {
                cout << "| " << setw(4) << setfill('0') << i << " ";
            }
            cout << "\n";
            cout << "|______|______|______|______|______|______|\n";
            cout << "|============================================|\n";
            cout << "|---------------|-------|-------|-------|-------|\n";

            tempPtr = tempPtr->nextPtr;
        }
    }
}




void linkedClient::saveFile() {
    ofstream outFile("test.txt");

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