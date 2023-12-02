#pragma once

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

#include "Client.h"
#include "linkedClient.h"

using namespace std;

// ==================  general functions  ================== 
void processRawFile(ifstream& inFile, linkedClient& clientList);



// ==================  client functions  ================== 
void processClient(vector<string> inputLine, linkedClient& clientList);



// ==================  commission functions  ================== 



#endif