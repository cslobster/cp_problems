#include <bits/stdc++.h>
using namespace std;

const int MXI = 20, MXN = 1e5 + 3, MXB = (1 << 20);

int n;
string s;
map<char, int> charToInd;
int a[MXN], adj[MXI][MXI], dp[MXB];
int cnt = 0;

void reset() {
    memset(dp, 0x3f, sizeof(dp));
    for (int i = 0; i < MXN; i++) {
        a[i] = -1;
    }
    for (int i = 0; i < MXI; i++) {
        for (int j = 0; j < MXI; j++) {
            adj[i][j] = 0;
        }
    }
}

int main() {
    // ifstream cin("in.in");
    // ofstream cout("out.out");

    reset();

    cin >> s;
    n = s.size();
    for (int i = 0; i < n; i++) {
        if (charToInd.count(s[i])) a[i] = charToInd[s[i]];
        else {
            charToInd[s[i]] = cnt++;
            a[i] = charToInd[s[i]];
        }
        if (i) {
            adj[a[i - 1]][a[i]]++;
        }
    }

    dp[0] = 1;
    for (int mask = 1; mask < (1 << cnt); mask++) {
        for (int c = 0; c < cnt; c++) {
            if (!(mask & (1 << c))) continue;
            int sum = 0;
            for (int i = 0; i < cnt; i++) {
                if (mask & (1 << i)) sum += adj[c][i];
            }
            dp[mask] = min(dp[mask], dp[mask ^ (1 << c)] + sum);
        }
    }
    cout << dp[(1 << cnt) - 1] << endl;
}