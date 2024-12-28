#include <bits/stdc++.h>
using namespace std;

vector<int> par;

int getPar(int a) {
    if (par[a] == a) return a;
    return par[a] = getPar(par[a]);
}

void merge(int a, int b) {
    a = getPar(a);
    b = getPar(b);
    if (a == b) return;
    par[a] = b;
}

int main() {
    int n, m, q;
    cin >> n >> m >> q;
    par.resize(n + 1);
    vector<pair<int, int>> roads(m);
    vector<set<int>> queries(n + 1);
    for (int i = 0; i < m; i++) {
        cin >> roads[i].first >> roads[i].second;
    }

    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        queries[a].insert(b);
        queries[b].insert(a);
    }

   for (int i = 0; i < m; i++) {
       auto& [u, v] = roads[i];
       merge(u, v);
       f
   }
}