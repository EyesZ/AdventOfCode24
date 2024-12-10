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

int score(int startX, int startY, const vector<string>& map) {
    queue<Point> q;                
    set<Point> visited;            
    set<Point> endPoints;     

    q.push({startX, startY});
    visited.insert({startX, startY});

    while (!q.empty()) {
        Point cur = q.front();
        q.pop();

        int curHeight = map[cur.x][cur.y] - '0';

        if (curHeight == 9) {
            endPoints.insert(cur);
        }

        for (const auto& dir : dirs) {
            int newX = cur.x + dir.x;
            int newY = cur.y + dir.y;

            if (isValid(newX, newY, map)) {
                int newHeight = map[newX][newY] - '0';
                Point neighbour = {newX, newY};

                if (newHeight == curHeight + 1 && visited.find(neighbour) == visited.end()) {
                    q.push(neighbour);
                    visited.insert(neighbour);
                }
            }
        }
    }

    return endPoints.size();
}

int calcIsShortForCalculator(const vector<string>& map) {
    int sum = 0;

    for (int i = 0; i < map.size(); ++i) {
        for (int j = 0; j < map[0].size(); ++j) {
            if (map[i][j] == '0') { // if 0 start counting
                sum += score(i, j, map);
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