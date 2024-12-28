#include <bits/stdc++.h>
using namespace std;

const int MX = 1e5 + 1;

struct Cow {
    int g, d;
};

bool operator<(const Cow &a, const Cow &b) {
    return a.g > b.g;
}

int main() {
    ifstream cin("msched.in");
    ofstream cout("msched.out");
    int n;
    cin >> n;
    vector<Cow> c(n);
    for (int i = 0; i < n; i++) {
        cin >> c[i].g >> c[i].d;
    }
    sort(c.begin(), c.end());
    int ans = 0, cnt = 0;
    bool taken[MX];
    for (auto cow : c) {
        int i = cow.d;
        while (i > 0 && taken[i]) {
            i--;
        }
        if (i == 0) continue;
        ans += cow.g;
        taken[i] = true;
        cnt++;
    }
    cout << ans << endl;
}