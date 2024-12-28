#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MXN = 2e5 + 2;
const ll MX = 1e18 + 2;

struct Event {
    ll q, t, x, n;
};

struct Cow {
    ll x, t, n;
};

bool operator<(const Event &a, const Event &b) {
    if (a.t != b.t) return a.t < b.t;
    return a.q < b.q;
}

bool operator<(const Cow &a, const Cow &b) {
    if (a.x != b.x) return a.x < b.x;
    return a.t < b.t;
}

int n;
Event events[MXN];
set<Cow> bst;

int main() {
    // ifstream cin("test.in");
    // ofstream cout("test.out");
    cin >> n;
    for (int i = 0; i < n; i++) {
        int q, t, x, n; cin >> events[i].q >> t >> x >> events[i].n;
        events[i].x = t + x, events[i].t = t - x;
    }
    sort(events, events + n);

    int ans = 0;
    for (int i = 0; i < n; i++) {
        auto &[q, t, x, n] = events[i];
        if (q == 1) {
            bst.insert({x, t, n});
        } else {
            if (bst.empty()) continue;
            // biggest x < apple x
            int lft = n;
            while (lft > 0) {
                auto it = bst.upper_bound({x, MX, MX});
                if (it == bst.begin()) break;
                it--;
                assert(it->x <= x);
                if (lft - it->n >= 0) {
                    lft -= it->n;
                    ans += it->n;
                    bst.erase(it);
                } else {
                    Cow c = {it->x, it->t, it->n - lft};
                    ans += lft;
                    lft = 0;
                    bst.erase(it);
                    bst.insert(c);
                }
            }
        }
    }
    cout << ans << endl;
}