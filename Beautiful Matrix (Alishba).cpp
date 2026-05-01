#include <iostream>
using namespace std;

int main() {
    int x, row, col;

    for(int i = 1; i <= 5; i++) {
        for(int j = 1; j <= 5; j++) {
            cin >> x;
            if(x == 1) {
                row = i;
                col = j;
            }
        }
    }

    int moves = abs(row - 3) + abs(col - 3);

    cout << moves;

    return 0;
}