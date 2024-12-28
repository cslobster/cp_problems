#include <bits/stdc++.h>
using namespace std;

const int MOD = 2012;

int n;
string s;
map<array<int, 3>, int> mp;
int j = 0;

int f(int i, int h, int g) {
    if (mp.count({i, h, g})) return mp[{i, h, g}];
    if (h < 0 || g < 0) return 0;
    if (i == n && h == 0 && g == 0) return 1;
    return mp[{i, h, g}] = (f(i + 1, h + ((s[i] == '(') ? 1 : -1), g) + f(i + 1, h, g + ((s[i] == '(') ? 1 : -1))) % MOD;
}

int main() {
    ifstream cin("bbreeds.in");
    ofstream cout("bbreeds.out");
    cin >> s;
    n = s.size();
    cout << f(0, 0, 0) << endl;
}