//============================================================================
// Name        : Lab2-2.cpp
// Author      : Gavin Walters
// Authored    : 22 January, 2018
// Subject	   : Week 2 up to speed
// Version     : 1.0
// Copyright   : Copyright © 2017 SNHU COCE
// Description : Lab 2-2 Up to Speed in C++, Part 2
//============================================================================

#include <algorithm>
#include <iostream>
#include <time.h>

/*
 * Included the CSVparser library or header file so that its resources could be used.
 */
#include "CSVparser.hpp"


using namespace std;

//============================================================================
// Global definitions visible to all methods and classes
//============================================================================

// forward declarations
double strToDouble(string str, char ch);

struct Bid {
    string title;
    string fund;
    double amount;
    Bid() {
        amount = 0.0;
    }
};

//============================================================================
// Static methods used for testing
//============================================================================

/**
 * Display the bid information
 *
 * @param bid struct containing the bid info
 */
void displayBid(Bid bid) {
    cout << bid.title << " | " << bid.amount << " | " << bid.fund << endl;
    return;
}

/**
 * Prompt user for bid information
 *
 * @return Bid struct containing the bid info
 */
Bid getBid() {
    Bid bid;

    cout << "Enter title: ";
    cin.ignore();
    getline(cin, bid.title);

    cout << "Enter fund: ";
    cin >> bid.fund;

    cout << "Enter amount: ";
    cin.ignore();
    string strAmount;
    getline(cin, strAmount);
    bid.amount = strToDouble(strAmount, '$');

    return bid;
}

/**
 * Load a CSV file containing bids into a container
 *
 * @param csvPath the path to the CSV file to load
 * @return a container holding all the bids read
 */
vector<csv::Row> loadBids(string csvPath) {
	// FIXME (2): Define a vector data structure to hold a collection of bids.

    // initialize the CSV Parser using the given path
    csv::Parser file = csv::Parser(csvPath);

    // FIX (2): Created a vector to store a collection of bids as row types.
    vector<csv::Row> collectionOfBids;

	// loop to read rows of a CSV file
	for (unsigned int i = 0; i < file.rowCount(); i++) {
        // FIXME (3): create a data structure to hold data from each row and add to vector
		// Fix (3): Used the previously declared vector collectionOfBids to get rows pushed on as elements.
		// Using at(i) = file.getRow(i) was problematic.
		 collectionOfBids.push_back(file.getRow(i));
    }
    return collectionOfBids;
}

/**
 * Simple C function to convert a string to a double
 * after stripping out unwanted char
 *
 * credit: http://stackoverflow.com/a/24875936
 *
 * @param ch The character to strip out
 */
double strToDouble(string str, char ch) {
    str.erase(remove(str.begin(), str.end(), ch), str.end());
    return atof(str.c_str());
}

/**
 * The one and only main() method
 */
int main(int argc, char* argv[]) {

    // process command line arguments
    string csvPath;
    switch (argc) {
    case 2:
        csvPath = argv[1];
        break;
    default:
        csvPath = "src/eBid_Monthly_Sales.csv";
    }

    // FIXME (4): Define a vector to hold all the bids
    // FIX (4):Declared another vector of rows to store the bids being collected in the loadBids function.
    vector<csv::Row> storedBids;

    // FIXME (7a): Define a timer variable
    // FIX (7a): Declared a timer 1 and 2 to calculate difference in times.
    clock_t t1, t2;
    float time_diff;

    int choice = 0;
    while (choice != 9) {
        cout << "Menu:" << endl;
        cout << "  1. Enter a Bid" << endl;
        cout << "  2. Load Bids" << endl;
        cout << "  3. Display All Bids" << endl;
        cout << "  9. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
        	cout << "Not currently implemented." << endl;

            break;
        case 2:
            // FIXME (7b): Initialize a timer variable before loading bids
        	// Start time
        	cout << endl;
        	t1 = clock();

            // FIXME (5): Complete the method call to load the bids
        	storedBids = loadBids(csvPath);

            // FIXME (7c): Calculate elapsed time and display result
        	// End time
        	t2 = clock();
        	// Calc difference in times and display.
        	cout << endl << "time elapsed: " << (time_diff = t2 - t1)/1000000 << endl;

            break;
        case 3:
            // FIXME (6): Loop and display the bids read
        	// Used this loop to run though each element, displaying the contents of each row stored there.
            for (int i = 0; i < storedBids.size(); ++i) {
            		cout << storedBids.at(i) << endl;
            }
            cout << endl;

            break;
        }
    }

    cout << "Good bye." << endl;

    return 0;
}
