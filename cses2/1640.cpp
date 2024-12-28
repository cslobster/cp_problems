#include <bits/stdc++.h>
using namespace std;

const int MXN = 2e5 + 3;

int n, x;
int a[MXN];
map<int, int> mp;

int main() {
    cin >> n >> x;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (mp.count(x - a[i])) {
            cout << mp[x - a[i]] + 1 << " " << i + 1 << endl;
            return 0;
        }
        mp[a[i]] = i;
    }
    cout << "IMPOSSIBLE" << endl;
}