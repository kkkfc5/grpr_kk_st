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

using namespace std;

// ==================  general functions  ================== 
void processRawFile(ifstream& inFile, Linked<Client> clientList);



// ==================  client functions  ================== 
void processClient(vector<string> inputLine, Linked<Client> clientList);



// ==================  commission functions  ================== 



#endif