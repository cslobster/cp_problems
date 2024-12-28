#include <bits/stdc++.h>
using namespace std;

#include <bits/extc++.h>
using namespace __gnu_pbds;

template<class T>
using Tree = tree<T, null_type, less<T>, rb_tree_tag,
    tree_order_statistics_node_update>;

const int MXN = 2e5 + 3;

int n;
pair<int, int> ranges[MXN];
int order1[MXN], order2[MXN], ans1[MXN], ans2[MXN];


int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> ranges[i].first >> ranges[i].second;
    }
    iota(order1, order1 + n, 0);
    sort(order1, order1 + n, [](const int &a, const int &b) {
        if (ranges[a].first != ranges[b].first) return ranges[a].first > ranges[b].first;
        return ranges[a].second < ranges[b].second;
    });
    Tree<pair<int, int>> tree;
    for (int i = 0; i < n; i++) {
        auto &[a, b] = ranges[order1[i]];
        ans1[order1[i]] = tree.order_of_key({b, INT_MAX});
        tree.insert({b, i});
    }
    for (int i = 0; i < n; i++) cout << (ans1[i] > 0) << " ";
    cout << endl;
    iota(order2, order2 + n, 0);
    sort(order2, order2 + n, [](const int &a, const int &b) {
        if (ranges[a].second != ranges[b].second) return ranges[a].second > ranges[b].second;
        return ranges[a].first <ranges[b].first;
    });
    Tree<pair<int, int>> tree2;
    for (int i = 0; i < n; i++) {
        auto &[a, b] = ranges[order2[i]];
        ans2[order2[i]] = tree2.order_of_key({a, INT_MAX});
        tree2.insert({a, i});
    }
    for (int i = 0; i < n; i++) cout << (ans2[i] > 0) << " ";

}