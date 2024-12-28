#include <bits/stdc++.h>
using namespace std;

int n;
vector<string> ans;

vector<string> f(int i) {
    if (i == 1) return {"0", "1"};
    vector<string> p = f(i - 1);
    vector<string> cur;
    for (auto s : p) {
        cur.push_back("0" + s);
    }
    reverse(p.begin(), p.end());
    for (auto s : p) {
        cur.push_back("1" + s);
    }
    return cur;
}

int main() {
    cin >> n;
    ans = f(n);
    for (auto e : ans) {
        cout << e << endl;
    }
}