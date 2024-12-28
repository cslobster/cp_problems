#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int MXT = 1e3 + 1;

int t, k;
ld p[MXT];
ll c[MXT][MXT];

void calc_c() {
    c[0][0] = 1;
    for (int n = 1; n < MXT; n++) {
        for (int k = 0; k < MXT; k++) {
            if (k == 0) c[n][k] = 1;
            else c[n][k] = c[n - 1][k - 1] + c[n - 1][k];
        }
    }
}

void calc_p() {
    for (int i = 0; i < MXT; i++) {
        p[i] = (ld)c[t][i] / (1 << t);
    }
}

int main() {
    cin >> t >> k;
    t--;
    calc_c();
    calc_p();

    ld prev = 0; int j;
    for (int i = 1; i <= k; i++) {
        double ans = 0;
        for (j = 0; j <= ((int)prev); j++) {
            ans += p[j];
        }
        ans *= prev;
        for (; j <= t; j++) {
            ans += j * p[j];
        }
        // for (j = 0; j <= t; j++) {
        //     ans += p[j] * max((double)j, prev);
        // }
        prev = ans;
    }
    cout << setprecision(20) << prev + 1 << endl;
}