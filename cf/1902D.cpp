#include <bits/stdc++.h>
using namespace std;

const int MXN = 2e5 + 3;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
map<char, int> dc = {{'U', 0}, {'D', 1}, {'L', 3}, {'R', 2}};

int n, q;
string s;
pair<int, int> pre[MXN], suf[MXN];
map<pair<int, int>, vector<int>> mp;

bool check(pair<int, int> p, int l, int r) {
    if (!mp.count(p)) return false;
    auto it = lower_bound(mp[p].begin(), mp[p].end(), l);
    return it != mp[p].end() && *it <= r;
}

int main() {
    cin >> n >> q >> s;
    mp[{0, 0}] = {0};
    for (int i = 1; i <= n; i++) {
        pre[i] = {dx[dc[s[i - 1]]], dy[dc[s[i - 1]]]};
        if (i) pre[i].first += pre[i - 1].first, pre[i].second += pre[i - 1].second;
        mp[pre[i]].push_back(i);
    }
    for (int i = n - 1; i >= 0; i--) {
        suf[i] = {dx[dc[s[i] - 1]], dy[dc[s[i] - 1]]};
        if (i + 1 < n) suf[i].first += suf[i + 1].first, suf[i].second += suf[i + 1].second;
    }
    for (int i = 0; i < q; i++) {
        pair<int, int> p; int l, r;
        cin >> p.first >> p.second >> l >> r;
        pair<int, int> nw = {pre[r].first + pre[l - 1].first - p.first, pre[r].second + pre[l - 1].second - p.second};
        if (check(p, 0, l - 1)) cout << "YES\n";
        else if (check(p, r, n)) cout << "YES\n";
        else if (check(nw, l, r - 1)) cout << "YES\n";
        else cout << "NO\n";
    }
}