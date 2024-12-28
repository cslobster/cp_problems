#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int a, b, n;
vector<int> routes[1001];
vector<pair<int, int>> inv[1001];

ll dst[1001], cost[1001], cnt[1001];

struct State {
    int n;
};

bool operator<(const State &a, const State &b) {
    if (dst[a.n] != dst[b.n]) return dst[a.n] < dst[b.n];
    return cnt[a.n] < cnt[b.n];
}

priority_queue<State> pq;

int main() {
    ifstream cin("cowroute.in");
    ofstream cout("cowroute.out");
    cin >> a >> b >> n;
    for (int i = 0; i < n; i++) {
        int k; cin >> cost[i] >> k;
        for (int j = 0; j < k; j++) {
            int x; cin >> x;
            routes[i].push_back(x);
            inv[x].push_back({i, j});
        }
    }
    for (int i = 1; i <= 1000; i++) dst[i] = 1e18;
    dst[a] = 0, cnt[a] = 0;
    pq.push({a});
    while (!pq.empty()) {
        auto tp = pq.top();
        pq.pop();
        if (tp.n == b) continue;
        for (auto &[i, j] : inv[tp.n]) {
            for (int x = j; x < routes[i].size(); x++) {
                int y = routes[i][x];
                if (dst[y] > dst[tp.n] + cost[i]) {
                    cnt[y] = cnt[tp.n] + x - j;
                    dst[y] = dst[tp.n] + cost[i];
                    if (y == b) {
                        // cout << cnt[y] << " " << tp.n << endl;
                    }
                    pq.push({y});
                }
                if (dst[y] == dst[tp.n] + cost[i]) {
                    // cout << tp.n << " " << y << " " << cnt[y] << " " << cnt[tp.n] + x - j << endl;
                    if (cnt[y] > cnt[tp.n] + x - j) {
                        cnt[y] = cnt[tp.n] + x - j;
                        if (y == b) {
                            // cout << cnt[y] << " " << tp.n << endl;
                        }
                        pq.push({y});
                    } else {
                        // cout << "FAIL: " << dst[y] << " " << "FROM: " << " " << tp.n << " " << cnt[y] << endl;
                    }
                }
            }
        }
    }
    if (dst[b] == 1e18) cout << "-1 -1\n";
    else cout << dst[b] << " " << cnt[b] << endl;
}