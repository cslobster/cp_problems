#include <bits/stdc++.h>
using namespace std;

const int MXN = 2e5 + 3, MXD = 32;

int n, q;
int up[MXN][MXD];
int where[MXN], cycDist[MXN];
vector<int> adj[MXN];
vector<map<int, int>> cyc;
int cycId = 1;
// -1 is tree, 0 is not processed

void build() {
    for (int j = 1; j < MXD; j++) {
        for (int i = 1; i <= n; i++) {
            up[i][j] = up[up[i][j - 1]][j - 1];
        }
    }
}

int lift(int a, int b) {
    for (int j = 0; j < MXD; j++) {
        if (b & (1 << j)) {
            a = up[a][j];
        }
    }
    return a;
}

int main() {
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        where[i] = 0;
        cin >> up[i][0];
        adj[up[i][0]].push_back(i);
    }
    build();
    cyc.push_back({});
    stack<int> s;
    for (int i = 1; i <= n; i++) {
        if (where[i] != 0) continue;
        int node = i;
        vector<int> path;
        path.push_back(node);
        while (where[up[node][0]] == 0) {
            node = up[node][0];
            where[node] = -3;
            path.push_back(node);
        }
        map<int, int> cycle;
        bool incyc = false;
        for (auto at : path) {
            if (at == up[node][0]) incyc = true;
            if (incyc) cycle[at] = cycle.size();
            where[at] = incyc ? cycId : -1;
        }
        cyc.push_back(cycle);
        cycId++;
    }
    for (int i = 1; i <= n; i++) {
        if (where[i] != -1 || where[up[i][0]] == -1) continue;
        cycDist[i] = 1;
        vector<int> st(adj[i]);
        while (!st.empty()) {
            auto tp = st.back();
            st.pop_back();
            cycDist[tp] = cycDist[up[tp][0]] + 1;
            st.insert(st.end(), adj[tp].begin(), adj[tp].end());
        }
    }
    for (int i = 0; i < q; i++) {
        int a, b; cin >> a >> b;
        if (where[up[a][MXD - 1]] != where[up[b][MXD - 1]]) {
            cout << "-1\n"; continue;
        }
        if (where[a] != -1 || where[b] != -1) {
            if (where[a] != -1 && where[b] == -1) {
                cout << "-1\n"; continue;
            }
            int dist = cycDist[a];
            int acyc = lift(a, cycDist[a]);
            map<int, int> &cycle = cyc[where[acyc]];
            int aI = cycle[acyc];
            int bI = cycle[b];
            int temp = (aI <= bI) ? bI - aI : cycle.size() - (aI - bI);
            cout << dist + temp << endl;
        } else {
            if (cycDist[b] > cycDist[a]) {
                cout << "-1\n"; continue;
            }
            int temp = cycDist[a] - cycDist[b];
            cout << ((lift(a, temp) == b) ? temp : -1) << "\n";
        }
    }
}