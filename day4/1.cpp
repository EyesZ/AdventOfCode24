#include <bits/stdc++.h>
using namespace std;

int countOccurrences(const vector<string>& grid, const string& word) {
    int count = 0;
    int rows = grid.size();
    int cols = grid[0].size();
    int wordLength = word.length();

    vector<pair<int, int>> directions = {
        {0, 1},  {0, -1},  // sides
        {1, 0},  {-1, 0},  // up and down
        {1, 1},  {-1, -1}, // diagonal 
        {1, -1}, {-1, 1}   // diagonal
    };

    for (int row = 0; row < rows; ++row) {
        for (int col = 0; col < cols; ++col) {
            for (const auto& dir : directions) {
                int r = row, c = col;
                int i;
                for (i = 0; i < wordLength; ++i) {
                    // don't escape the matrix andrew tate fuming rn
                    if (r < 0 || r >= rows || c < 0 || c >= cols || grid[r][c] != word[i]) {
                        break;
                    }
                    // if inside advance
                    r += dir.first;
                    c += dir.second;
                }
                // xmas found
                if (i == wordLength) {
                    count++;
                }
            }
        }
    }
    return count;
}

int main() {
    vector<string> grid;
    string word = "XMAS";
    string l;

    while (getline(cin, l)) {
        if (!l.empty()) {
            grid.push_back(l);
        }
    }
    int sum = countOccurrences(grid, word);
    cout << "Total occurrences of " << word << ": " << sum << endl;

    return 0;
}