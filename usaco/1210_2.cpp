#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int MXT = 1e3 + 1;

int t, k;
ld p[MXT], a[MXT], b[MXT];
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
    // for (int i = 0; i < MXT; i++) {
    //     ld x = pow(0.5, t);
    //     p[i] = (ld)c[t][i] * x;
    //     a[i] = p[i];
    //     if (i) a[i] += a[i - 1];
    // }
    p[0] = pow(0.5, t);
    a[0] = p[0];
    for (int i = 1; i < MXT; i++) {
        p[i] = p[i - 1] * (t - i + 1) / (i);
        a[i] = a[i - 1] + p[i];
    }
    for (int i = t; i >= 0; i--) {
        b[i] = i * p[i];
        if (i + 1 < MXT) b[i] += b[i + 1];
    }
}


ld calc(int q, ld e_x) {
    int fe_x = (int) e_x;
    ld aq = pow(a[fe_x], q);
    ld p1 = aq * e_x;
    ld p2 = b[fe_x + 1] * (1 - aq);
    if (a[fe_x] == 1) p2 = 0;
    else p2 /= (1 - a[fe_x]);
    ld sum = p1 + p2;
    return sum;
}

int main() {
    // ifstream cin("test.in");
    // ofstream cout("test.out");
    cin >> t >> k;
    t--;
    calc_c();
    calc_p();

    ld prev = 0; int j;
    for (int i = 0; i <= k; ) {
        int l = 1;
        int r = k - i;
        while (l != r) {
            int mid = (l + r + 1)/2;
            if (((int)calc(mid, prev)) == (int)prev) {
                l = mid;
            }
            else {
                r = mid - 1;
            }
        }
        prev = calc(l, prev);
        i += l;
        if (i >= k) break;
    }
    cout << setprecision(20) << prev + 1 << endl;
}