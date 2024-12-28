#include <bits/stdc++.h>
using namespace std;

const int MXN = 2e5 + 3;

int n, k;
pair<int, int> movies[MXN];

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> movies[i].first >> movies[i].second;
    }
    multiset<int> s;
    sort(movies, movies + n, [](const pair<int, int> &a, const pair<int, int> &b) {
        if (a.second != b.second) return a.second < b.second;
        return a.first < b.first;
    });
    int ans = 0;
    for (int i = 0; i < k; i++) s.insert(0);
    for (int i = 0; i < n; i++) {
        auto &[st, ed] = movies[i];
        auto it = s.upper_bound(st);
        if (it == s.begin()) continue;
        it--;
        s.erase(it);
        s.insert(ed);
        ans++;
    }
    cout << ans << endl;
}