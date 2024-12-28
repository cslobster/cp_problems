#include <bits/stdc++.h>
using namespace std;

#define int long long
vector<int> xx, yy;
vector<int> limx, limy;
int sz;
int dp[41][3][3][2];

vector<int> conv(int a, int b) {
    vector<int> ans(40); int i = 0;
    while (a > 0) {
        ans[i] = a % b;
        a /= b;
        i++;
    }
    return ans;
}

int f(int i, int xc, int yc, bool leq) {
    if (dp[i][xc][yc][leq] != -1) return dp[i][xc][yc][leq];
//    cout << i << " " << xc << " " << yc << " " << leq << endl;
    if (i == sz) {
        if (xc == 0 && yc == 0) return leq;
        return 0;
    }
    int ans = 0;
    int stx = (xx[i] + xc) % 3;
    int sty = (yy[i] + yc) % 3;
    int carx = (xx[i] + xc) / 3;
    int cary = (yy[i] + yc) / 3;
    for (auto d : {0, 1, 2}) { // next digit to append
        int dx = (stx + d) % 3; // next value digit
        int dy = (sty + d) % 3;
        if (dx % 2 != dy % 2) continue;
        // next carry
        int nxc = (stx + d) / 3; // value to carry
        int nyc = (sty + d) / 3;

        bool nleq = false;
        if (dx < limx[i]) nleq = true;
        if (dx == limx[i]) nleq = leq;
//        cout << dx << " " << dy << " " << nxc << " " << nyc << " " << nleq << endl;
        ans += f(i + 1, carx + nxc, cary + nyc, nleq);
    }
    return dp[i][xc][yc][leq] = ans;
}


signed main() {
    int q;
    cin >> q;
    while (q--) {
        memset(dp, -1, sizeof(dp));
        int d, x, y;
        cin >> d >> x >> y;
        if (x > y) swap(x, y);
        xx = conv(x, 3); yy = conv(y, 3);
        limx = conv(x + d, 3), limy = conv(y + d, 3);
        sz = xx.size();
        cout << f(0, 0, 0, true) << endl;
    }
}