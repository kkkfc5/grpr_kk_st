#pragma once
#ifndef LINKEDCLIENT_H
#define LINKEDCLIENT_H

#include "linkedList.h"
#include "Client.h"


class linkedClient : public Linked<Client> {
public:
    // searches list for specified clientID. returns true if found.
    bool hasClientID(int searchID);
    bool hasCommisID(int clientID, int searchID);

    //void calculateDiscount(linkedCommission& commissionList); // calculates discount based on how many commissions are ordered and/or how much is spent
    
    void addCommission(int clientID, int comisID); // adds a commission ID to the array holding commissions
    void delCommission(int comisID);
    void incrementTotComm(int clientID);

    void print();
    void updateActiveCommissions();
    void saveFile();
};




#endif // !LINKEDCLIENT_H


