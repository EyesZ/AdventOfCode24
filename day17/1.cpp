using namespace std;
#include <bits/stdc++.h>

int program[16];
int programSize = 16;

void compute(int a, int b, int c) {
    for (int zzz = 0; zzz < programSize; zzz+=2) {
        int opcode = program[zzz];
        int operand = program[zzz+1];
        int combr = operand;
        if (operand == 4) {
            combr = a;
        }
        if (operand == 5) {
            combr = b;
        }
        if (operand == 6) {
            combr = c;
        }
        if (opcode == 0) {  // adv
            a /= 1 << combr;
        }
        if (opcode == 1) {  // bxl
            b ^= operand;
        }
        if (opcode == 2) {  // bst
            b = combr % 8;
        }
        if (opcode == 3) {  // jnz
            if (a != 0) {
                zzz = operand - 2;
            }
        }
        if (opcode == 4) {  // bxc
            b ^= c;
        }
        if (opcode == 5) {  // out
            printf("%d,", combr % 8);
        }
        if (opcode == 6) {  // bdv
            b = a / (1 << combr);
        }
        if (opcode == 7) {  // cdv
            c = a / (1 << combr);
        }
    }
}

int main() {
    int a, b, c;
    cin >> a ;

    for (int i = 0; i < 16; i++) {
        cin >> program[i];
        programSize++;
    }
    compute(a, b, c);
    printf("\n");

}
