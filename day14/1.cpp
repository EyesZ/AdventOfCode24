#include <bits/stdc++.h>
using namespace std;

const int WIDTH = 101;
const int HEIGHT = 103;

int getQuadrant(int x, int y) {
    int midX = WIDTH / 2;
    int midY = HEIGHT / 2;

    if (x < midX && y < midY) return 1;
    if (x < midX && y > midY) return 2;
    if (x > midX && y < midY) return 3; 
    if (x > midX && y > midY) return 4; 
    return 0;
}

int main() {
    string line;

    int quadrant[5]={0};
    while (getline(cin, line)) {
        if (line.empty()) continue;
        
        int px, py, vx, vy;
        sscanf(line.c_str(), "p=%d,%d v=%d,%d", &px, &py, &vx, &vy);
        //cout << px << " " << py << " " << vx << " " << vy << endl;

        px = (px + ((vx+WIDTH) * 100)) % WIDTH;
        py = (py + ((vy+HEIGHT) * 100)) % HEIGHT;
        //cout << px << " " << py << endl;
        quadrant[getQuadrant(px, py)]++;
    }

    cout << quadrant[1]*quadrant[2]*quadrant[3]*quadrant[4] << endl;
    return 0;
}
