#include "Logic.h"
#include "UI.h"
#include "string"

using namespace std;

int main() {
    Logic logic;
    init();
    string currInput;
    while (true) {
        currInput = readInput();
        if (logic.isExit(currInput)) {
            break;
        }
        if (!logic.isValidInput(currInput)) {
            showInvalidInputError();
            continue;
        }
    }
    close();
    return 0;
}
