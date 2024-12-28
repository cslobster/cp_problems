#include <bits/stdc++.h>
using namespace std;

const int MXN = 3e5 + 3;

struct Ss {
    int x, d;
};

int n, m;
int order[MXN], ans[MXN];
Ss a[MXN];
stack<int> st[2];


void solve() {
    cin >> n >> m;
    st[0] = stack<int>();
    st[1] = stack<int>();
    iota(order, order + n, 0);
    for (int i = 0; i < n; i++) cin >> a[i].x;
    for (int i = 0; i < n; i++) {
        ans[i] = -1;
        char c; cin >> c;
        a[i].d = (c == 'L') ? -1 : 1;
    }
    sort(order, order + n, [](const int &i, const int &j){return a[i].x < a[j].x;});
    for (int xx = 0; xx < n; xx++) {
        int i = order[xx];
        int x = a[i].x;
        int p = a[i].x % 2;
        int d = a[i].d;
        if (d == -1) {
            if (st[p].empty()) st[p].push(i);
            else {
                int j = st[p].top();
                st[p].pop();
                ans[i] = ans[j] = (x - a[j].d * a[j].x) / 2;
            }
        } else {
            st[p].push(i);
        }
    }
    for (int p = 0; p < 2; p++) {
        while (st[p].size() > 1) {
            int i = st[p].top();
            st[p].pop();
            int j = st[p].top();
            st[p].pop();
            ans[i] = ans[j] = (2 * m - a[i].x - (a[j].d == 1 ? a[j].x : -a[j].x)) / 2;
        }
    }
    for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}