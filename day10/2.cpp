#include <bits/stdc++.h>
using namespace std;

struct Point {
    int x, y;
    bool operator<(const Point& other) const {
        return tie(x, y) < tie(other.x, other.y);
    }
};

const vector<Point> dirs = {
    {0, 1},
    {1, 0}, 
    {0, -1}, 
    {-1, 0}
};

bool isValid(int x, int y, const vector<string>& map) {
    return x >= 0 && y >= 0 && x < map.size() && y < map[0].size();
}

int countDiff(int x, int y, const vector<string>& map, set<Point>& visited, set<Point>& path) {
    int curHeight = map[x][y] - '0';
    
    if (curHeight == 9) {
        return 1;
    }

    int count = 0;
    for (const auto& dir : dirs) {
        int newX = x + dir.x;
        int newY = y + dir.y;

        if (isValid(newX, newY, map)) {
            int nextHeight = map[newX][newY] - '0';
            Point neighbour = {newX, newY};

            if (nextHeight == curHeight + 1 && path.find(neighbour) == path.end()) {
                path.insert(neighbour); 
                count += countDiff(newX, newY, map, visited, path);
                path.erase(neighbour); 
            }
        }
    }

    return count;
}

int rate(int startX, int startY, const vector<string>& map) {
    set<Point> visited;
    set<Point> path;
    path.insert({startX, startY});
    return countDiff(startX, startY, map, visited, path);
}

int calcIsShortForCalculator(const vector<string>& map) {
    int sum = 0;

    for (int i = 0; i < map.size(); ++i) {
        for (int j = 0; j < map[0].size(); ++j) {
            if (map[i][j] == '0') { // if 0 start counting
                sum += rate(i, j, map);
            }
        }
    }

    return sum;
}

int main() {
    vector<string> map;
    string line;

    while (getline(cin, line)) {
        map.push_back(line);
    }

    int sum = calcIsShortForCalculator(map);

    cout << sum << endl;

    return 0;
}