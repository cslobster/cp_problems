#include <bits/stdc++.h>
using namespace std;

int digSum(int n) {
    int s = 0;
    while (n != 0) {
        s += n % 10;
        n /= 10;
    }
    return s;
}

int main() {
    int t;
    cin >> t;
    vector<int> q(t);
    int mx = 0;
    for (int i = 0; i < t; i++) {
        cin >> q[i];
        mx = max(mx, q[i]);
    }
    vector<int> dp(mx + 1);
    for (int i = 1; i <= dp.size(); i++) {
        dp[i] = dp[i - 1] + digSum(i);
    }
    for (int i = 0; i < t; i++) {
        cout << digSum(dp[q[i]]) << endl;
    }
}