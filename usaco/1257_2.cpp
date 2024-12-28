#include <bits/stdc++.h>
using namespace std;

struct Cow {
    int p, c, x;
};

bool operator<(const Cow &a, const Cow &b) {
    return a.x < b.x;
}

const int MXN = 2003;

int n, a, b;
Cow cows[MXN];
int dp[MXN][4007];
int ans = 0;

void setMax(int &a, int b) {
    if (b == -1) return;
    a = max(a, b);
    ans = max(ans, a);
}

int main() {
    cin >> n >> a >> b;
    for (int i = 1; i <= n; i++) {
        cin >> cows[i].p >> cows[i].c >> cows[i].x;
    }
    sort(cows + 1, cows + n + 1);
    memset(dp, -1, sizeof(dp));
    dp[0][a + b] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = a + b; j >= 0; j--) {
            if (i) setMax(dp[i][j], dp[i - 1][j]);
            if (dp[i][j] == -1) {
                continue;
            }
            if (i) setMax(dp[i][j], dp[i - 1][j]);
            if (j > a) {
                if (j - a >= cows[i + 1].c * cows[i + 1].x) {
                    setMax(dp[i + 1][j - cows[i + 1].c * cows[i + 1].x], dp[i][j] + cows[i + 1].p);
                } else {
                    int newPrice = cows[i + 1].c - (j - a) / cows[i + 1].x;
                    if (a >= newPrice)
                        setMax(dp[i + 1][a - newPrice], dp[i][j] + cows[i + 1].p);
                }
            } else if (j >= cows[i + 1].c) {
                setMax(dp[i + 1][j - cows[i + 1].c], dp[i][j] + cows[i + 1].p);
            }
        }
    }
    cout << ans << endl;

}