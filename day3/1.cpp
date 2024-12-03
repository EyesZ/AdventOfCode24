#include <bits/stdc++.h>
using namespace std;

int main() {
    
    string zzzz;
    getline(cin, zzzz);

    // copilot broken regex :3 silly me dont want to learn regex
    regex pattern(R"(mul\((\d+),(\d+)\))");
    smatch match;
    int sum = 0;

    // first time using this tbh dont really care if its slow, geeksforgeeks ftw
    auto begin = sregex_iterator(zzzz.begin(), zzzz.end(), pattern);
    auto end = sregex_iterator();

    for (sregex_iterator i = begin; i != end; i++) {
        match = *i;
       
        int x = stoi(match[1].str());
        int y = stoi(match[2].str());
        
        sum += x * y;
    }

    
    cout << "Total Sum: " << sum << endl;

    return 0;
}