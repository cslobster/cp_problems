#include <bits/stdc++.h>
using namespace std;

#define int long long

const int MX = 1e16;

signed main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;
        map<pair<int, int>, int> room;
        vector<vector<int>> in(k);
        int cnt = 0;
        vector<int> x(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> x[i];
        }
        vector<vector<int>> rooms(n + 1);
        for (int i = 0; i < k; i++) {
            int a, b, c, d, h;
            cin >> a >> b >> c >> d >> h;
            in[i] = {a, b, c, d, h};
            if (!room.count({a, b})) {
                room[{a, b}] = cnt;
                cnt++;
                rooms[a].push_back(b);
            }
            if (!room.count({c, d})) {
                room[{c, d}] = cnt;
                cnt++;
                rooms[c].push_back(d);
            }
        }
        if (!room.count({1, 1})) {
            room[{1, 1}] = cnt;
            cnt++;
            rooms[1].push_back(1);
        }
        if (!room.count({n, m})) {
            rooms[n].push_back(m);
            room[{n, m}] = cnt;
            cnt++;
        }
        for (int i = 1; i <= n; i++) {
            sort(rooms[i].begin(), rooms[i].end());
        }
        vector<vector<pair<int, int>>> adj(cnt);
        for (int i = 0; i < k; i++) {
            vector<int> v = in[i];
            adj[room[{v[0], v[1]}]].push_back({room[{v[2], v[3]}], -v[4]});
        }

        int st = room[{1, 1}], ed = room[{n, m}];
        vector<int> dist(cnt, MX);
        dist[st] = 0;
        for (int i = 1; i <= n; i++) {
            priority_queue<pair<int, int>> pq;
            for (auto j : rooms[i]) {
                int idx = room[{i, j}];
                if (dist[idx] == MX) continue;
                pq.push({-dist[idx], j});
            }
            while (!pq.empty()) {
                auto tp = pq.top();
                pq.pop();
                int tpi = room[{i, tp.second}];
                if (-tp.first != dist[tpi]) continue;
                auto it = lower_bound(rooms[i].begin(), rooms[i].end(), tp.second);
                if (it != rooms[i].begin()) {
                    auto prev = it; prev--;
                    int idx = room[{i, *prev}];
                    if (-tp.first + abs(tp.second - *prev) * x[i] < dist[idx]) {
                        dist[idx] = -tp.first + abs(tp.second - *prev) * x[i];
                        pq.push({-dist[idx], *prev});
                    }
                }
                auto nxt = it; nxt++;
                if (nxt != rooms[i].end()) {
                    int idx = room[{i, *nxt}];
                    if (-tp.first + abs(tp.second - *nxt) * x[i] < dist[idx]) {
                        dist[idx] = -tp.first + abs(tp.second - *nxt) * x[i];
                        pq.push({-dist[idx], *nxt});
                    }
                }
            }
            for (auto j : rooms[i]) {
                int idx = room[{i, j}];
                if (dist[idx] == MX) continue;
                for (auto& ch : adj[idx]) {
                    dist[ch.first] = min(dist[ch.first], dist[idx] + ch.second);
                }
            }
        }
        if (dist[ed] == MX) cout << "NO ESCAPE\n";
        else cout << dist[ed] << "\n";
    }
}