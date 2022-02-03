#ifndef PROJECTWAR_LOGIC_H
#define PROJECTWAR_LOGIC_H
#include "string"
#include "vector"
#include "ui/UI.h"

using namespace std;

class Logic {
    string FILE_NAME = "../lib/words.txt";
    string EXIT = "q";
    string DONE = "GGGGG";
    vector<int> currState;
    int numOfPredictions;

public:
    vector<string> WORDS;
    Logic();
    bool isExit(string input);
    bool isValidInput(string input);
    bool isDone(string input);
    void filter(string prevPrediction, string predicate);
    void reset();
    string predict();
};


#endif //PROJECTWAR_LOGIC_H
