#include <bits/stdc++.h>
using namespace std;

int A, B, n, m;
int a[2010], b[2010], vis[4100000];

inline pair<int, int> get(int z) {
    return {z / 2001, z % 2001};
}

int d[4] = {2001, -2001, 1, -1};

signed main() {
    ifstream cin("fencedin.in");
    ofstream cout("fencedin.out");

    cin >> A >> B >> n >> m;
    a[0] = 0, b[0] = 0;
    a[n + 1] = A, b[m + 1] = B;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= m; i++) {
        cin >> b[i];
    }
    sort(a, a + n + 1);
    sort(b, b + m + 1);
    priority_queue<pair<int, int>> q;
    long long cost = 0;
    q.push({0, 2002});
    for (int cnt = 0; cnt < (n + 1) * (m + 1); cnt++) {
        assert(!q.empty());
        auto tp = q.top();
        q.pop();
        if (vis[tp.second]) {
            cnt--; continue;
        }
        vis[tp.second] = true;
        cost -= tp.first;
        for (int i = 0; i < 4; i++) {
            int z = tp.second + d[i];
            auto [x, y] = get(z);
            if (x <= 0 || y <= 0 || x > n + 1 || y > m + 1) continue;
            if (vis[z]) continue;
            int dis;
            if (i < 2) {
                dis = b[y] - b[y - 1];
            } else {
                dis = a[x] - a[x - 1];
            }
            q.push({-dis, z});
        }
    }
    cout << cost;
}