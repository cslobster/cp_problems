#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MX = 1e6 + 2;

int n, k; ll m;
int p[MX], nxt[MX]; bool vis[MX]; int cnt[MX], res[MX];
vector<pair<int, int>> s[MX];
vector<int> cyc;
int ans = 0;
int id = 0;

void dfs(int node) {
    vis[node] = true;
    cyc.push_back(node);
    if (!vis[nxt[node]]) dfs(nxt[node]);
}

void add(int i, int lim) {
    for (auto e : s[i]) {
        if (lim < e.second) continue;
        if (cnt[e.first] == 0) ans++;
        cnt[e.first]++;
    }
}

void sub(int i, int lim) {
    for (auto e : s[i]) {
        if (lim < e.second) continue;
        cnt[e.first]--;
        if (cnt[e.first] == 0) ans--;
    }
}

int main() {
    ifstream cin("in.in");
    ofstream cout("out.out");

    cin >> n >> k >> m;
    iota(p, p + n + 1, 0);
    for (int i = 0; i < k; i++) {
        int a, b;
        cin >> a >> b;
        s[p[a]].push_back({b, i + 1});
        s[p[b]].push_back({a, i + 1});
        swap(p[a], p[b]);
    }

    memset(vis, 0, sizeof(0));
    for (int i = 1; i <= n; i++) {
        s[i].push_back({i, 0});
        nxt[p[i]] = i;
    }
    for (int i = 1; i <= n; i++) {
        ll d = m / k, r = m % k;
        if (!vis[i]) {
            dfs(i);
            if (d > cyc.size()) {
                d = cyc.size();
                r = 0;
            }

            for (int i = 0; i < d; i++) {
                add(cyc[i], k);
            }

            int j = d - 1;
            for (int i = 0; i < cyc.size(); i++) {
                int nj = (j + 1) % cyc.size();
                add(cyc[nj], r);
                if (ans < 0) cout << cyc[i] << " " << i << endl;
                res[cyc[i]] = ans;
                cout << ans << endl;
                sub(cyc[nj], r);
                sub(cyc[i], k);
                add(cyc[nj], k);
                j = nj;
            }
            ans = 0;
            for (int i = 1; i <= n; i++) {
                cnt[i] = 0;
            }
            cyc.clear();
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << res[i] << endl;
    }
}