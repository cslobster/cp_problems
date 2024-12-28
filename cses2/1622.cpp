#include <bits/stdc++.h>
using namespace std;

int main() {
    string s; cin >> s;
    vector<char> a;
    for (auto c : s) a.push_back(c);
    sort(a.begin(), a.end());
    vector<vector<char>> perms;
    do {
        perms.push_back(a);
    } while (next_permutation(a.begin(), a.end()));
    cout << perms.size() << endl;
    for (auto f : perms) {
        for (auto e : f) {
            cout << e;
        }
        cout << endl;
    }
}