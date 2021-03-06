#ifndef PROJECTWAR_UI_H
#define PROJECTWAR_UI_H
#include "string"
#include "iostream"

using namespace std;

void init();
string readInput();
void showInvalidInputError();
void showFileErrorAndExit();
void showError(string input);
void printPrediction(string prediction);
void close();

#endif //PROJECTWAR_UI_H
