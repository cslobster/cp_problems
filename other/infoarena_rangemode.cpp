#include <bits/stdc++.h>
using namespace std;

const int MXN = 1e5 + 3, MXSQ = 400;

int n, q, sq, blocks;
int a[MXN], freq[MXN], ans[MXN];
vector<array<int, 3>> queries[MXSQ];

void add(int i, int &mx) {
    freq[a[i]]++;
    if (mx == -1 || freq[a[i]] > freq[mx] || (freq[a[i]] == freq[mx] && a[i] < mx)) {
        mx = a[i];
    }
}

int main() {
    ifstream cin("rangemode.in");
    ofstream cout("rangemode.out");
    cin >> n >> q;
    sq = ceil(sqrt(n));
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 0; i < q; i++) {
        int l, r; cin >> l >> r;
        queries[l / sq].push_back({l, r, i});
    }
    for (int i = 0; i <= sq; i++) {
        sort(queries[i].begin(), queries[i].end(), [](const array<int, 3> &a, const array<int, 3> &b) {
            if (a[1] != b[1]) return a[1] < b[1];
            return a[0] < b[0];
        });
        // now do this query
        int prevMx = sq * (i + 1) - 1, mx = -1;
        for (int x = 0; x < queries[i].size(); x++) {
            auto &[l, r, idx] = queries[i][x];
            for (int ind = r; ind > prevMx; ind--) {
                add(ind, mx);
            }
            prevMx = max(prevMx, r);
            int mx2 = mx;
            // add the remainder
            for (int ind = l; ind <= min(r, sq * (i + 1) - 1); ind++) {
                add(ind, mx2);
            }
            ans[idx] = mx2;
            for (int ind = l; ind <= min(r, sq * (i + 1) - 1); ind++) {
                freq[a[ind]]--;
            }
        }
        for (int ind = 0; ind < MXN; ind++) {
            freq[ind] = 0;
        }
    }
    for (int i = 0; i < q; i++) {
        cout << ans[i] << endl;
    }
}