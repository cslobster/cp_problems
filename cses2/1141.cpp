#include <bits/stdc++.h>
using namespace std;

const int MXN = 2e5 + 3;

int n;
int k[MXN];
map<int, int> mp;

int main() {
    cin >> n;
    int ans = 0, first = 0;
    for (int i = 0; i < n; i++) {
        cin >> k[i];
        if (mp.count(k[i])) {
            // restart at mp[k[i]] + 1
            first = max(first, mp[k[i]] + 1);
        }
        ans = max(ans, i - first + 1);

        mp[k[i]] = i;
    }
    cout << ans << endl;
}