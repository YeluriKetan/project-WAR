#include "UI.h"
#include "iostream"

using namespace std;

void init() {
    cout << "Project WAR\n";
}

string readInput() {
    string input;
    cin >> input;
    return input;
}

void showInvalidInputError() {
    cerr << "Invalid Input encountered. Try again!\n";
}

void showFileErrorAndExit() {
    cerr << "Unable to open file\n";
    exit(EXIT_FAILURE);
}

void close() {
    cout << "Goodbye\n";
}