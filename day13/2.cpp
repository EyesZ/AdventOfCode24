#include <bits/stdc++.h>
using namespace std;

struct Machine {
    int ax, ay;
    int bx, by;
    int px, py; 
};


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

    uint64_t answer_2 = 0;

    for (const auto& machine : machines) {
        
        double a1 = machine.ax;
        double a2 = machine.ay;
        double b1 = machine.bx;
        double b2 = machine.by;
        double c1 = machine.px;
        double c2 = machine.py;
        double c1_2 = machine.px + 10000000000000;
        double c2_2 = machine.py + 10000000000000;

        double x_2 = (-c2_2 * b1 + c1_2 * b2) / (a1 * b2 - a2 * b1);
        double y_2 = (c2_2 - x_2 * a2) / b2;

        if(floor(x_2) == x_2 && floor(y_2) == y_2) {
            answer_2 += x_2 * 3 + y_2;
        }

    }

    std::cout << answer_2 << "\n";

    return 0;
}