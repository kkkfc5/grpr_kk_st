#include "functions.h"




// ==================  general functions  ================== 


void processRawFile(ifstream& inFile, Linked<Client> clientList) {

    string inputLine, tempString;
    vector<string> row;

    getline(inFile, inputLine);



    while (inFile) {
        row.clear();

        stringstream inSS(inputLine);

        while (getline(inSS, tempString, ',')) { // adds each element of the input line to a vector
            row.push_back(tempString);
        }


        if (row[0] == "client") {
            // KENNETH CODES THIS, IT WILL BE USED IN PROCESSING THE DATA
            processClient(row, clientList);
        }
        else if (row[0] == "commis") {
            // SYLVIA CODES THIS
            // processCommission();
        }

        getline(inFile, inputLine);
    }// end while



    cout << "\n\n";





}



// ==================  client functions  ================== 


void processClient(vector<string> inputLine, Linked<Client> clientList) {

    bool goodLine = true;

    // error checks v



    //inputLine[1] string clientName;
    //         |  NO ERROR NEEDS TO BE CHECKED?


    //inputLine[2] int clientID;
    //         |  needs to make sure there isn't the same ID in the linkedlist.
    


    //inputLine[3] double discount;
    //         |  can't be less than 0.00, more than 1.00.
    try {
        if (stod(inputLine[3]) < 0.00 || stod(inputLine[3]) > 1.00) {
            goodLine = false;
        }
    }
    catch (logic_error) {
        cout << "\nSTOI ERROR DISCOUNT\n";
        goodLine = false;
    }


    //inputLine[4] int numActiveComm;
    //         |  can't be less than 0
    try {
        if (stoi(inputLine[4]) < 0) {
            cout << "\nERROR: numActiveComis < 0\n";
            goodLine = false;
        }
    }
    catch (logic_error) {
        cout << "\nSTOI ERROR numActiveComis\n";
        goodLine = false;
    }


    //inputLine[5] int numTotalComm;
    //         |  can't be less than active comis
    try {
        if (stoi(inputLine[4]) > stoi(inputLine[5])) { // if numActive is greater than numTotal
            cout << "\nERROR: numTotalComis < 0\n";
            goodLine = false;
        }
    }
    catch (logic_error) {
        cout << "\nSTOI ERROR numTotalComis (and/or num active comis)\n";
        goodLine = false;
    }


    //inputLine[6+] vector<int> clientCommissions;
    //         |  check stoi
    //         |  checks if ID is already added
    vector<int> tempIDs;
    for (int i = 6; i < inputLine.size(); i++) { // starts at 6 because we've already checked the first 5 elements of the vector
        // for the rest of the elements in the inputLine vector (the active commissionsID)
        try {
            for (int j = 0; j < tempIDs.size(); i++) { // checks if the comisID you're about to add is already in the vector (prevents repeats)
                if (tempIDs[j] != stoi(inputLine[i])) { 
                    tempIDs.push_back(stoi(inputLine[i])); // if comisID isn't in vector already, then add it
                }
            }
        }
        catch (logic_error) {
            cout << "\nSTOI ERROR COMMISSION IDs\n";
            goodLine = false;
        }
    }



    // error checks ^



    if (goodLine) {
        // create client using input line
        Client tempClient(inputLine[1], stoi(inputLine[2]), stod(inputLine[3]), stoi(inputLine[4]), stoi(inputLine[5]), tempIDs);
        cout << "\n\nfor temp client name: " << inputLine[1] << "\n\n";

        // add client to linked list
        clientList.addNode(tempClient);
    }
    else if (!goodLine) {
        cout << "\n\n'Twasn't a good input line.";
    }
}







// ==================  commission functions  ================== 