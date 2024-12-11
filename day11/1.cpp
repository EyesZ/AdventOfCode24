#include <bits/stdc++.h>
using namespace std;

long long blinking(unordered_map<long long, long long> initial_stones, int blinks) {
    unordered_map<long long, long long> stones = initial_stones;

    for (int i = 0; i < blinks; ++i) {
        unordered_map<long long, long long> next_stones;

        for (const auto& [stone, count] : stones) {
            if (stone == 0) {
                next_stones[1] += count;
            } else {
                string num_str = to_string(stone);
                if (num_str.length() % 2 == 0) {
                    int mid = num_str.length() / 2;
                    int left = stoi(num_str.substr(0, mid));
                    int right = stoi(num_str.substr(mid));
                    next_stones[left] += count;
                    next_stones[right] += count;
                } else {
                    next_stones[stone * 2024] += count;
                }
            }
        }

        stones = next_stones;
    }

    long long total_stones = 0;
    for (const auto& [stone, count] : stones) {
        total_stones += count;
    }

    return total_stones;
}

int main() {

    unordered_map<long long, long long> initial_stones;
    int blinks1 = 25;
    int blinks2 = 75;

    long long stone;
    while (cin >> stone) {
        if (stone == -1) break;
        initial_stones[stone]++;
    }

    long long result1 = blinking(initial_stones, blinks1);
    long long result2 = blinking(initial_stones, blinks2);

    cout << blinks1 << " @ " << result1 << endl;
    cout << blinks2 << " @ " << result2 << endl;

    return 0;
}
