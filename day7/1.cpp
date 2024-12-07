#include <bits/stdc++.h>
using namespace std;

long long evaal(const vector<long long>& nums, const vector<char>& op) {
    long long result = nums[0];
    for (size_t i = 0; i < op.size(); ++i) {
        if (op[i] == '+') {
            result += nums[i + 1];
        } else if (op[i] == '*') {
            result *= nums[i + 1];
        }
    }
    return result;
}

long long zzzz(const string& input) {
    long long total = 0;
    istringstream input(input);
    string line;

    while (getline(input, line)) {
        if (line.empty()) {
            continue;
        }

        size_t colonPos = line.find(": ");
        long long target = stoll(line.substr(0, colonPos));
        vector<long long> numbers;

        istringstream numbersStream(line.substr(colonPos + 2));
        long long num;
        while (numbersStream >> num) {
            numbers.push_back(num);
        }

        size_t numOperators = numbers.size() - 1;
        bool possible = false;

        vector<char> operators(numOperators);
        function<void(size_t)> funinfun = [&](size_t pos) {
            if (pos == numOperators) {
                if (evaal(numbers, operators) == target) {
                    possible = true;
                }
                return;
            }
            operators[pos] = '+';
            funinfun(pos + 1);
            operators[pos] = '*';
            funinfun(pos + 1);
        };

        funinfun(0);

        if (possible) {
            total += target;
        }
    }

    return total;
}

int main() {
    string input, line;
    while (getline(cin, line)) {
        input += line + "\n";
    }

    long long result = zzzz(input);
    cout << result << endl;

    return 0;
}