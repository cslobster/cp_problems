#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MXN = 2e5 + 3;

struct Job {
    ll s, t;
};

int n;
Job jobs[MXN];

bool operator<(const Job &a, const Job &b) {
    if (a.s != b.s) return a.s < b.s;
    return a.t < b.t;
}

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> jobs[i].s >> jobs[i].t;
        jobs[i].s += jobs[i].t;
    }
    sort(jobs, jobs + n);
    priority_queue<ll> pq;
    ll tot = 0;
    for (int i = 0; i < n; i++) {
        auto &[s, t] = jobs[i];
        pq.push(t);
        tot += t;
        if (tot > s) {
            tot -= pq.top();
            pq.pop();
        }
    }
    cout << pq.size() << endl;
}

int main() {
    int t; cin >> t;
    while (t--) solve();
}