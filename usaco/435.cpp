#include <bits/stdc++.h>
using namespace std;
#define int long long
int dp[19][50][2][2];
int st, ed;

void xx() {
    for (int i = 0; i < 19; i++)
        for (int j = 0; j < 50; j++)
            for (int k = 0; k < 2; k++)
                for (int l = 0; l < 2; l++)
                    dp[i][j][k][l] = -1;
}

int f(int i, int k, int un, vector<int> a, int started, int x, int y, string targ) {
    if (i == targ.size()) {
        if (!started) return 0;
        if (y != -1) {
            return k == 0;
        }
        return k >= 0;
    }
    if (dp[i][k][un][started] != -1) return dp[i][k][un][started];
    int ans = 0;
    for (int j = 0; j <= 9; j++) {
        int p = targ[i] - '0';
        if (!un && j > p) break;
        bool under = un, start = false;
        if (j < p) {
            under = true;
        }
        if (j != 0 || started) {
            start = true;
        }
        if (start && y != -1 && j != x && j != y) continue;
        int add = 0;
        if (start) {
            if (j == x) add++;
            else add--;
        }
        ans += f(i + 1, k + add, under, a, start, x, y, targ);
    }
    return dp[i][k][un][started] = ans;
}

int cnt(int z) {
    string x = to_string(z);
    int ans = 0, y = 0;
    for (int i = 0; i <= 9; i++) {
        xx();
        ans += f(0, 0, false, {}, false, i, -1, x);
    }
    for (int i = 0; i <= 9; i++) {
        for (int j = 0; j <= 9; j++) {
            xx();
            y += f(0, 0, false, {}, false, i, j, x);
        }
    }
    return ans - (y / 2);
}

signed main() {
    ifstream cin("odometer.in");
    ofstream cout("odometer.out");
    cin >> st >> ed;
    cout << cnt(ed) - cnt(st - 1) << endl;
}