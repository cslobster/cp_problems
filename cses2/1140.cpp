#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MXN = 2e5 + 3, MXNN = 4e6 + 6;

int n;
int a[MXN][3];
set<ll> c;
unordered_map<ll, int> valToInd;
vector<int> endsHere[MXNN];
ll dp[MXNN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i][0] >> a[i][1] >> a[i][2];
        a[i][1]++;
        c.insert(a[i][0]), c.insert(a[i][1]);
    }
    int ind = 0;
    for (auto e : c) {
        valToInd[e] = ind++;
    }
    for (int i = 0; i < n; i++) {
        endsHere[valToInd[a[i][1]]].push_back(i);
    }
    dp[0] = 0;
    for (int i = 0; i < ind; i++) {
        if (i) {
            dp[i] = dp[i - 1];
        }
        for (auto e : endsHere[i]) {
            dp[i] = max(dp[i], dp[valToInd[a[e][0]]] + a[e][2]);
        }
    }
    cout << dp[ind - 1] << "\n";
}

