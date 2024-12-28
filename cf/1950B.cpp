#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<char>> a(2 * n + 1, vector<char> (2 * n + 1));
        for (int i = 0; i < n; i++) {
            // i * 2, i * 2 + 1
            for (int j = 0; j < n; j++) {
                // j * 2, j * 2 + 1
                char c;
                if ((i + j) % 2 == 0) {
                    c = '#';
                } else c = '.';
                a[i * 2][j * 2] = c;
                a[i * 2][j * 2 + 1] = c;
                a[i * 2 + 1][j * 2] = c;
                a[i * 2 + 1][j * 2 + 1] = c;
            }
        }
        for (int i = 0; i < 2 * n; i++) {
            for (int j = 0; j < 2 * n; j++) {
                cout << a[i][j];
            }
            cout << endl;
        }
    }
}