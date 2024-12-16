#include <bits/stdc++.h>
using namespace std;

// Directions: {dx, dy, cost to rotate to this direction}
const vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}}; // East, South, West, North

struct State {
    int x, y, dir, score;
    bool operator>(const State &other) const {
        return score > other.score;
    }
};

struct HashState {
    size_t operator()(const tuple<int, int, int> &state) const {
        auto &[x, y, dir] = state;
        return hash<int>()(x) ^ hash<int>()(y) ^ hash<int>()(dir);
    }
};

int solveMaze(const vector<string> &maze, int startX, int startY, int endX, int endY) {
    int rows = maze.size(), cols = maze[0].size();

    priority_queue<State, vector<State>, greater<State>> pq;
    unordered_set<tuple<int, int, int>, HashState> visited;

    pq.push({startX, startY, 0, 0}); // Start at (startX, startY) facing East (dir = 0)
    visited.insert({startX, startY, 0});

    while (!pq.empty()) {
        State curr = pq.top();
        pq.pop();

        int x = curr.x, y = curr.y, dir = curr.dir, score = curr.score;

        // If we reach the end tile, return the score
        if (x == endX && y == endY) {
            return score;
        }

        // Move forward in the current direction
        int nx = x + directions[dir].first;
        int ny = y + directions[dir].second;
        if (nx >= 0 && nx < rows && ny >= 0 && ny < cols && maze[nx][ny] != '#') {
            if (visited.find({nx, ny, dir}) == visited.end()) {
                pq.push({nx, ny, dir, score + 1});
                visited.insert({nx, ny, dir});
            }
        }

        // Rotate clockwise and counterclockwise
        for (int i = -1; i <= 1; i += 2) { // -1 for counterclockwise, 1 for clockwise
            int newDir = (dir + i + 4) % 4;
            if (visited.find({x, y, newDir}) == visited.end()) {
                pq.push({x, y, newDir, score + 1000});
                visited.insert({x, y, newDir});
            }
        }
    }

    return -1; // If no path found (should not happen for valid input)
}

int main() {
    vector<string> maze;
    string line;

    // Read the maze from standard input
    while (getline(cin, line)) {
        maze.push_back(line);
    }

    int startX, startY, endX, endY;

    // Find the start (S) and end (E) positions
    for (int i = 0; i < maze.size(); ++i) {
        for (int j = 0; j < maze[i].size(); ++j) {
            if (maze[i][j] == 'S') {
                startX = i;
                startY = j;
            }
            if (maze[i][j] == 'E') {
                endX = i;
                endY = j;
            }
        }
    }

    int result = solveMaze(maze, startX, startY, endX, endY);
    cout << "Lowest score: " << result << endl;

    return 0;
}
