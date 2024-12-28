#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MXN = 2e5 + 3;

int n, k;
int x[MXN];

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> x[i];
    ll ans = 0, cnt = 0;
    map<int, int> mp;
    for (int l = 0, r = 0; l < n; l++) {
        while (r < n && cnt + (mp[x[r]] == 0) <= k) {
            mp[x[r]]++;
            cnt += (mp[x[r]] == 1);
            r++;
        }
        ans += r - l;
        cnt -= (mp[x[l]] == 1);
        mp[x[l]]--;
    }
    cout << ans << endl;
}