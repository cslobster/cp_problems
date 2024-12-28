#include <bits/stdc++.h>
using namespace std;

const int MXN = 2e5 + 3;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

template<class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int n;
int l[MXN], r[MXN], k[MXN], ans[MXN], kOrder[MXN], lenOrder[MXN];

int main() {
    ifstream cin("test.in");
    ofstream cout("test.out");
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> l[i] >> r[i] >> k[i];
    }
    iota(kOrder, kOrder + n, 0);
    sort(kOrder, kOrder + n, [](const int &a, const int &b) {
        return k[a] > k[b];
    });
    iota(lenOrder, lenOrder + n, 0);
    sort(lenOrder, lenOrder + n, [](const int &a, const int &b) {
        return l[a] - r[a] < l[b] - r[b];
    });
    Tree<array<int, 2>> left, right;
    for (int i = 0, j = 0; i < n; i++) {
        while (j < n && r[lenOrder[j]] - l[lenOrder[j]] >= k[kOrder[i]]) {
            left.insert({l[lenOrder[j]], j});
            right.insert({r[lenOrder[j]], j});
            j++;
        }
        int sum = j - 1;
        sum -= j - left.order_of_key({r[kOrder[i]] - k[kOrder[i]] + 1, -1});
        sum -= right.order_of_key({l[kOrder[i]] + k[kOrder[i]], -1});
        ans[kOrder[i]] = sum;
    }
    for (int i = 0; i < n; i++) {
        cout << ans[i] << endl;
    }
}