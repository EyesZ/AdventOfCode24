#include <bits/stdc++.h>
using namespace std;


// Function to determine if a design is possible using available towel patterns
bool isPossible(const string& design, const unordered_set<string>& patterns) {
    int n = design.size();
    vector<bool> dp(n + 1, false); 
    dp[0] = true; 

    for (int i = 1; i <= n; ++i) {
        for (const string& pattern : patterns) {
            int len = pattern.size();
            if (i >= len && dp[i - len] && design.substr(i - len, len) == pattern) {
                dp[i] = true;
                break;
            }
        }
    }

    return dp[n];
}

int main() {
    // Read input
    string line;
    getline(cin, line);

    unordered_set<string> patterns;
    size_t pos = 0;
    while ((pos = line.find(", ")) != string::npos) {
        patterns.insert(line.substr(0, pos));
        line.erase(0, pos + 2);
    }
    patterns.insert(line); 


    vector<string> designs;
    getline(cin, line);
    while (getline(cin, line) && !line.empty()) {
        designs.push_back(line);
    }

    int possibleCount = 0;
    for (const string& design : designs) {
        if (isPossible(design, patterns)) {
            ++possibleCount;
        }
    }

    // Output the result
    cout << possibleCount << endl;

    return 0;
}
