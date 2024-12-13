#include <bits/stdc++.h>
using namespace std;

struct Machine {
    int ax, ay;
    int bx, by;
    int px, py; 
};

int calc(const Machine& machine) {
    int minTokens = INT_MAX;

    for (int aPresses = 0; aPresses <= 100; aPresses++) {
        for (int bPresses = 0; bPresses <= 100; bPresses++) {
            int totalX = aPresses * machine.ax + bPresses * machine.bx;
            int totalY = aPresses * machine.ay + bPresses * machine.by;

            if (totalX == machine.px && totalY == machine.py) {
                int cost = aPresses * 3 + bPresses * 1;
                minTokens = min(minTokens, cost);
            }
        }
    }

    if (minTokens == INT_MAX) {
        return -1;
    }

    return minTokens;
}

int main() {
    vector<Machine> machines;
    string line;

    while (getline(cin, line)) {
        Machine machine;
        string inputA = line;
        sscanf(inputA.c_str(), "Button A: X+%d, Y+%d", &machine.ax, &machine.ay);

        getline(cin, line);
        string inputB = line;
        sscanf(inputB.c_str(), "Button B: X+%d, Y+%d", &machine.bx, &machine.by);

        getline(cin, line);
        string inputPrize = line;
        sscanf(inputPrize.c_str(), "Prize: X=%d, Y=%d", &machine.px, &machine.py);

        machines.push_back(machine);
        getline(cin, line);
    }

    int totalTokens = 0;

    for (const auto& machine : machines) {
        int tokens = calc(machine);
        if (tokens != -1) {
            totalTokens += tokens;
        }
    }

    cout << totalTokens << endl;

    return 0;
}
