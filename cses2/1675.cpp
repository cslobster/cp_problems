#include <bits/stdc++.h>
using namespace std;

int main() {
    for (int i = 1; i <= n; i++) dist[i] = LLONG_MAX;
    dist[1] = 0;
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    pq.push({0LL, 1});
    while (!pq.empty()) {
        auto tp = pq.top();
        pq.pop();
        if (tp.first != dist[tp.second]) continue;
        for (auto ch : adj[tp.second]) {
            if (ch.second + tp.first < dist[ch.first]) {
                pq.push({dist[ch.first] = ch.second + tp.first, ch.first});
            }
        }
    }
}