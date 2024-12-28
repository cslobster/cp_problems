#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<char>> grid(n, vector<char>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }
    vector<vector<int>> h(n, vector<int>(m));
    for (int i = 0; i < m; i++) {
        int last = 0;
        for (int j = 0; j < n; j++) {
            if (grid[j][i] == '*') last = 0;
            else h[j][i] = ++last;
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        stack<int> s;
        vector<int> l(m), r(m);
        for (int j = 0; j < m; j++) {
            if (s.empty()) {
                s.push(j);
                l[j] = -1;
            } else {
                while (!s.empty() && h[i][s.top()] >= h[i][j]) {
                    s.pop();
                }
                if (s.empty()) {
                    l[j] = -1;
                } else {
                    l[j] = s.top();
                }
                s.push(j);
            }
        }
        stack<int> s2;
        for (int j = m - 1; j >= 0; j--) {
            if (s2.empty()) {
                s2.push(j);
                r[j] = m;
            } else {
                while (!s2.empty() && h[i][s2.top()] >= h[i][j]) {
                    s2.pop();
                }
                if (s2.empty()) {
                    r[j] = m;
                } else {
                    r[j] = s2.top();
                }
                s2.push(j);
            }
        }

        for (int j = 0; j < m; j++) {
            ans = max(ans, (r[j] - l[j] - 1) * h[i][j]);
        }
    }
    cout << ans << endl;
}