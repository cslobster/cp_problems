#include <bits/stdc++.h>
using namespace std;

const int MX = 1e5 + 1;
int n, k, m, p[MX], ans[MX];
set<pair<int, int>> s[MX];
int par[MX];
vector<int> cycles[MX], d[MX];
int id = 0;
int vis[MX];
int cnt = 0;

int val(map<int, int> &un) {
    int aa= 0;
    for (auto e : un) {
        if (e.second > 0) aa++;
    }
    return aa;
}

void dfs(int node) {
    if (vis[node]) return;
    vis[node] = true;
    cycles[id].push_back(node);
    d[id].push_back(node);
    dfs(par[node]);
}

void merge(map<int, int> &mp, set<pair<int, int>> b, int lim) {
    for (auto e : b) {
        if (e.second > lim) continue;
        if (mp[e.first] == 0) cnt++;
        mp[e.first]++;
    }
}

void del(map<int, int> &mp, set<pair<int, int>> b, int lim) {
    for (auto e : b) {
        if (e.second > lim) continue;
        mp[e.first]--;
        if (mp[e.first] == 0) cnt--;
    }
}

int main() {
    cin >> n >> k >> m;
    iota(p, p + n + 1, 0);
    for (int i = 0; i < k; i++) {
        int a, b;
        cin >> a >> b;
        s[p[a]].insert({b, i + 1});
        s[p[b]].insert({a, i + 1});
        swap(p[a], p[b]);
    }
    for (int i = 1; i <= n; i++) {
        s[i].insert({i, 0});
        par[p[i]] = i;
    }
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            dfs(i);
            id++;
        }
    }
    int d = m / k, r = m % k;
    for (int i = 0; i < id; i++) {
        auto &cyc = cycles[i];
        map<int, int> un;
        if (d >= cyc.size()) {
            d = cyc.size();
            r = 0;
        }
        for (int i = 0; i < d; i++) {
            merge(un, s[cyc[i]], k);
        }
        int j = d - 1;
        for (int  i = 0; i < cyc.size(); i++) {
            int nj = (j + 1) % cyc.size();
            merge(un, s[cyc[nj]], r);
            // cout << val(un) << " " << cnt << endl;
            ans[cyc[i]] = cnt;
            del(un, s[cyc[nj]], r);
            del(un, s[cyc[i]], k);
            merge(un, s[cyc[nj]], k);
            j = nj;
        }
        cnt = 0;
    }
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << endl;
    }
}