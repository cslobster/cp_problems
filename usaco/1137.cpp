#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template <class T>
using Tree =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

using ll = long long;

int main() {
    int n;
    cin >> n;
    vector<int> b(n);
    vector<int> lastInd(n + 1, -1);
    ll ans = 0;
    Tree<pair<int, int>> s;
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        int botLim = lastInd[b[i]];
        int ind = s.order_of_key({-botLim, 0});
        ans += ind;
        if (lastInd[b[i]] != -1)
            s.erase({-(lastInd[b[i]]), b[i]});
        s.insert({-(lastInd[b[i]] = i), b[i]});
    }
    cout << ans << endl;
}