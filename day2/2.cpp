#include <bits/stdc++.h>
using namespace std;

bool isSafeReport(const vector<int>& levels) {
    bool inc = true, dec = true;

    for (int i = 1; i < levels.size(); ++i) {
        int diff = levels[i] - levels[i - 1];
        if (diff > 0) dec = false;
        if (diff < 0) inc = false;
        
        if (abs(diff) < 1 || abs(diff) > 3) {
            return false;
        }

    }

    return inc || dec;
}

bool isSafeWithDampener(const vector<int>& levels) {
    if (isSafeReport(levels)) {
        return true; 
    }
    // check all cuz edge cases too hard to think about hehe
    for (size_t i = 0; i < levels.size(); ++i) {
        vector<int> zzz = levels;
        zzz.erase(zzz.begin() + i); 

        if (isSafeReport(zzz)) {
            return true;
        }
    }

    return false; 
}

int main() {

    string l;
    vector<vector<int>> reports;

    // :3
    while (getline(cin, l)) {

        istringstream stream(l);
        vector<int> report;
        int level;

        while (stream >> level) {
            report.push_back(level);
        }

        reports.push_back(report);
        
    }

    int safeCount = 0;
    for (const auto& report : reports) {
        if (isSafeWithDampener(report)) {
            safeCount++;
        }
    }

    cout << safeCount << endl;

    return 0;
}