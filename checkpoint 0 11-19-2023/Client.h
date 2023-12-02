#pragma once

#ifndef CLIENT_H
#define CLIENT_H

#include "linkedList.h"

#include <vector>
#include <string>

using namespace std;


class Client {
private:
	string clientName;
	int clientID;
	double discount;
	int numActiveComm;
	int numTotalComm;
	vector<int> clientCommissions;

	
public:
	//constructors
	Client();
	Client(string name, int ID, double disc, int active, int total, vector<int> comis);


	string getClientName() { return clientName; }
};



#endif 