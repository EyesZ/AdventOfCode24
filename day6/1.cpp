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

int moveGuard(const vector<string>& grid, pair<int, int> startPos, pair<int, int> startDir) {
    set<pair<int, int>> visited;
    pair<int, int> pos = startPos;
    pair<int, int> dir = startDir;

    visited.insert(pos);

    int maxX = grid[0].size();
    int maxY = grid.size();

    while (true) {
        int nextX = pos.first + dir.first;
        int nextY = pos.second + dir.second;

        if (nextX < 0 || nextX >= maxX || nextY < 0 || nextY >= maxY) {
            break; 
        }

        if (grid[nextY][nextX] == '#') {
            dir = turnRight(dir);
        } else {
            pos = {nextX, nextY};
            visited.insert(pos);
        }
    }

    return visited.size();
}

int guardPatrol(const vector<string>& map) {
    auto [grid, startPos, startDir] = parseMap(map);
    return moveGuard(grid, startPos, startDir);
}

int main() {
    vector<string> map;
    string line;

    while (getline(cin, line) && !line.empty()) {
        map.push_back(line);
    }
    int result = guardPatrol(map);
    cout << result << endl;

    return 0;
}