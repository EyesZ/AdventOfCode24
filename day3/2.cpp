#include <bits/stdc++.h>
using namespace std;

int main() {

    string zzzz;
    getline(cin, zzzz);

    // copilot broken regex :3 silly me dont want to learn regex
    // Updated regex pattern to match mul(X, Y) and instructions like do() and don't()
    regex pattern(R"(mul\((\d+),(\d+)\)|do\(\)|don't\(\))");
    smatch match;
    int sum = 0;
    bool mula = true; 

    // first time using this tbh dont really care if its slow, geeksforgeeks ftw
    auto begin = sregex_iterator(zzzz.begin(), zzzz.end(), pattern);
    auto end = sregex_iterator();

    for (sregex_iterator i = begin; i != end; i++) {
        match = *i;

        if (match[1].matched && match[2].matched) {
            if (mula) {
                int x = stoi(match[1].str());
                int y = stoi(match[2].str());
                sum += x * y;  
            }
        }
        else if (match.str() == "do()") {
            mula = true;  
        }
        else if (match.str() == "don't()") {
            mula = false;  
        }
    }

    cout << "Total Sum: " << sum << endl;

    return 0;
}