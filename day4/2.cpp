#include <bits/stdc++.h>
using namespace std;

bool isXMAS(const vector<string>& grid, int row, int col) {
    int rows = grid.size();
    int cols = grid[0].size();

    // Offsets for the X-MAS pattern
    /*   TL  TR
     *     C
     *   BL  BR 
    */
    pair<int, int> topLeft = {-1, -1};
    pair<int, int> topRight = {-1, 1};
    pair<int, int> center = {0, 0};
    pair<int, int> bottomLeft = {1, -1};
    pair<int, int> bottomRight = {1, 1};

    // andrew tate fuming again
    for (auto [dr, dc] : {topLeft, topRight, center, bottomLeft, bottomRight}) {
        int r = row + dr, c = col + dc;
        if (r < 0 || r >= rows || c < 0 || c >= cols) {
            return false;
        }
    }

    // get each char from the X
    char tl = grid[row + topLeft.first][col + topLeft.second];          
    char tr = grid[row + topRight.first][col + topRight.second];        
    char ctr = grid[row + center.first][col + center.second];           
    char bl = grid[row + bottomLeft.first][col + bottomLeft.second];    
    char br = grid[row + bottomRight.first][col + bottomRight.second];  

    // Check for mas and sam
    bool diagonal1 = ((tl == 'M' && ctr == 'A' && br == 'S') || // MAS
                      (tl == 'S' && ctr == 'A' && br == 'M'));  // SAM

    bool diagonal2 = ((tr == 'M' && ctr == 'A' && bl == 'S') || // MAS
                      (tr == 'S' && ctr == 'A' && bl == 'M'));  // SAM

    return diagonal1 && diagonal2;
}

int countOccurrences(const vector<string>& grid) {
    int count = 0;
    int rows = grid.size();
    int cols = grid[0].size();

    for (int row = 1; row < rows - 1; ++row) {
        for (int col = 1; col < cols - 1; ++col) {
            if (isXMAS(grid, row, col)) {
                count++;
            }
        }
    }

    return count;
}

int main() {
    vector<string> grid;
    string l;

    while (getline(cin, l)) {
        if (!line.empty()) {
            grid.push_back(l);
        }
    }
    int sum = countOccurrences(grid);
    cout << "Total X-MAS occurrences: " << sum << endl;

    return 0;
}