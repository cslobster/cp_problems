#include <bits/stdc++.h>
using namespace std;

char grid[8][8];
int order[8];

int check() {
    set<int> notAvX, notAvY;
    for (int i = 0; i < 8; i++) {
        int j = order[i];
        if (grid[i][j] == '*') return 0;
        if (notAvX.count(i - j)) return 0;
        if (notAvY.count(i + j)) return 0;
        notAvX.insert(i - j);
        notAvY.insert(i + j);
    }
    return 1;
}

int main() {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            cin >> grid[i][j];
        }
    }
    iota(order, order + 8, 0);
    int ans = 0;
    do {
        ans += check();
    } while (next_permutation(order, order + 8));
    cout << ans << endl;
}