#include "Logic.h"
#include "string"
#include "fstream"

using namespace std;

Logic::Logic() {
    ifstream file(FILE_NAME);
    if (!file.is_open()) {
        showFileErrorAndExit();
    }
    string currString;
    while (file >> currString) {
        WORDS.push_back(currString);
    }
}

bool Logic::isExit(string input) {
    return EXIT == input;
}

bool Logic::isValidInput(string input) {
    if (input.size() != 5) {
        return false;
    }
    for (char curr: input) {
        if (!(curr == 'B' || curr == 'G' || curr == 'Y')) {
            return false;
        }
    }
    return true;
}

