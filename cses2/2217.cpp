#include <bits/stdc++.h>
using namespace std;

const int MXN = 2e5 + 3;

int n, m;
int x[MXN], y[MXN];

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> x[i];
        y[x[i]] = i;
    }
    int ans = 0, prev = n + 1;
    for (int i = 1; i <= n; i++) {
        if (y[i] < prev) ans++;
        prev = y[i];
    }
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        int og = 0;
        if (x[a] - 1 > 0 && y[x[a] - 1] > y[x[a]]) og++;
        if (x[a] + 1 <= n && y[x[a]] > y[x[a] + 1]) og++;
        if (x[a] != x[b] - 1 && x[b] - 1 > 0 && y[x[b] - 1] > y[x[b]]) og++;
        if (x[b] != x[a] - 1 && x[b] + 1 <= n && y[x[b]] > y[x[b] + 1]) og++;
        swap(x[a], x[b]);
        swap(y[x[a]], y[x[b]]);
        int nw = 0;
        if (x[a] - 1 > 0 && y[x[a] - 1] > y[x[a]]) nw++;
        if (x[a] + 1 <= n && y[x[a]] > y[x[a] + 1]) nw++;
        if (x[a] != x[b] - 1 && x[b] - 1 > 0 && y[x[b] - 1] > y[x[b]]) nw++;
        if (x[b] != x[a] - 1 && x[b] + 1 <= n && y[x[b]] > y[x[b] + 1]) nw++;
        ans = ans - og + nw;
        cout << ans << endl;
    }
}