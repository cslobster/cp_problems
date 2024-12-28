#include <bits/stdc++.h>
using namespace std;

#include <bits/extc++.h>
using namespace __gnu_pbds;

template<class T>
using Tree = tree<T, null_type, less<T>, rb_tree_tag,
    tree_order_statistics_node_update>;

int main() {
    int n, k;
    cin >> n >> k;
    Tree<int> s;
    for (int i = 1; i <= n; i++) s.insert(i);
    int x = k;
    x %= s.size();
    while (!s.empty()) {
        // int child = *s.begin();
        auto it = s.find_by_order(x);
        cout << *it << ' ';
        s.erase(it);
        x += k;
        if (s.empty()) break;
        x %= s.size();
    }
}