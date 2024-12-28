#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;
        map<pair<int, int>, int> room;
        map<int, pair<int, int>> ind;
        vector<vector<int>> in(k);
        int cnt = 0;
        vector<int> x(n + 1);
        for (int i = 1; i <= n; i++) cin >> x[i];
        vector<vector<int>> rooms(n + 1);
        vector<vector<int>> aa(n + 1);
        vector<bool> dp(n + 1);
        for (int i = 0; i < k; i++) {
            int a, b, c, d, h;
            cin >> a >> b >> c >> d >> h;
            in[i] = {a, b, c, d, h};
            room[{a, b}] = cnt;
            ind[cnt] = {a, b};
            cnt++;
            room[{c, d}] = cnt;
            ind[cnt] = {c, d};
            cnt++;
            rooms[a].push_back(b);
            rooms[c].push_back(d);
            aa[a].push_back(c);
        }
        dp[1] = true;
        for (int i = 1; i <= n; i++) {
            for (auto ch : aa[i]) {
                dp[ch] = dp[ch] || dp[i];
            }
        }
        if (!dp[n]) {
            cout << "NO ESCAPE" << endl;
            continue;
        }
        if (!room.count({1, 1})) {
            room[{1, 1}] = cnt;
            ind[cnt] = {1, 1};
            cnt++;
            rooms[1].push_back(1);
        }
        if (!room.count({n, m})) {
            rooms[n].push_back(m);
            room[{n, m}] = cnt;
            ind[cnt] = {n, m};
            cnt++;
        }
        int st = room[{1, 1}], ed = room[{n, m}];
        vector<vector<pair<int, int>>> adj(cnt);
//        vector<int> p(cnt);
//        for (int i = 0; i < cnt; i++) {
//            p[i] = -ind[i].first * 1e6;
//        }
        for (int i = 0; i < k; i++) {
            vector<int> v = in[i];
            adj[room[{v[0], v[1]}]].push_back({room[{v[2], v[3]}], -v[4]});
        }
//        for (int i = 0; i < cnt; i++) {
//            for (auto &e : adj[i]) e.second += p[i] - p[e.first];
//        }
        for (int i = 1; i <= n; i++) {
            sort(rooms[i].begin(), rooms[i].end());
            for (int j = 0; j < (int)rooms[i].size() - 1; j++) {
                adj[room[{i, rooms[i][j]}]].push_back({room[{i, rooms[i][j + 1]}],
                                                       (rooms[i][j + 1] - rooms[i][j]) * x[i]});

                adj[room[{i, rooms[i][j + 1]}]].push_back({room[{i, rooms[i][j]}],
                                                           (rooms[i][j + 1] - rooms[i][j]) * x[i]});
            }
        }
        priority_queue<pair<int, int>> pq;
        vector<int> dist(cnt, LONG_LONG_MAX);
        pq.push({0, st});
        dist[st] = 0;
        bool found = false;
        while (!pq.empty()) {
            auto tp = pq.top();
            pq.pop();
            if (tp.second == cnt - 1) found = true;
//            if (dist[tp.second] != -tp.first) continue;
            for (auto ch : adj[tp.second]) {
                if (ch.second - tp.first < dist[ch.first]) {
                    pq.push({-(dist[ch.first] = ch.second - tp.first), ch.first});
                }
            }
        }
//        if (dist[cnt - 1] == 0x3f3f3f3f) {
//            cout << "N : " << n << " " << rooms[1].size() << "  ";
//            for (int j = 0; j < (int)rooms[1].size() - 1; j++) {
//                cout << room[{1, rooms[1][j]}] << "," << rooms[1][j]
//                << " " << room[{1, rooms[1][j + 1]}] << "," << rooms[1][j + 1] << "\t";
//            }
//            cout << endl;
//        }
        cout << dist[ed] << endl;
    }
}