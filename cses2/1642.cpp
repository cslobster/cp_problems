#include <bits/stdc++.h>
using namespace std;

const int MXN = 1003;

int n, x;
int a[MXN], order[MXN];
map<int, pair<int, int>> mp;

int main() {
    cin >> n >> x;
    for (int i = 0; i < n; i++) cin >> a[i];
    iota(order, order + n, 0);
    sort(order, order + n, [](const int &aa, const int &bb){return a[aa] < a[bb];});
    for (int ind = 0; ind < n; ind++) {
        for (int ind2 = ind + 1; ind2 < n; ind2++) {
            int i = order[ind], j = order[ind2];
            if (mp.count(x - a[i] - a[j])) {
                int k = mp[x - a[i] - a[j]].first, l = mp[x - a[i] - a[j]].second;
                if (k != i && l != i && k != j && l != j) {
                    cout << i + 1 << " " << j + 1 << " " << k + 1
                        << " " << l + 1 << endl;
                    return 0;
                }
            }
            mp[a[i] + a[j]] = {i, j};
        }
    }
    cout << "IMPOSSIBLE\n";
}