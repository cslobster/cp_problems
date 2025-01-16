#include <bits/stdc++.h>
using namespace std;

const int MXN = 2e5 + 3;

struct Query {
    int p, x, q, y;
};

struct Qq {
    int p[2], x[2], ii;
};

bool operator<(const Qq &a, const Qq &b) {
    return a.x[a.ii] < b.x[b.ii];
}


int n, m, k;
vector<Qq> adj[MXN];
int cur[MXN];
int indexAt[MXN];
Query a[MXN];

int val(int a, int b) {
    if (cur[a] < b) return 0;
    if (cur[a] == b) return 1;
    return 2;
}

bool valid(int i) {
    return val(a[i].p, a[i].x) == val(a[i].q, a[i].y);
}

struct State {
    int p, i; // array index, index in adj[p]
};

bool operator<(const State &x, const State &y) {
    return adj[x.p][x.i].x[adj[x.p][x.i].ii] < adj[y.p][y.i].x[adj[y.p][y.i].ii];
}

int main() {
    cin >> n >> m >> k;
    priority_queue<State> pq;
    for (int i = 0; i < k; i++) {
        int p, x, q, y;
        cin >> p >> x >> q >> y;
        a[i] = {p, x, q, y};
        adj[p].push_back({p, q, x, y, 0});
        adj[q].push_back({p, q, x, y, 1});
    }
    for (int i = 1; i <= n; i++) {
        sort(adj[i].begin(), adj[i].end());
        indexAt[i] = 0;
        cur[i] = 1;
        pq.push({i, 0});
    }
    while (!pq.empty()) {
        auto [p, i] = pq.top();
        pq.pop();
        if (valid(i)) continue;
        if (indexAt[p] != i) continue;
        auto &[pp, xx, ii] = adj[p][i];
        int changed = 0;
        if (cur[pp[ii]] > xx[ii]) {
            cur[pp[1 - ii]] = xx[1 - ii] + 1;
            changed = 1 - ii;
        } else if (cur[pp[1 - ii]] > xx[1 - ii]) {
            cur[pp[ii]] = xx[ii] + 1;
            changed = ii;
        } else if (cur[pp[ii]] == xx[ii]) {
            cur[pp[1 - ii]] = xx[1 - ii];
            changed = 1 - ii;
        } else if (cur[pp[1 - ii]] == xx[1 - ii]) {
            cur[pp[ii]] = xx[ii];
            changed = ii;
        }
        if (cur[pp[ii]] > m || cur[pp[1 - ii]] > m) {
            cout << -1 << endl;
            return 0;
        }
        indexAt[pp[ii]]++;
        if (indexAt[pp[ii]] < adj[pp[ii]].size()) {
            pq.push({pp[ii], indexAt[pp[ii]]});
        }
        indexAt[pp[1 - ii]]++;
        if (indexAt[pp[1 - ii]] < adj[pp[1 - ii]].size()) {
            pq.push({pp[1 - ii], indexAt[pp[1 - ii]]});
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        cout << cur[i] << " ";
        ans += cur[i];
    }
    cout << endl;
    cout << ans << endl;
}