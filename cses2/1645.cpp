#include <bits/stdc++.h>
using namespace std;

const int MXN = 2e5 + 3;

int n;
int x[MXN], ans[MXN];
map<int, vector<int>> mp;
set<int> s;

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {cin >> x[i]; mp[x[i]].push_back(i);}
    for (auto k : mp) {
        for (auto i : k.second) {
            auto it = s.lower_bound(i);
            if (it == s.begin()) {
                ans[i] = 0;
            } else {
                it--;
                ans[i] = *it;
            }
        }
        for (auto i : k.second) {
            s.insert(i);
        }
    }
    for (int i = 1; i <= n; i++) cout << ans[i] << " ";
}