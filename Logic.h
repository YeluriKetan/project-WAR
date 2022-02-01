#ifndef PROJECTWAR_LOGIC_H
#define PROJECTWAR_LOGIC_H
#include "string"
#include "vector"
#include "UI.h"

using namespace std;

class Logic {
    string FILE_NAME = "../words.txt";
    string EXIT = "q";
    vector<string> WORDS;
public:
    Logic();
    bool isExit(string input);
    bool isValidInput(string input);
};


#endif //PROJECTWAR_LOGIC_H
