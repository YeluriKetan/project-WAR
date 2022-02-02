#include "logic/Logic.h"
#include "ui/UI.h"
#include "string"

using namespace std;

int main() {
    Logic logic;
    init();
    string currInput;
    string prediction = logic.predict();
    printPrediction(prediction);
    while (true) {
        currInput = readInput();
        if (logic.isExit(currInput)) {
            break;
        }
        if (!logic.isValidInput(currInput)) {
            showInvalidInputError();
            continue;
        }
        if (logic.isDone(currInput)) {
            break;
        }
        logic.filter(prediction, currInput);
        prediction = logic.predict();
        if (prediction.empty()) {
            showError("Can't predict! Something wrong...");
        } else {
            printPrediction(prediction);
        }
    }
    close();
    return 0;
}
