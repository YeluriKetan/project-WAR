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
    showError("Unable to open file");
}

void showError(string input) {
    cerr << input << "\n";
    exit(EXIT_FAILURE);
}

void printPrediction(string prediction) {
    cout << prediction << "\n";
}

void close() {
    cout << "Goodbye\n";
}