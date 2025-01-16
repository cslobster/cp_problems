/*
 * how many pairs of inns of the same color are there such that in between the inns is a value >= p
 * for each color, store each inn
 * for each inn, store last index to the right with value >= p
 * for each inn of each color, binary search on inns of the same color
 * to count how many have index <= calculated index
 */

#include <bits/stdc++.h>
using namespace std;

const int MXN = 2e6 + 5, MXK = 101;

using ll = long long;

int n, kkk, p;
ll a[MXN], b[MXN], last[MXN];
map<int, vector<int>> occ;

int cnt[MXN];

int main() {
    // ifstream cin("in.in");
    cin >> n >> kkk >> p;
    int ind = -1;
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
        if (b[i] <= p) ind = i;
        last[i] = ind;
        occ[a[i]].push_back(i);
    }
    ll ans = 0;
    for (auto &[k, v] : occ) {
        vector<int> ss;
        for (int i = 0; i < v.size(); i++) {
            auto it = upper_bound(ss.begin(), ss.end(), last[v[i]]);
            ans += it - ss.begin();
            ss.push_back(v[i]);
        }
    }
    cout << ans << endl;
}