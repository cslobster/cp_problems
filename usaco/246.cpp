#include <bits/stdc++.h>
using namespace std;

const int MX = 1e5 + 2;
int n, m;
vector<int> adj[MX];
int t[MX], ind[MX], d[MX];

int main() {
    ifstream cin("msched.in");
    ofstream cout("msched.out");
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> t[i + 1];
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        ind[b]++;
    }
    priority_queue<pair<int, int>> pq;
    for (int i = 1; i <= n; i++) {
        d[i] = 0x3f3f3f3f;
        if (ind[i] == 0) pq.push({-(d[i] = t[i]), i});
    }
    while (!pq.empty()) {
        auto tp = pq.top();
        pq.pop();
        if (d[tp.second] != -tp.first) continue;
        for (auto ch : adj[tp.second]) {
            ind[ch]--;
            if (ind[ch] == 0 && -tp.first + t[ch] < d[ch]) {
                pq.push({-(d[ch] = t[ch] - tp.first), ch});
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = max(ans, d[i]);
    }
    cout << ans << endl;
}