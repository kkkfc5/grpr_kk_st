#pragma once

#ifndef COMMISSION_H
#define COMMISSION_H

#include<vector>
#include<string>
using namespace std;

class Commission {
private:
	int progress;
	int commID;
	int clientID;
	int priority;
	double price;
	double time;
	bool isFinished;


public:
	Commission();
	Commission(int cl, int co, int prio, bool f, double pri, double t, int prog);

	int getProgress() { return progress; }
	int getCommID() { return commID; }
	int getClientID() { return clientID;}
	int getPriority() { return priority; }
	double getPrice() { return price; }
	double getTime() { return time; }
	bool getFinished() { return isFinished; }


	void setPriority(int x) { priority = x; }
	void setFinished(bool x) { isFinished = x; }


	static int commCount;
	static int activeCommCount;

};




// for static ints at the end, have the constructor +1 them. In the function that sets a commission to finished, -1 from the totalActiveComis int

#endif