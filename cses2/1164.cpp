#include <bits/stdc++.h>
using namespace std;

const int MXN = 2e5 + 3;

int n;
multiset<int> rooms;
vector<array<int, 3>> p;
int order[MXN], room[MXN];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b; cin >> a >> b;
        p.push_back({a, b, i});
    }
    iota(order, order + n, 0);
    sort(order, order + n, [](const int &a, const int &b)  {
        return p[a] < p[b];
    });
    int ans = 0;
    for (int xx = 0; xx < n; xx++) {
        auto &[a, b, i] = p[order[xx]];
        auto it = rooms.lower_bound(a);
        if (it == rooms.begin()) {
            rooms.insert(b);
        } else {
            it--;
            rooms.erase(it);
            rooms.insert(b);
        }
        ans = max(ans, (int)rooms.size());
    }
    set<pair<int, int>> r;
    for (int i = 1; i <= ans; i++) r.insert({0, i});
    for (int xx = 0; xx < n; xx++) {
        auto &[a, b, i] = p[order[xx]];
        auto it = r.lower_bound({a, 0});
        assert(it != r.begin());
        it--;
        int ri = it->second;
        r.erase(it);
        r.insert({b, ri});
        room[order[xx]] = ri;
    }
    cout << ans << endl;
    for (int i = 0; i < n; i++) cout << room[i] << ' ';
}