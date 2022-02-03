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
    int count = 0;
    while (file >> currString) {
        WORDS.push_back(currString);
        currState.push_back(count++);
    }
    numOfPredictions = 0;
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

bool Logic::isDone(string input) {
    return DONE == input;
}

bool matches(string word, string prevPrediction, string predicate) {
    for (int i = 0; i < 5; ++i) {
        if (predicate[i] != 'G') { // if not G, continue
            continue;
        }
        if (prevPrediction[i] != word[i]) { // if G, letter has to match
            return false; // else false
        }
        word[i] = 0; // replace with blank
    }
    for (int i = 0; i < 5; ++i) {
        if (predicate[i] != 'Y') { // if not Y, continue
            continue;
        }
        if (word[i] == prevPrediction[i]) {
            return false;
        }
        int pos = word.find(prevPrediction[i]);
        if (pos == string::npos) { // if it exists anywhere, its ok
            return false;
        } else {
            if (predicate[pos] == 'B' && prevPrediction[pos] == prevPrediction[i]) {
                return false;
            }
            word[pos] = 0;
        }
    }
    for (int i = 0; i < 5; ++i) {
        if (predicate[i] != 'B') { // if not B, continue
            continue;
        }
        if (word.find(prevPrediction[i]) != string::npos) { // if B, letter shouldn't exist
            return false; // else false
        }
    }
    return true;
}

void Logic::filter(string prevPrediction, string predicate) {
    vector<int> nextState;
    for (int i = 0; i < currState.size(); ++i) {
        if (matches(WORDS[currState[i]], prevPrediction, predicate)) { // filtering
            nextState.push_back(currState[i]);
        }
    }
    currState = nextState;
}

void Logic::reset() {
    currState.clear();
    for (int i = 0; i < 2315; ++i) {
        currState.push_back(i);
    }
    numOfPredictions = 0;
}

string Logic::predict() {
    if (currState.empty()) {
        return "";
    } else if (currState.size() < 11) {
        return WORDS[currState[currState.size() / 2]];
    } else {
        switch (numOfPredictions) {
            case 0:
                numOfPredictions++;
                return "salet";
            case 1:
                numOfPredictions++;
                return "corni";
            case 2:
                numOfPredictions++;
                return "dumpy";
            default:
                numOfPredictions++;
                return WORDS[currState[currState.size() / 2]];
        }
    }
}