#include <bits/stdc++.h>
using namespace std;

struct Region {
    char type;
    int area;
    int perimeter;
};

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

bool isValid(int x, int y, int rows, int cols) {
    return x >= 0 && x < rows && y >= 0 && y < cols;
}

Region bfs(const vector<string>& map, vector<vector<bool>>& visited, int startX, int startY) {
    char type = map[startX][startY];
    queue<pair<int, int>> q;
    q.push({startX, startY});
    visited[startX][startY] = true;

    int area = 0;
    int perimeter = 0;

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        area++;

        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (!isValid(nx, ny, map.size(), map[0].size()) || map[nx][ny] != type) {
                perimeter++;
            } else if (!visited[nx][ny]) {
                visited[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }

    return {type, area, perimeter};
}

int main() {
    vector<string> map;
    string line;

    while (getline(cin, line)) {
        map.push_back(line);
    }

    int rows = map.size();
    int cols = map[0].size();
    vector<vector<bool>> visited(rows, vector<bool>(cols, false));

    unordered_map<char, vector<Region>> blobs;

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (!visited[i][j]) {
                Region blob = bfs(map, visited, i, j);
                blobs[blob.type].push_back(blob);
            }
        }
    }

    int sum = 0;
    for (const auto& entry : blobs) {
        for (const Region& blob : entry.second) {
            sum += blob.area * blob.perimeter;
        }
    }

    cout << sum << endl;
    return 0;
}