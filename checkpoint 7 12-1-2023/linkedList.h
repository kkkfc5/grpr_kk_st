#pragma once

#ifndef LINKEDLIST_H
#define LINKEDLIST_H


#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
using namespace std;



// NOTE :: THIS FILE IS THE TEMPLATE FILE. 





template<typename D>
struct Node {
	D data;
	Node* nextPtr = nullptr;
};




template<typename D>
class Linked {
protected:
    Node<D>* headPtr;
    Node<D>* tailPtr;

public:
    Linked();
    ~Linked();
    virtual void addNode(D d);
    void printList();
};





// NOTE :: TEMPLATE DEFINITIONS NEED TO BE IN THE SAME FILE AS THE TEMPLATE CLASS




template<typename D>
Linked<D>::Linked() {
    //cout << "Constructor called\n";
    headPtr = nullptr;
    tailPtr = nullptr;
}


template<typename D>
Linked<D>::~Linked() {
    //cout << "Destructor called\n";
    //Destructor will loop through the list and delete each node
    Node<D>* tempPtr = headPtr;
    Node<D>* delPtr = tempPtr;
    while (tempPtr != nullptr) {
        //cout << headPtr << " : " << tailPtr << "\n"; // ======================================
        //cout << "you killed: " << tempPtr->data.fname << " " << tempPtr->data.lname << endl;   << -- WILL ERROR OUT BC OUT CLASSES DONT HAVE THOSE FIELDS
       // cout << "you deleted something\n";
        
        //if (tempPtr->nextPtr != nullptr) {
        //    cout << "\n" << "tempptr->nextptr :  " << tempPtr->nextPtr << "\n";
        //}

        //cout << tempPtr->data.getClientName() << "\n\n"; // ================================
        tempPtr = tempPtr->nextPtr;
        delete delPtr;
        delPtr = tempPtr;
    }
    headPtr = nullptr;
    tailPtr = nullptr;
}



template<typename D>
void Linked<D>::addNode(D d) {
    //Create a new node (set data & pointer values)
    Node<D>* newNode = new Node<D>;
    newNode->data = d;

    //if the list is empty, set head & tail pointers to new node
    if (headPtr == nullptr) {
        headPtr = newNode;
        tailPtr = newNode;
    }
    //else add node to the end
    else {
        tailPtr->nextPtr = newNode;
        tailPtr = newNode;
        newNode->nextPtr = nullptr;
    }
}






// ====================================== NOTE :: 
// BELOW CAN BE THE TEMPLATE FOR SORTING
//   |  however, thing to note is that we only sort the different commissions
//        |  the only way we sort the clients is separating via clientID, and comis class has that field so only commissions will have sort functions
/*
template<typename D>
void Linked<D>::addNodeOrdered(D d) {
    //Create a new node (set data & pointer values)
    Node<D>* newNode = new Node<D>;
    newNode->data = d;
    newNode->nextPtr = nullptr;
    //check for empty list
    if (headPtr == nullptr) {
        headPtr = newNode;
        tailPtr = newNode;
    }
    //check to see if newNode goes before headPtr
    // if so adjust headptr
    else if (newNode->data.lname < headPtr->data.lname) {
        newNode->nextPtr = headPtr;
        headPtr = newNode;
    }
    else {
        //loop through to find where to insert new node
        Node<D>* tempPtr = headPtr;
        while (tempPtr->nextPtr != nullptr && tempPtr->nextPtr->data.lname < newNode->data.lname) { // << -- THIS WILL ERROR BECAUSE FNAME/LNAME FIELDS DONT EXIST 
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
*/






// NOTE :: we are only deleting the commissions; clients aren't ever deleted. 
//           |  thus, what is below needs to be added not to the template, but to the comis class.
//                |  (have to remove the template part, and replace the D parts to be the comis class type)
/*
template<typename D>
void Linked<D>::delNode(string key) {
    //start at the headPtr and loop until you find key or get to the end of the list
    Node<D>* tempPtr = headPtr;
    Node<D>* delPtr;
    //condition 1: delete data at headptr
    if (tempPtr != nullptr &&
        tempPtr->data.lname == key) { // << --  WILL ERROR OUT ====================================================
        delPtr = tempPtr;
        headPtr = tempPtr->nextPtr;
        delete delPtr;
        delPtr = nullptr;
        return;
    }
    //condition 2: delete a value in the middle of the list
    else {
        while (tempPtr != nullptr &&
            tempPtr->nextPtr != nullptr) {
            if (tempPtr->nextPtr->data.lname == key) { // << -- WILL ERROR OUT, COMIS DOESNT HAVE lname FIELD ================================
                delPtr = tempPtr->nextPtr;
                tempPtr->nextPtr = tempPtr->nextPtr->nextPtr;
                //condition 3: delete value at the end of the list
                if (tempPtr->nextPtr == nullptr)
                    tailPtr = tempPtr;
                delete delPtr;
                delPtr = nullptr;
                return;
            }
            tempPtr = tempPtr->nextPtr;
        }
    }
}
*/




// NOTE :: we can have two different print statements. 
//          |  print function for commissions allows for the sorting of the data. 
//          |  print function for client will print just the one specific client's info, or print the name of all clients.

template<typename D>
void Linked<D>::printList() {
    //start at the headPtr and loop - printing data from each node
    //condition: if headPtr is null, print "List is empty"
    if (headPtr == nullptr) {
        cout << "The list is empty\n";
    }
    else {
        Node<D>* tempPtr = headPtr;
        while (tempPtr != nullptr) {
            //cout << tempPtr->data.fname << " " << tempPtr->data.lname << endl; // << -- will error out (we only need prints for commissions, no?)
            //cout << "########## " << tempPtr->data.getClientName() << "\n";
            cout << "########## " << tempPtr->data.getCommID() << "\n";
            tempPtr = tempPtr->nextPtr;
        }
    }
}













#endif 











/*
template<typename D>
class vectors {
    if (D == "int") { int intArray[]; }
    else if (D == "double") { double dbleArray[]; }
    else if (D == "string") { string strArray[]; }
    else {
        // .....
    }
};

vectors<int> vectOne;
vectors<double> vectTwo;
vectors<string> vectThree;

*/