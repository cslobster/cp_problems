#include <bits/stdc++.h>
using namespace std;

#define int long long

const int MXN = 303, MXD = 19, MOD = 1e9 + 7;

int n, q;
vector<int> a, b;
int p[MXN];
int dp[MXN][MXD][MXD][3];
// int dp[6][3][3][3];
int ans[2][MXN][MXN];
int cnt = 0;
// dp[i][l][r][c]

void add(int &a, int b) {
    a += b;
    a %= MOD;
}


void read_string(vector<int> &c) {
    // ifstream cin("test.in");

    string s; cin >> s;
    for (auto ch : s) {
        c.push_back(ch - '0');
    }
    reverse(c.begin(), c.end());
}

void read_int(int p, int x, vector<int> &c) {
    if (!p) x--;
    while (x) {
        c.push_back(x % 10);
        x /= 10;
    }
    c.push_back(-1);
    reverse(c.begin(), c.end());
}
ofstream fout("test.out");

void calc_dp(int x, vector<int> &num) {

    for (int i = n; i >= 1; i--) {
        memset(dp, 0, sizeof(dp));
        for (int j = i; j <= n; j++) {
            // for (int len = 0; len < num.size(); len++) {
                // for (int l = 0; l + len < num.size(); l++) {
            for (int l = 1; l < num.size(); l++) {
                for (int r = num.size() - 1; r >= l; r--) {
                    /*
                    // int r = l + len;
                    for (int z = 0; z < 3; z++) {
                        dp[j][l][r][z] += dp[j - 1][l][r][z];
                    }
                    if (l == r) {
                        if (x == 1 && i == 4 && j == 5 && l == 3) {
                            fout << "" << endl;
                        }
                        if (p[j] < num[l]) dp[j][l][l][0] += 2;
                        else if (p[j] == num[l]) dp[j][l][l][1] += 2;
                        else dp[j][l][l][2] += 2;
                    }

                    // add back
                    add(dp[j][l][r][0], dp[j - 1][l][r - 1][0]);
                    add(dp[j][l][r][2], dp[j - 1][l][r - 1][2]);
                    if (p[j] < num[r]) add(dp[j][l][r][0], dp[j - 1][l][r - 1][1]);
                    else if (p[j] == num[r]) add(dp[j][l][r][1], dp[j - 1][l][r - 1][1]);
                    else {
                        add(dp[j][l][r][2], dp[j - 1][l][r - 1][1]);
                    }

                    // add front
                    if (p[j] < num[l]) {
                        for (int z = 0; z < 3; z++)
                            add(dp[j][l][r][0], dp[j - 1][l + 1][r][z]);
                    } else if (p[j] == num[l]) {
                        for (int z = 0; z < 3; z++)
                            add(dp[j][l][r][z], dp[j - 1][l + 1][r][z]);
                    } else {
                        for (int z = 0; z < 3; z++)
                            add(dp[j][l][r][2], dp[j - 1][l + 1][r][z]);
                    }

                    fout << i << " " << j << " " << l << " " << r << " ";
                    for (int z = 0; z < 3; z++) {
                        fout << dp[j][l][r][z] << " ";
                    }
                    // fout << dp[5][3][3][0];
                    fout << endl;

                    if (l == 1) {
                        for (int z = 0; z < 3; z++) {
                            if (l == 1 && r == num.size() - 1 && z == 2) break;
                            // fout << l << " " << i << " " << j << " " << dp[j][l][r][z] << " " <<ans[x][i][j] << endl;
                            add(ans[x][i][j], dp[j][l][r][z]);
                        }
                    }
                    */
                    int equal = 0, less = 0, greater = 0;

                    // do nothing
                    add(equal, dp[j - 1][l][r][1]);
                    add(less, dp[j - 1][l][r][0]);
                    add(greater, dp[j - 1][l][r][2]);

                    if (l == r) {
                        // if (x == 1 && i == 4 && j == 5 && l == 3) {
                        //     fout << "" << endl;
                        // }
                        if (p[j] < num[l]) add(less, 2);
                        else if (p[j] == num[l]) add(equal, 2);
                        else greater += 2;
                    }

                    // add L to front
                    if (p[j] > num[l]) {
                        for (int z = 0; z < 3; z++)
                            add(greater, dp[j - 1][l + 1][r][z]);
                    } else if (p[j] == num[l]) {
                        for (int z = 0; z < 3; z++)
                            add(equal, dp[j - 1][l + 1][r][z]);
                    } else { // p[j] < num[l]
                        for (int z = 0; z < 3; z++)
                            add(less, dp[j - 1][l + 1][r][z]);
                    }

                    // add R to back
                    add(greater, dp[j - 1][l][r - 1][2]);
                    add(less, dp[j - 1][l][r - 1][0]);
                    if (p[j] > num[r]) {
                        add(greater, dp[j - 1][l][r - 1][1]);
                    } else if (p[j] == num[r]) {
                        add(equal, dp[j - 1][l][r - 1][1]);
                    } else {
                        // p[j] < num[r]
                        add(less, dp[j - 1][l][r - 1][1]);
                    }
                    dp[j][l][r][1] = equal % MOD; dp[j][l][r][0] = less % MOD, dp[j][l][r][2] = greater % MOD;
                    if (l == 1) {
                        for (int z = 0; z < 3; z++) {

                            if (l == 1 && r == num.size() - 1 && z == 2) break;
                            cnt++;
                            if (cnt < 1000)
                            fout << cnt << " " << l << " " << i << " " << j << " " << dp[j][l][r][z] << " " <<ans[x][i][j] << endl;
                            add(ans[x][i][j], dp[j][l][r][z]);
                        }
                    }
                }
            }

            // for (int d = 1; d < num.size(); d++) {
            //     ans[x][i][j] += dp[j][1][d][0];
            //     ans[x][i][j] += dp[j][1][d][1];
            //     if (d == num.size() - 1) ans[x][i][j] += dp[j][1][d][2];
            // }
        }
    }
}

signed main() {
    ifstream cin("test.in");
    cin >> n;
    int aa, bb; cin >> aa >> bb;
    read_int(0, aa, a), read_int(1, bb, b);
    for (int i = 1; i <= n; i++) cin >> p[i];
    cin >> q;
    calc_dp(0, a);
    calc_dp(1, b);

    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        // fout << (ans[1][l][r] - ans[0][l][r] + MOD) % MOD << endl;
    }
    fout << cnt << endl;
}

/*
5 13 31
1 2 3 4 5
3
1 2
1 3
2 5

*/