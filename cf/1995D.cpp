#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, c, k;
        cin >> n >> c >> k;
        string s;
        cin >> s;
        vector<vector<int>> pre(c, vector<int>(n + 1));
        for (int i = 0; i < c; i++) {
            for (int j = 0; j < n; j++) {
                pre[i][j + 1] = pre[i][j] + (s[j] - 'A' == i);
            }
        }
        vector<bool> bs(1 << c);
        for (int i = 0; i <= n - k; i++) {
            int st = 0;
            for (int j = 0; j < c; j++) {
                if (pre[i + k][j] - pre[i][j]) st |= (1 << j);
            }
            bs[st] = true;
        }
        bs[(1 << (s[s.size() - 1] - 'A'))] = true;

    }
}