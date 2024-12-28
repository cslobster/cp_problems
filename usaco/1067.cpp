#include <bits/stdc++.h>
using namespace std;

struct Cow {
    int x, y;
};

bool operator<(const Cow &a, const Cow &b) {
    return a.x < b.x;
}

int n;
Cow cows[201];
int ans = 0;
int squares = 0;

void solve() {
    sort(cows, cows + n);
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            auto &a = cows[i], &b = cows[j];
            int w = b.x - a.x;
            set<int> c;
            for (int k = i + 1; k < j; k++) {
                c.insert(cows[k].y);
            }

        }
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> cows[i].x >> cows[i].y;
    }
    solve();
    for (int i = 0; i < n; i++) {
        swap(cows[i].x, cows[i].y);
    }
    solve();

}