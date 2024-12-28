#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> ans;

void f(int n, int a, int b, int c) {
    if (n == 1) {
        ans.push_back({a, c}); return;
    }
    f(n - 1, a, c, b);
    ans.push_back({a, c});
    f(n - 1, b, a, c);
}

int main() {
    int n;
    cin >> n;
    f(n, 1, 2, 3);
    cout << ans.size() << endl;
    for (auto e : ans) {
        cout << e.first << " " << e.second << endl;
    }
}