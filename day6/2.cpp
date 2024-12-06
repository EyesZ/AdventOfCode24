#include <bits/stdc++.h>
using namespace std;

const vector<pair<int, int>> directions = {{0, -1}, {1, 0}, {0, 1}, {-1, 0}};

pair<int, int> turnRight(pair<int, int> dir) {
    if (dir == directions[0]) return directions[1]; // Up -> Right
    if (dir == directions[1]) return directions[2]; // Right -> Down
    if (dir == directions[2]) return directions[3]; // Down -> Left
    return directions[0];                           // Left -> Up
}

tuple<vector<string>, pair<int, int>, pair<int, int>> parseMap(const vector<string>& map) {
    vector<string> grid = map;
    pair<int, int> startPos;
    pair<int, int> startDir;

    for (int y = 0; y < grid.size(); ++y) {
        for (int x = 0; x < grid[y].size(); ++x) {
            char cell = grid[y][x];
            if (cell == '^') {
                startPos = {x, y};
                startDir = directions[0];
                grid[y][x] = '.';
            } else if (cell == '>') {
                startPos = {x, y};
                startDir = directions[1];
                grid[y][x] = '.';
            } else if (cell == 'v') {
                startPos = {x, y};
                startDir = directions[2];
                grid[y][x] = '.';
            } else if (cell == '<') {
                startPos = {x, y};
                startDir = directions[3];
                grid[y][x] = '.';
            }
        }
    }

    return {grid, startPos, startDir};
}

bool moveGuard(const vector<string>& grid, pair<int, int> startPos, pair<int, int> startDir) {
    set<tuple<int, int, pair<int, int>>> visited;
    pair<int, int> pos = startPos;
    pair<int, int> dir = startDir;

    while (true) {
        if (visited.count({pos.first, pos.second, dir})) {
            return true; 
        }
        visited.insert({pos.first, pos.second, dir});

        int nextX = pos.first + dir.first;
        int nextY = pos.second + dir.second;

        if (nextX < 0 || nextX >= grid[0].size() || nextY < 0 || nextY >= grid.size()) {
            break; 
        }

        if (grid[nextY][nextX] == '#') {
            dir = turnRight(dir);
        } else {
            pos = {nextX, nextY};
        }
    }

    return false;
}

int findObstructionPositions(vector<string> map) {
    auto [grid, startPos, startDir] = parseMap(map);
    int loopPositions = 0;

    for (int y = 0; y < grid.size(); ++y) {
        // had to print this cuz 2 min run time
        // silly me very efficient code :3 
        // cout << "y: " << y << endl;
        for (int x = 0; x < grid[y].size(); ++x) {
            if (grid[y][x] == '.' && make_pair(x, y) != startPos) {
                grid[y][x] = '#';

                if (moveGuard(grid, startPos, startDir)) {
                    ++loopPositions;
                }
                grid[y][x] = '.';
            }
        }
    }

    return loopPositions;
}

int main() {
    vector<string> map;
    string line;

    while (getline(cin, line) && !line.empty()) {
        map.push_back(line);
    }
    int result = findObstructionPositions(map);
    cout << result << endl;

    return 0;
}