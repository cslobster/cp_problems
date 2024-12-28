#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MXN = 1e5 + 3, MOD = 1e9 + 7;

int n;
map<int, set<int>> label;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        label[a].insert(i);
    }
    vector<int> ans(n + 1, 0);
    for (auto &[l, v] : label) {
        for (int x = n; x >= 1; x--) {
            int cur = 0;
            int prev = *v.begin();
            while (true) {
                cur++;
                auto it = v.upper_bound(prev + x);
                if (it == v.end()) break;
                prev = *it;
            }
            ans[x] += cur;
        }
    }
    for (int i = 1; i <= n; i++) cout << ans[i] << endl;
}