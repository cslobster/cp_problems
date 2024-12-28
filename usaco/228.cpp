#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream cin("invite.in");
    ofstream cout("invite.out");
    int n, g;
    cin >> n >> g;
    vector<set<int>> groups(g);
    vector<vector<int>> inv(n + 1);
    for (int i = 0; i < g; i++) {
        int s; cin >> s;
        for (int j = 0; j < s; j++) {
            int a; cin >> a;
            groups[i].insert(a);
            inv[a].push_back(i);
        }
    }
    queue<int> q;
    q.push(1);
    int cnt = 0;
    vector<int> vis(n + 1);
    vis[1] = 1;
    while (!q.empty()) {
        int tp = q.front();
        q.pop();
        cnt++;
        for (auto i : inv[tp]) {
            groups[i].erase(tp);
            if (groups[i].size() == 1 && !vis[*groups[i].begin()]) {
                vis[*groups[i].begin()] = 1;
                q.push(*groups[i].begin());
            }
        }
    }
    cout << cnt << endl;
}