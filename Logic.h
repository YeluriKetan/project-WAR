#ifndef PROJECTWAR_LOGIC_H
#define PROJECTWAR_LOGIC_H
#include "string"
#include "vector"
#include "UI.h"

using namespace std;

class Logic {
    string FILE_NAME = "../words.txt";
    string EXIT = "q";
    string DONE = "GGGGG";
    vector<string> WORDS;
    vector<int> currState;

public:
    Logic();
    bool isExit(string input);
    bool isValidInput(string input);
    bool isDone(string input);
    void filter(string prevPrediction, string predicate);
    string predict();
};


#endif //PROJECTWAR_LOGIC_H
