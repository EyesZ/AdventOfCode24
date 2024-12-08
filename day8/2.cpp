#include <bits/stdc++.h>
using namespace std;


struct Antenna {
    int x, y; 
    char frequency;  
};

bool isWithinBounds(int x, int y, int width, int height) {
    return x >= 0 && x < height && y >= 0 && y < width;
}

void addLineAntinodes(set<pair<int, int>> &antinodes, const Antenna &a, const Antenna &b, int width, int height) {
    int dx = b.x - a.x;
    int dy = b.y - a.y;
    // guess i should have paid more attention math class
    // its better than brute forcing the whole thing
    int gcd = abs(__gcd(dx, dy));
    dx /= gcd;
    dy /= gcd;

    int x = a.x, y = a.y;
    while (isWithinBounds(x, y, width, height)) {
        antinodes.insert({x, y});
        x += dx;
        y += dy;
    }

    x = a.x - dx;
    y = a.y - dy;
    while (isWithinBounds(x, y, width, height)) {
        antinodes.insert({x, y});
        x -= dx;
        y -= dy;
    }
}

int main() {
    vector<string> map;
    string line;

    while (getline(cin, line)) {
        if (!line.empty()) {
            map.push_back(line);
        }
    }

    int height = map.size();
    int width = map[0].size();

    // get all antennas by frequency
    unordered_map<char, vector<Antenna>> frequencyMap;
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            if (isalnum(map[i][j])) {
                frequencyMap[map[i][j]].push_back({i, j, map[i][j]});
            }
        }
    }
    // answer
    set<pair<int, int>> antinodes;
    // not sure how this is fast but it is
    for (const auto &entry : frequencyMap) {
        const auto &antennas = entry.second;
        for (size_t i = 0; i < antennas.size(); ++i) {
            for (size_t j = i + 1; j < antennas.size(); ++j) {
                addLineAntinodes(antinodes, antennas[i], antennas[j], width, height);
            }
        }
    }

    cout <<  "AAAAAAAAAA : " << antinodes.size() << endl;

    return 0;
}