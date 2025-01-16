#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MXN = 1e5 + 3;

int n, b;
ll c[MXN], l[MXN], p[MXN], sum[MXN], cnt[MXN];
vector<int> ch[MXN];
multiset<ll> s[MXN];

void merge(multiset<ll> &a, multiset<ll> b) {
    if (a.size() > b.size()) swap(a, b);
    for (auto e : b) {
        a.insert(e);
    }
}

void dfs(int par) {
    for (auto child : ch[par]) {
        dfs(child);
        merge(s[par], s[child]);
    }
}

int main() {
    cin >> n >> b;
    for (int i = 1; i <= n; i++) {
        cin >> p[i] >> c[i] >> l[i];
        s[i].insert(c[i]);
        sum[i] = c[i];
        cnt[i] = 1;
        ch[p[i]].push_back(i);
    }
    dfs(1);
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        ll mxcnt = 0, sum = 0;
        for (auto e : s[i]) {
            if (sum + e > b) break;
            sum += e;
            mxcnt++;
        }
        ans = max(ans, mxcnt * l[i]);
    }
    cout << ans << endl;
}