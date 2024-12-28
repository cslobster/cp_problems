#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    int n;
    cin >> n;
    vector<int> k(n);
    for (int i = 0; i < n; i++) {
        cin >> k[i];
    }
    stack<int> s;
    vector<int> l(n);
    for (int i = 0; i < n; i++) {
        if (s.empty()) {
            s.push(i);
            l[i] = -1;
        } else {
                while (!s.empty() && k[s.top()] >= k[i]) {
                    s.pop();
                }
                if (s.empty()) {
                    l[i] = -1;
                } else {
                    l[i] = s.top();
                }
            s.push(i);
        }
    }
    vector<int> r(n);
    stack<int> s2;
    for (int i = n - 1; i >= 0; i--) {
        if (s2.empty()) {
            s2.push(i);
            r[i] = n;
        } else {while (!s2.empty() && k[s2.top()] >= k[i]) {
                    s2.pop();
                }
                if (s2.empty()) {
                    r[i] = n;
                } else {
                    r[i] = s2.top();
                }
            s2.push(i);
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans = max(ans, (r[i] - l[i] - 1) * k[i]);
    }
    cout << ans << endl;
}