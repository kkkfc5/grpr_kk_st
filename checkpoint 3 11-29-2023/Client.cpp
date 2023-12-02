#include "Client.h"

Client::Client() {
	clientName = "ERROR";
	clientID = -1;
	discount = -1.00;
	numActiveComm = -1;
}


Client::Client(string name, int ID, double disc, int active, int total, vector<int> comis) {
	clientName = name;
	clientID = ID;
	discount = disc;
	numActiveComm = active;
	numTotalComm = total;

	for (int i = 0; i < comis.size(); i++) { clientCommissions[i] = comis[i]; }
}


