#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<vector<char>> grid(n, vector<char> (n));
        int lm = n, rm = 0, tm = n, dm = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> grid[i][j];
                if (grid[i][j] == '1') {
                    lm = min(lm, i);
                    rm = max(rm, i);
                    tm = min(tm, j);
                    dm = max(dm, j);
                }
            }
        }
        if (lm - rm != tm - dm) {
            cout << "TRIANGLE" << endl;
            continue;
        }
        bool flag = false;
        for (int i = lm; i <= rm; i++) {
            for (int j = tm; j <= dm; j++) {
                if (grid[i][j] != '1') {
                    cout << "TRIANGLE" << endl;
                    flag = true;
                    break;
                }
            }
        }
        if (flag) break;
        cout << "SQUARE" << endl;
    }
}