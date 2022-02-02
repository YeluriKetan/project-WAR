#include "Adversary.h"
#include "string"

using namespace std;

string Adversary::checker(string input) {
    string correctWordCopy = CORRECT_WORD;
    string output = ".....";
    for (int i = 0; i < 5; ++i) { // first mark all greens and remove the letters
        if (input[i] == correctWordCopy[i]) {
            output[i] = 'G';
            correctWordCopy[i] = 0;
            input[i] = 0;
        }
    }
    for (int i = 0; i < 5; ++i) {
        int pos;
        if (input[i] != 0) {
            pos = correctWordCopy.find(input[i]);
            if (pos == string::npos) { // if letter doesn't exist anywhere B
                output[i] = 'B';
            } else { // if the letter exists somewhere, Y
                output[i] = 'Y';
                correctWordCopy[pos] = 0;
            }
        }
    }
    return output;
}