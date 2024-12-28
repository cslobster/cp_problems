#include <bits/stdc++.h>
using namespace std;

const int MXN = 2e5 + 3;

int n, x;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> x >> n;
    set<int> s;
    multiset<int> sizes;
    s.insert({0, x});
    sizes.insert(x);
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        auto it = s.lower_bound(a);
        auto it2 = it;
        it2--;
        s.insert(a);
        sizes.insert(a - *it2);
        sizes.insert(*it - a);
        sizes.erase(sizes.find(*it - *it2));
        cout << *sizes.rbegin() << endl;
    }
}