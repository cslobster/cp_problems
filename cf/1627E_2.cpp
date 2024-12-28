#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
//    ifstream cin("test.txt");
    int t;
    cin >> t;
//    if (t == 4) {
//        cout << "16\nNO ESCAPE\n-90\n27\n"; return 0;
//    }
//    t = 1;
    int xxxx =4;
    while (t--) {
        xxxx++;

        int n, m, k;
        cin >> n >> m >> k;
        map<pair<int, int>, int> room;
//        map<int, pair<int, int>> ind;
        vector<vector<int>> in(k);
        int cnt = 0;
        vector<int> x(n + 1);
        if (xxxx==4) cout << n << " " << m << ' ' << k << endl;
        for (int i = 1; i <= n; i++) {
            cin >> x[i];
            if (xxxx==4) cout << x[i] << " ";
        }
        if (xxxx==4) cout << endl;
        vector<vector<int>> rooms(n + 1);
        vector<vector<int>> aa(n + 1);
        vector<bool> dp(n + 1);
        for (int i = 0; i < k; i++) {
            int a, b, c, d, h;
            cin >> a >> b >> c >> d >> h;
            in[i] = {a, b, c, d, h};
            if (!room.count({a, b})) {
                room[{a, b}] = cnt;
//            ind[cnt] = {a, b};
                cnt++;
                rooms[a].push_back(b);
            }
            if (!room.count({c, d})) {
                room[{c, d}] = cnt;
//            ind[cnt] = {c, d};
                cnt++;
                rooms[c].push_back(d);
            }
            aa[a].push_back(c);
            if (xxxx==4) cout << a<<' '<<b<<' '<<c<<" "<<d<<" " << h << endl;
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
//            ind[cnt] = {1, 1};
            cnt++;
            rooms[1].push_back(1);
        }
        if (!room.count({n, m})) {
            rooms[n].push_back(m);
            room[{n, m}] = cnt;
//            ind[cnt] = {n, m};
            cnt++;
        }
        vector<vector<pair<int, int>>> adj(cnt);
        for (int i = 0; i < k; i++) {
            vector<int> v = in[i];
            adj[room[{v[0], v[1]}]].push_back({room[{v[2], v[3]}], -v[4]});
        }

        int st = room[{1, 1}], ed = room[{n, m}];
        vector<int> dist(cnt, 1e16 + 1);
        dist[st] = 0;
        for (int i = 1; i <= n; i++) {
            priority_queue<pair<int, int>> pq;
            for (auto j : rooms[i]) {
                int idx = room[{i, j}];
                pq.push({-dist[idx], j});
            }
            while (!pq.empty()) {
                auto tp = pq.top();
                pq.pop();
                int tpi = room[{i, tp.second}];
                if (-tp.first != dist[tpi]) continue;
                for (auto ch : rooms[i]) {
                    if (ch == tp.second) continue;
                    int idx = room[{i, ch}];
                    if (-tp.first + abs(tp.second - ch) * x[i] < dist[idx]) {
                        dist[idx] = -tp.first + abs(tp.second - ch) * x[i];
                        pq.push({-dist[idx], ch});
                    }
                }
            }
            for (auto j : rooms[i]) {
                int idx = room[{i, j}];
                for (auto ch : adj[idx]) {
                    dist[ch.first] = min(dist[ch.first], dist[idx] + ch.second);
                }
            }
        }
//        cout << n << ' ' << m << " "<< k << "\t";
//        for (int i = 0; i < cnt; i++) {
//            cout << dist[i] << " ";
//        }
        cout << dist[ed] << endl;
//        cout << "XXXXX: " << xxxx<<endl;
    }
}