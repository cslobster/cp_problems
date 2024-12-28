#include <bits/stdc++.h>
using namespace std;

const int MXN = 1e6 + 3, inf = 1e9 + 3;

int n;
int h[MXN], ans[MXN];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> h[i];
    }

    multiset<pair<int, int>> s;
    for (int i = n; i >= 1; i--) {
        auto ub = s.upper_bound({h[i], inf});
        if (ub == s.end()) ans[i] = n + 1;
        else {
            ub = next(ub);
            if (ub == s.end()) ans[i] = n + 1;
            else ans[i] = ub->second;
        }
        s.insert({h[i], i});
    }
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << endl;
    }
}