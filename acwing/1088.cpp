#include <bits/stdc++.h>
using namespace std;

using ll = long long;
int rem[19];

vector<int> conv(ll a, ll b) {
    vector<int> ans;
    while (a > 0) {
        ans.push_back(a % b);
        a /= b;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

ll f(int i, bool under, vector<int> &targ, int dsum, int r) {
    if (i == targ.size()) {
        return r % 7 == 0 && dsum % 7 == 0;
    }
    ll ans = 0;
    int limit = under ? 9 : targ[i];
    for (int d = 0; d <= limit; d++) {
        if (d == 7) continue;
        int nr = (rem[targ.size() - i] * d) % 7 + r;
        ans += f(i, under || d < targ[i], targ, dsum + d, nr);
    }
    return ans;
}

ll solve(int x) {
    if (x == 0) return 0;
    vector<int> d = conv(x, 10);
    return f(0, false, d, 0, 0);
}

void prep() {
    rem[0] = 1;
    for (int i = 1; i < 19; i++) {
        rem[i] = (3 * rem[i - 1]) % 7;
    }
}

int main() {
    prep();
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;
        cout << solve(b) - solve(a - 1) << endl;
    }
}