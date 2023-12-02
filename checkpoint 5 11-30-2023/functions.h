#pragma once

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cmath>

#include "Client.h"
#include "linkedClient.h"
#include "linkedCommission.h"


using namespace std;

// ==================  general functions  ================== 
void processRawFile(ifstream& inFile, linkedClient& clientList, linkedCommission& commissionList);
void save(linkedClient& clientList, linkedCommission& commissionList); // purges txt file, the overwrites it.

void menuHeader();
void printMenu(linkedClient& clientList, linkedCommission& commissionList);

// ==================  client functions  ================== 
void processClient(vector<string> inputLine, linkedClient& clientList);

void addClient(linkedClient& clientList);

// ==================  commission functions  ================== 
void processCommission(vector<string> row, linkedCommission& commissionList);



#endif