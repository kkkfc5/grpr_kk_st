#include "functions.h"




// ==================  general functions  ================== 


void processRawFile(ifstream& inFile, linkedClient& clientList, linkedCommission& commissionList) {

    string inputLine, tempString;
    vector<string> row;

    getline(inFile, inputLine);



    while (inFile) {
        //cout << "\n\n\n\n\n______________________________________\n";
        //cout << "\n   entering new iteration   \n\n\n";

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
            processCommission(row, commissionList);
        }

        getline(inFile, inputLine);
    }// end while



    cout << "\n\n";


   

}



// ==================  client functions  ================== 


void processClient(vector<string> inputLine, linkedClient& clientList) {

    bool goodLine = true;

    // error checks v



    //inputLine[1] string clientName;
    //         |  NO ERROR NEEDS TO BE CHECKED?


    //inputLine[2] int clientID;
    //         |  needs to make sure there isn't the same ID in the linkedlist.
    try {
        int ID = stoi(inputLine[2]);
        if (clientList.hasClientID(ID)) { // if the list already has the client ID, error out.
            goodLine = false;
            cout << "\nERROR IN REPEATED CLIENT ID\n";
        }
        else {
            //cout << "\nall's good, not a repeat of clientID\n";
        }
    }
    catch (logic_error) {
        cout << "\nSTOI ERROR clientID\n";
        goodLine = false;
    }


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
        //cout << "\n\nfor temp client name: " << inputLine[1] << "\n\n";

        // add client to linked list
        clientList.addNode(tempClient);
    }
    else if (!goodLine) {
        cout << "\n\n'Twasn't a good input line.";
    }

    //cout << "\n\n\n   ending iteration";
    //cout << "\n______________________________________\n\n\n\n";
}







// ==================  commission functions  ================== 

void processCommission(vector<string> row , linkedCommission& commissionList) {
    bool goodLine = true;
    
    try {
        int test = stoi(row[1]);
        test = stoi(row[2]);
        test = stoi(row[3]);
    }
    catch (logic_error) {
        cout << "\nSTOI ERROR\n";
        goodLine = false;
    }

    try {
        if (stoi(row[4]) != 1 && stoi(row[4]) != 0) {
            cout << "not 1 or 0" << endl;
            goodLine = false;
        }
    }
    catch (logic_error) {
        cout << "\nSTOI ERROR\n";
        goodLine = false;
    }

    try {
        if (stoi(row[5]) <0) {
            cout << "negative" << endl;
            goodLine = false;
        }
        if (stoi(row[6]) < 0) {
            cout << "negative" << endl;
            goodLine = false;
        }
    }
    catch (logic_error) {
        cout << "\nSTOI ERROR\n";
        goodLine = false;
    }

    try {
        if (stoi(row[7]) < 0 || stoi(row[7]) > 100) {
            cout << "not percentage" << endl;
            goodLine = false;
        }
    }
    catch (logic_error) {
        cout << "\nSTOI ERROR\n";
        goodLine = false;
    }

    if (goodLine) {
        Commission tempComm(stoi(row[1]), stoi(row[2]), stoi(row[3]), stoi(row[4]), stod(row[5]), stod(row[6]), stoi(row[7]));
        //cout << "\n\nCommission ID test: " << row[1] << "\n\n";
        commissionList.addNode(tempComm);
    }
    else if (!goodLine) {
        cout << "\nbad line\n";
    }

}