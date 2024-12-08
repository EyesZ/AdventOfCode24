#include <bits/stdc++.h>
using namespace std;


struct Antenna {
    int x, y;  
    char frequency;
};

bool isWithinBounds(int x, int y, int width, int height) {
    return x >= 0 && x < height && y >= 0 && y < width;
}

void findAntinodes(const vector<Antenna>& antennas, set<pair<int, int>>& antinodes, int width, int height) {
    //  n2
    for (size_t i = 0; i < antennas.size(); ++i) {
        for (size_t j = 0; j < antennas.size(); ++j) {
            if (i != j && antennas[i].frequency == antennas[j].frequency) {
                // mid point between two antennas if same freq
                int dx = antennas[j].x - antennas[i].x;
                int dy = antennas[j].y - antennas[i].y;

                // back and forth from mid point
                int x1 = antennas[i].x - dx;
                int y1 = antennas[i].y - dy;
                int x2 = antennas[j].x + dx;
                int y2 = antennas[j].y + dy;

                if (isWithinBounds(x1, y1, width, height)) {
                    antinodes.insert({x1, y1});
                }
                if (isWithinBounds(x2, y2, width, height)) {
                    antinodes.insert({x2, y2});
                }
            }
        }
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

    vector<Antenna> antennas;
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            if (isalnum(map[i][j])) {
                antennas.push_back({i, j, map[i][j]});
            }
        }
    }
    // answer
    set<pair<int, int>> antinodes;

    findAntinodes(antennas, antinodes, width, height);

    cout << "AAAAAAAAAA : " << antinodes.size() << endl;

    return 0;
}
