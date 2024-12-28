#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MX = 2e5 + 10;
int n, p;
vector<pair<int, ll>> adj[MX];
set<pair<int, int>> l;
vector<array<int, 3>> v;

map<array<int, 3>, int> mp;
map<int, array<int, 3>> idx;

ll dist[MX];

int dst(int i, int j) {
    return abs(idx[i][0] - idx[j][0]) + abs(idx[i][1] - idx[j][1]);
}

int main() {
    ifstream cin("boards.in");
    ofstream cout("boards.out");
    cin >> n >> p;
    int id = 0;
    idx[id] = {0, 0, 0};
    mp[{0, 0, 0}] = 0;
    v.push_back({0, 0, id++});
    for (int i = 0; i < p; i++) {
        int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
        v.push_back({x1, y1, id});
        adj[id].push_back({id + 1, 0});
        idx[id] = {x1, y1, 0};
        mp[{x1, y1, 0}] = id++;
        v.push_back({x2, y2, id});
        idx[id] = {x2, y2, 1};
        mp[{x2, y2, 1}] = id++;
    }
    idx[id] = {n, n, 0};
    mp[{n, n, 0}] = id;
    v.push_back({n, n, id++});
    sort(v.begin(), v.end(), [](const array<int, 3> &a, const array<int, 3> &b) {
        return a[0] > b[0];
    });
    for (auto &[x, y, i] : v) {
        auto it = l.lower_bound({y, 0});
        if (it == l.end()) {
            l.insert({y, i});
            continue;
        }
        adj[i].push_back({it->second, dst(it->second, i)});
        l.insert({y, i});
    }
    l.clear();
    sort(v.begin(), v.end(), [](const array<int, 3> &a, const array<int, 3> &b) {
            return a[1] > b[1];
        });
    for (auto &[x, y, i] : v) {
        auto it = l.lower_bound({x, 0});
        if (it == l.end()) {
            l.insert({x, i});
            continue;
        }
        adj[i].push_back({it->second, dst(it->second, i)});
        l.insert({x, i});
    }

    priority_queue<pair<int, int>> pq;
    for (int i = 1; i < id; i++) dist[i] = 1e18;
    pq.push({0, 0});
    while (!pq.empty()) {
        auto tp = pq.top();
        pq.pop();
        if (-tp.first != dist[tp.second]) continue;
        for (auto ch : adj[tp.second]) {
            if (-tp.first + ch.second < dist[ch.first]) {
                pq.push({-(dist[ch.first] = ch.second - tp.first), ch.first});
            }
        }
    }
    for (int i = 1; i < id; i++) {
        cout << dist[i] << endl;
    }
    cout << dist[id - 1] << endl;
}