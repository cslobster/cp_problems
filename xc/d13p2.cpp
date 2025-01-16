/*
 * straight-forward bfs but technically on a 3d grid
 * you can travel from one hole to another only if dist < 2r
 * precalculate adj and bfs
 */

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MXN = 1003;

struct Point {
    ll x, y, z;
};

ll inline sq(ll a) {
    return a * a;
}

ll dist(Point a, Point b) {
    return sq(a.x - b.x) + sq(a.y - b.y) + sq(a.z - b.z);
}

int n; ll h, r;
Point a[MXN];
ll d[MXN];
bool vis[MXN];
vector<int> adj[MXN];
vector<int> touches0, touchesN;

bool works(Point a, Point b) {
    return dist(a, b) <= 4 * r * r;
}

void clear() {
    for (int i = 0; i < MXN; i++) {
        adj[i].clear();
        vis[i] = false;
    }
    touches0.clear(), touchesN.clear();
}

void solve() {
    clear();
    cin >> n >> h >> r;
    for (int i = 0; i < n; i++) {
        d[i] = 1e18;
        cin >> a[i].x >> a[i].y >> a[i].z;
    }
    for (int i = 0; i < n; i++) {
        if (abs(a[i].z) <= r) {
            touches0.push_back(i);
        }
        if (abs(h - a[i].z) <= r) {
            touchesN.push_back(i);
        }
        for (int j = i + 1; j < n; j++) {
            if (works(a[i], a[j])) {
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }
    queue<int> q;
    for (auto i : touches0) {
        d[i] = 0;
        q.push(i);
    }
    while (!q.empty()) {
        auto tp = q.front();
        q.pop();
        for (auto ch : adj[tp]) {
            if (!vis[ch]) {
                vis[ch] = true;
                d[ch] = d[tp] + 1;
                q.push(ch);
            }
        }
    }
    ll ans = 1e18;
    for (auto i : touchesN) {
        ans = min(ans, d[i]);
    }
    if (ans == (long long)1e18) {
        cout << "No" << endl;
    } else {
        cout << "Yes" << endl;
    }
}

int main() {
    int t; cin >> t;
    while (t--) solve();
}