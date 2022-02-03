#include "logic/Logic.h"
#include "ui/UI.h"
#include "string"
#include "test/Adversary.h"
#include "map"
#include "chrono"
#include "fstream"

using namespace std;
using namespace std::chrono;

int testWord(Adversary &adversary, Logic &logic, string word, ofstream &outfile) {
    adversary.CORRECT_WORD = word;
    string prediction;
    string result;
    int count = 0;
    while (true) {
        prediction = logic.predict();
        outfile << prediction;
        count++;
        if (prediction.empty()) {
            cerr << word << " emtpy prediction\n";
            return -1;
        }
        result = adversary.checker(prediction);
        if (logic.isDone(result)) {
            break;
        }
        outfile << ",";
        logic.filter(prediction, result);
    }
    outfile << "\n";
    return count;
}

int main() {
    Adversary adversary;
    Logic logic;
    map<int, int> countTracker;
    ofstream outfile;
    outfile.open("../lib/output.txt", ios::out | ios::trunc);
    int ans;
    auto start = high_resolution_clock::now();
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    long long totalTime = 0;
    for (string currWord: logic.WORDS) {
        start = high_resolution_clock::now();
        ans = testWord(adversary, logic, currWord, outfile);
        stop = high_resolution_clock::now();
        duration = duration_cast<microseconds>(stop - start);
        totalTime += duration.count();
        countTracker[ans]++;
        logic.reset();
    }
    outfile.close();
    double total = 0;
    cout << "Distribution:\n";
    for (pair<int, int> currPair: countTracker) {
        total += currPair.first * currPair.second;
        cout << currPair.first << " " << currPair.second << "\n";
    }
    cout << "Average no. of predictions required: " << total/2315 << endl;
    cout << "Average time taken to solve: " << totalTime/2315 << " microseconds" << endl;
    return 0;
}
