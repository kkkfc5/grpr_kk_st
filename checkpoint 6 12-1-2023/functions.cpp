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
            processCommission(row, commissionList, clientList);
        }

        getline(inFile, inputLine);
    }// end while



    cout << "\n\n";


}






void save(linkedClient& clientList, linkedCommission& commissionList) {
    ofstream outFile("test.txt");
    outFile.close(); // PURGES TEXT FILE

    commissionList.saveFile();
    clientList.saveFile();
}




void menuHeader() {
    cout << "Please enter a choice.\n"
        << "(A)dd client\n"
        << "(C)reate new commission\n"
        << "(D)elete commisson\n"
        << "(P)rint\n"
        << "(S)ave\n"
        << "(Q)uit\n";
}



void printMenu(linkedClient& clientList, linkedCommission& commissionList) {
    char choiceYN;
    string sort = "\0", filter = "\0";

    bool good = false;
    bool quick = true;

    cout << "\n\nDo you want to print the list of commissions? (Y/N)\t[D for Default | Q to Quit]\n";
    cin >> choiceYN;
    if (toupper(choiceYN) == 'Y' || toupper(choiceYN) == 'N') { good = true; }
    else if (toupper(choiceYN) == 'Q') { cout << "\n\nQuiting . . . \n\n\n"; return; } // if user wants to quit, end the function.
    else if (toupper(choiceYN) == 'D') { good = true; quick = true; }


    while (!good && toupper(choiceYN) != 'D') {
        cout << "Poor input. Try again.\n";
        cin >> choiceYN;
        if (toupper(choiceYN) == 'Y' || toupper(choiceYN) == 'N') { good = true; }
        else if (toupper(choiceYN) == 'Q') { cout << "\n\nQuiting . . . \n\n\n"; return; } // if user wants to quit, end the function.
        else if (toupper(choiceYN) == 'D') { good = true; quick = true; }
    }

    good = false; // reset flag

    if (toupper(choiceYN) == 'Y') {

        cout << "\n\nWould you like to sort by priority or price?\t\t[Q to Quit]\n"
            << "(1) Priority\n"// the options are 0 and 1 for .. reasons. 
            << "(0) Price\n"; //  2.) opposite ends of keyboard means minimal chance of miss-entry 

        cin >> sort;
        if (sort == "0" || sort == "1") { good = true; }
        else if (toupper(sort[0]) == 'Q') { cout << "\n\nQuiting . . . \n\n\n"; return; } // if user wants to quit, end the function.


        while (!good) {
            cout << "Poor input. Try again.\n";
            cin >> sort;
            if (sort == "0" || sort == "1") { good = true; }
            else if (toupper(sort[0]) == 'Q') { cout << "\n\nQuiting . . . \n\n\n"; return; } // if user wants to quit, end the function.

        }

        good = false; // reset flag

        // - - - - - - - - - - - - - - - - - - - 

        cout << "\n\nWould you like to filter out the finished commissions?\t\t[Q to Quit]\n"
            << "(Y)es\n"
            << "(N)o\n";

        cin >> filter;
        if (toupper(filter[0]) == 'Y' || toupper(filter[0]) == 'N') { good = true; }
        else if (toupper(filter[0]) == 'Q') { cout << "\n\nQuiting . . . \n\n\n"; return; } // if user wants to quit, end the function.


        while (!good) {
            cout << "Poor input. Try again.\n";
            cin >> filter;
            if (filter == "0" || filter == "1") { good = true; }
            else if (toupper(filter[0]) == 'Q') { cout << "\n\nQuiting . . . \n\n\n"; return; } // if user wants to quit, end the function.

        }

        good = false; // reset flag

    } // end if
    else if (toupper(choiceYN) == 'D') {
        sort = "0";
        filter = 'n';
    }


    // ===========================================================================
    // ===========================================================================


    cout << "\n\nDo you want to print the client list? (Y/N)\t\t[Q to Quit]\t\t\n";
    cin >> choiceYN;
    if (toupper(choiceYN) == 'Y' || toupper(choiceYN) == 'N') { good = true; }
    else if (toupper(choiceYN) == 'Q') { cout << "\n\nQuiting . . . \n\n\n"; return; } // if user wants to quit, end the function.


    while (!good) {

        cout << "Poor input. Try again.\n";
        cin >> choiceYN;
        if (toupper(choiceYN) == 'Y' || toupper(choiceYN) == 'N') { good = true; }
        else if (toupper(choiceYN) == 'Q') { cout << "\n\nQuiting . . . \n\n\n"; return; } // if user wants to quit, end the function.

    }
    good = false; // reset flag

    cout << "\n\n\n\n";

    /*
    if (sort == "1" && toupper(filter[0]) == 'N') { commissionList.sortPriority('n'); }
    else if (sort == "1" && toupper(filter[0]) == 'Y') { commissionList.sortPriority('y'); }
    else if (sort == "0" && filter == "0") { commissionList.sortPrice('n'); }
    else if (sort == "0" && filter == "1") { commissionList.sortPrice('y'); }
    */

    if (sort == "1") { commissionList.sortPriority(filter[0]); }
    else if (sort == "0") { commissionList.sortPriority(filter[0]); }


    // ===========================================================================
    // ===========================================================================


    if (toupper(choiceYN) == 'Y') { clientList.print(); }

    cout << "\n\n\n\n";
}


void update(linkedClient& clientList, linkedCommission& commissionList) {
    clientList.updateActiveCommissions();
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
            cout << "\nERROR: numTotalComis < numActiveComis\n";
            goodLine = false;
        }
    }
    catch (logic_error) {
        cout << "\nSTOI ERROR numTotalComis (and/or num active comis)\n";
        goodLine = false;
    }

    //cout << "\n";
    //for (int i = 0; i < inputLine.size(); i++) {
    //    cout << i << "=";
    //} cout << "\n";
    //cout << inputLine.size() <<  "\n\n";

    //inputLine[6+] vector<int> clientCommissions;
    //         |  check stoi
    //         |  checks if ID is already added
    vector<int> tempIDs;
    bool notFound = true;
    for (int i = 6; i < inputLine.size() ; i++) { // starts at 6 because we've already checked the first 5 elements of the vector
        //cout << "(" << i << " : " << inputLine.size() << ")  --  ";
        //cout << "[[[[[[[[[[[]]]]]]]]]]]]  " << inputLine[i] << "\n";

        // for the rest of the elements in the inputLine vector (the active commissionsID)
        try {
            if (i > 6) { // if on second loop. This is necessary because otherwise, tempID is empty and thus doesnt run, so inputline[6] must be pushed on.
                for (int j = 0; j < tempIDs.size(); j++) { // checks if the comisID you're about to add is already in the vector (prevents repeats)
                    //cout << inputLine[i] << "++== \n";
                    //cout << tempIDs[j] << "+++== " << j << "|" << tempIDs.size() << "\n";
                    if (tempIDs[j] == stoi(inputLine[i])) {
                        notFound = false;
                    }

                } // end for

                if (notFound) {
                    tempIDs.push_back(stoi(inputLine[i])); // if comisID isn't in vector already, then add it
                    //cout << inputLine[i] << " : (not found)\n";
                }
            } // end if inputline size
            else { // else if the 6th element
                tempIDs.push_back(stoi(inputLine[i]));
                //cout << inputLine[i] << " : \n";
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
        Client tempClient(inputLine[1], stoi(inputLine[2]), stod(inputLine[3]), tempIDs.size(), stoi(inputLine[5]), tempIDs);
        //cout << "\n\nfor temp client name: " << inputLine[1] << "\n\n";

        // add client to linked list
        clientList.addNode(tempClient);
    }
    else if (!goodLine) {
        cout << "\n\n'Twasn't a good input line.\n_________________________\n";
    }

    //cout << "\n\n\n   ending iteration";
    //cout << "\n______________________________________\n\n\n\n";
}


void addClient(linkedClient& clientList) {



    // - - - - - - - - CLIENT-ID CHECKS - - - - - - - - 
    // - - - - - - - - v v v v v v v v  - - - - - - - - 

    char choiceYN;
    bool good = false;
    string input;
    int clientID;


    cout << "\n\nDo you know what the client ID should be? (Y/N)\t\t[Q to Quit]\n";

    cin >> choiceYN;
    if (toupper(choiceYN) == 'Y' || toupper(choiceYN) == 'N') { good = true; }
    else if (toupper(choiceYN) == 'Q') { cout << "\n\nQuiting . . . \n\n\n"; return; } // if user wants to quit, end the function.

    while (!good) {
        cout << "Poor input. Try again.\n";
        cin >> choiceYN;
        if (toupper(choiceYN) == 'Y' || toupper(choiceYN) == 'N') { good = true; }
        else if (toupper(choiceYN) == 'Q') { cout << "\n\nQuiting . . . \n\n\n"; return; } // if user wants to quit, end the function.

    }

    good = false; // resetting flag

    if (toupper(choiceYN) == 'Y') {

        while (!good) {

            try {
                cout << "\n\nWhat will the client ID be?\t\t[Q to Quit]\n";
                cin >> input;
                if (toupper(input[0]) == 'Q') { cout << "\n\nQuiting . . . \n\n\n"; return; }
                clientID = stoi(input);// if it isn't numeric, it'll throw an error

                if (clientID < 0 || clientID > 10000) { cout << "Poor input. Try again.\n"; }// if not 4 digits and positive, error out
                else if (clientList.hasClientID(clientID)) { cout << "Poor input. Try again.\n"; }// if client id exists already, error out
                else { good = true; }

            }
            catch (...) { cout << "Poor input. Try again.\n"; }// catches stoi error

        } // end while

        good = false; // reset flag

    }
    else { // else if the user doesnt know what client ID to add
        while (!good) {
            clientID = rand() % 10000; // random number 0-9999
            //cout << "clinet id:  : ::   : : :: " << clientID << "\n\n\n";

            if (!clientList.hasClientID(clientID)) { good = true; } // if the clientID doesnt exist in the list, then break the while loop
        }

        good = false; // reset the flag
    }

    // - - - - - - - - ^ ^ ^ ^ ^ ^ ^ ^  - - - - - - - - 
    // - - - - - - - - CLIENT-ID CHECKS - - - - - - - - 
    // ================================================
    // - - - - - - - CLIENT NAME CHECKS - - - - - - - - 
    // - - - - - - - v v v v v v v v v  - - - - - - - -

    char trash;
    string name;

    trash = cin.get();  // there is a '\0' char in the input buffer, so we need to remove that before we getline

    cout << "\n\nWhat is the client's name?\n";
    getline(cin, name);
    //cout << "||" << name << "\n";


    // - - - - - - - - ^ ^ ^ ^ ^ ^ ^ ^  - - - - - - - - 
    // - - - - - - - CLIENT NAME CHECKS - - - - - - - - 
    // ================================================
    // - - - - - - CLIENT DISCOUNT CHECKS - - - - - - - 
    // - - - - - - - v v v v v v v v v  - - - - - - - -


    double discount;

    while (!good) {
        try {
            cout << "\n\nWhat is the client's discount percentage? (only input an integer)\t\t[Q to Quit]\n";
            cin >> input;
            if (toupper(input[0]) == 'Q') { cout << "\n\nQuiting . . . \n\n\n"; return; }

            discount = stod(input);
            //cout << "||" << discount << "\n";

            if (discount <= 1 && discount > 0) { good = true; } // if discount is inputted as 0.xx and positive
            else if (discount <= 100 && discount >= 0) { good = true; discount /= 100; } // if percent is inputted in form  xx%, then divide it by 100 to be of form 0.xx
            else { cout << "Poor input. Try again.\n"; }
        }
        catch (...) { cout << "Poor input. Try again.\n"; }// catches stod error
    } // end while
    good = false; // resetting flag



    // - - - - - - - - ^ ^ ^ ^ ^ ^ ^ ^  - - - - - - - - 
    // - - - - - - CLIENT DISCOUNT CHECKS - - - - - - - 
    // ================================================


    vector<int> placeholder;

    Client tempClient(name, clientID, discount, 0, 0, placeholder);

    clientList.addNode(tempClient);

    cout << "\n\n[Client: " << tempClient.getClientName() << " added successfully]\n\n";

}







// ==================  commission functions  ================== 

void processCommission(vector<string> row , linkedCommission& commissionList, linkedClient& clientList) {
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
        clientList.addCommission(stoi(row[2]), stoi(row[3]));
    }
    else if (!goodLine) {
        cout << "\n\n'Twasn't a good input line.\n_________________________\n";

    }

}












void addCommission(linkedClient& clientList, linkedCommission& commissionList) {
    bool good = false;
    string input;




    // ==========================
    //    checks for price
    //    v v v v v v v v 
    
    double price;

    while (!good) {
        try {
            cout << "\n\nWhat is the price of the commission? \t\t[Q to Quit]\n";
            cin >> input;
            if (toupper(input[0]) == 'Q') { cout << "\n\nQuiting . . . \n\n\n"; return; } // if user wants to quit, end the function.
            else if (stod(input) >= 0) { good = true; price = stod(input); }
            else { cout << "Poor input. Try again.\n"; }

        }
        catch (...) { cout << "Poor input. Try again.\n"; }
    }

    good = false; // reset flag

    //    ^ ^ ^ ^ ^ ^ ^ ^ 
    //    checks for price
    // ==========================
    //    checks for priority
    //    v v v v v v v v v v
    
    int priority;

    while (!good) {
        try {
            cout << "\n\nWhat is the priority of the commission? \t\t[Q to Quit]\n";
            cin >> input;
            if (toupper(input[0]) == 'Q') { cout << "\n\nQuiting . . . \n\n\n"; return; } // if user wants to quit, end the function.
            else if (stoi(input) >= 0 && stoi(input) <= 10) { good = true; priority = stoi(input); }
            else { cout << "Poor input. Try again.\n"; }
        }
        catch (...) { cout << "Poor input. Try again.\n"; }
    }
    good = false; // reset flag

    //    ^ ^ ^ ^ ^ ^ ^ ^ 
    //    checks for priority
    // ==========================







    // need to know what clientid to add it to (final). [if want to print the name, we'll need to have a search func for clientid that returns a pointer to a client?_
    int clientID;
    char choiceYN;

    cout << "\n\nDo you know the client ID? (Y/N)\t\t[Q to Quit]\n";
    cin >> choiceYN;
    if (toupper(choiceYN) == 'Q') { cout << "\n\nQuiting . . . \n\n\n"; return; } // if user wants to quit, end the function.
    else if (toupper(choiceYN) == 'N') { clientList.print(); }
    else if (toupper(choiceYN) == 'Y') {
        
        while (!good) {

            try {
                cout << "\nPlease enter the clientID.\t\t[Q to Quit]\n";
                cin >> input;
                if (toupper(input[0]) == 'Q') { cout << "\n\nQuiting . . . \n\n\n"; return; } // if user wants to quit, end the function.
                
                clientID = stoi(input);



                if (clientID >= 0 && clientID <= 9999) {
                    if (!clientList.hasClientID(clientID)) { cout << "Invalid ID.\n"; }
                    else { good = true; break; }
                }
                else { cout << "Poor input. Try again.\n"; }
            }

            catch (...) { cout << "Poor input. Try again.\n"; }
        }

    }

    // flag isnt reset so that the bottom code wont run if above code runs.

    while (!good) {
        
        try {
            cout << "\n\nWhat is client ID you want to add the commission to?\t\t[Q to Quit]\n";
            cin >> input;
            if (toupper(input[0]) == 'Q') { cout << "\n\nQuiting . . . \n\n\n"; return; } // if user wants to quit, end the function.
            else {
                clientID = stoi(input);
                if (!clientList.hasClientID(clientID)) { cout << "ID doesn't exist. Try again.\n"; }
                else if (clientID >= 0 && clientID <= 9999) { good = true; }
            }
        }
        catch (...) { cout << "Poor input. Try again.\n"; }

    } // end while

    good = false; // flad reset.
    





    int commisID;



    cout << "\n\nDo you know what the commission ID should be? (Y/N)\t\t[Q to Quit]\n";

    cin >> choiceYN;
    if (toupper(choiceYN) == 'Y' || toupper(choiceYN) == 'N') { good = true; }
    else if (toupper(choiceYN) == 'Q') { cout << "\n\nQuiting . . . \n\n\n"; return; } // if user wants to quit, end the function.

    while (!good) {
        cout << "Poor input. Try again.\n";
        cin >> choiceYN;
        if (toupper(choiceYN) == 'Y' || toupper(choiceYN) == 'N') { good = true; }
        else if (toupper(choiceYN) == 'Q') { cout << "\n\nQuiting . . . \n\n\n"; return; } // if user wants to quit, end the function.

    }

    good = false; // resetting flag

    if (toupper(choiceYN) == 'Y') {

        while (!good) {

            try {
                cout << "\n\nWhat will the commission ID be?\t\t[Q to Quit]\n";
                cin >> input;
                if (toupper(input[0]) == 'Q') { cout << "\n\nQuiting . . . \n\n\n"; return; }
                commisID = stoi(input);// if it isn't numeric, it'll throw an error

                if (commisID < 0 || commisID > 10000) { cout << "Poor input. Try again.\n"; }// if not 4 digits and positive, error out
                else if (clientList.hasClientID(commisID)) { cout << "Poor input. Try again.\n"; }// if client id exists already, error out
                else { good = true; }
            }
            catch (...) { cout << "Poor input. Try again.\n"; }// catches stoi error

        } // end while

        good = false; // reset flag

    }
    else { // else if the user doesnt know what commission ID to add
        while (!good) {
            commisID = rand() % 10000; // random number 0-9999
            if (!clientList.hasCommisID(clientID, commisID)) { good = true; } // if the clientID doesnt exist in the list, then break the while loop
        }

        good = false; // reset the flag
    }


    
    clientList.addCommission(clientID, commisID);
    clientList.updateActiveCommissions();
    clientList.incrementTotComm(clientID);

    Commission tempComm(clientID, commisID, priority, false, price, 0, 0);
    commissionList.addNode(tempComm);

    cout << "\n\n";
    clientList.print();
    cout << "\n\n";
}




void deleteCommission(linkedClient& clientList, linkedCommission& commissionList) {
    // call update and delNode, and also remove it from the clientList
    // print menu asking what the client id is that you want to delete

    cout << "\n\n";

    commissionList.printPrice('n');

    clientList.print();

    bool good = false;
    string input;
    int comisID;

    while (!good) {
        try {
            cout << "\n\nWhat is the ID of the commission you would like to delete?\t\t[Q to Quit]\n";
            cin >> input;
            if (toupper(input[0]) == 'Q') { cout << "\n\nQuiting . . . \n\n\n"; return; } // if user wants to quit, end the function.
            else if (stoi(input) < 0 || stoi(input) > 9999) { cout << "Poor input. Try again.\n"; }
            else if (commissionList.hasCommissionID(stoi(input)) == true) { // if commission exists in commission list
                // delete protocol :
                commissionList.delNode(stoi(input));

                commissionList.printPrice('n'); // testing

                //remove from client list and update
                clientList.delCommission(stoi(input));
                clientList.updateActiveCommissions();

                clientList.print();

                cout << "\n\n";


                good = true;
            }
            else { cout << "ID not found. Try again.\n"; }
        }
        catch (...) { cout << "Poor input. Try again.\n"; }

    }// end while
}