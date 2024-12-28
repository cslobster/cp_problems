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
        if (i == n - 1) {
            st.push_back(i);
            continue;
        }
        while (!st.empty() && a[st.back()] > a[i]) {
            st.pop_back();
        }
        st.push_back(i);
        for (int j = st.size() - 2; j >= 0; j--) {
            reduce[st[j] - i] += a[st[j + 1]] - a[st[j]];
        }
    }
    for (int i = 1; i <= n; i++) {
        sum -= reduce[i];
        cout << sum << endl;
    }
}
