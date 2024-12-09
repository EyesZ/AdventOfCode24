#include <bits/stdc++.h>
using namespace std;

long long checksum(vector<int> zzz) {

    vector<int> stack;
    for (int i = 0; i < zzz.size(); i++) {
        if (i%2 == 1){ 
            // -42 for empytness
            stack.insert(stack.end(), zzz[i], -42);
        }
        else {
            // i/2 for pos
            stack.insert(stack.end(), zzz[i], i/2);
        }
    }
    long long sum = 0;

    // print stack
    // 0 0 -42 -42 -42 1 1 1 -42 -42 -42 2 -42 -42 -42 3 3 3 -42 4 4 -42 5 5 5 5 -42 6 6 6 6 -42 7 7 7 -42 8 8 8 8 9 9

    // reorder the stack for compression
    int jjj = stack.size() -1;
    int iii = 0;
    while(iii < jjj) {
        if(stack[iii] == -42 && stack[jjj] != -42) {
            swap(stack[iii], stack[jjj]);
            continue;
        }
        if(stack[iii] != -42) {
            iii++;
        }
        if(stack[jjj] == -42){
            jjj--;
        }
    }
    
    // print stack
    //0 0 9 9 8 1 1 1 8 8 8 2 7 7 7 3 3 3 6 4 4 6 5 5 5 5 6 6 -42 -42 -42 -42 -42 -42 -42 -42 -42 -42 -42 -42 -42 -42

    for(int vvv=0; vvv < stack.size() && stack[vvv] != -42; vvv++) {
        sum += vvv*stack[vvv];
    }


    return sum;
}

int main() {
    string line;
    getline(cin, line);

    vector<int> zzz;
    for (char c : line) {
        zzz.push_back(c-'0');
    }

    long long sum = 0;
    sum = checksum(zzz);
    cout << sum << endl;
    return 0;
}