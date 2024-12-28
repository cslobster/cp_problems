#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MXN = 5e5 + 3;

int n;
ll a[MXN], reduce[MXN];
vector<ll> st;
ll sum;

int main() {
    // ifstream cin("test.in");
    // ofstream cout("test.out");
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    sum = accumulate(a, a + n, 0LL);
    rotate(a, next(min_element(a, a + n)), a + n);
    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && a[st.back()] >= a[i]) {
            if (st.size() > 1) {
                ll amt = a[st.back()] - a[st[st.size() - 2]];
                reduce[st[st.size() - 2] - st.back()] += amt;
                reduce[st[st.size() - 2] - i] -= amt;
            }
            st.pop_back();
        }
        st.push_back(i);
    }
    while (!st.empty()) {
        if (st.size() > 1) {
            ll amt = a[st.back()] - a[st[st.size() - 2]];
            reduce[st[st.size() - 2] - st.back()] += amt;
            reduce[st[st.size() - 2] + 1] -= amt;
        }
        st.pop_back();
    }
    for (int i = 1; i <= n; i++) {
        reduce[i] += reduce[i - 1];
        sum -= reduce[i];
        cout << sum << endl;
    }
}
