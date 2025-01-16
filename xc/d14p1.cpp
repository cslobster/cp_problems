/*
 * queries can either remove an edge, add an edge, remove all edges pointing to a node, repair all those edges
 * win condition is valid in a circle tree (all outdegree = 1)
 * countable by having a running sum, hash each node value
 * add all sum of the edges (technically same as outdegree sum)
 * where the weight of the edge is a random number, should equal total if all outdegree = 1
 * also store sum of weights for edges pointing to each node
 *
 * tl;dr hash edge weights, set to 0 if edge destroyed
 * to remove edge: set edge weight = 0
 * to add edge: set edge weight to default value
 * to remove edges: set node sum = 0
 * to add edges: set node sum = defaults
 */

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MXN = 5e5 + 3;

std::random_device dev;
std::mt19937 rng(dev());
std::uniform_int_distribution<std::mt19937::result_type> randnum((long long)1e4,(long long)1e9); // distribution in range [1, 6]

int n, m, q;
ll val[MXN], d[MXN], ogd[MXN];
vector<int> adj[MXN];

int main() {
    cin >> n >> m;
    ll sum = 0, cur = 0;
    for (int i = 1; i <= n; i++) {
        val[i] = randnum(dev);
        sum += val[i];
    }
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        d[b] += val[a];
        ogd[b] += val[a];
        cur += val[a];
    }
    cin >> q;
    for (int i = 0; i < q; i++) {
        int t; cin >> t;
        if (t == 1) {
            int a, b; cin >> a >> b;
            d[b] -= val[a];
            cur -= val[a];
        } else if (t == 2) {
            int a; cin >> a;
            cur -= d[a];
            d[a] = 0;
        } else if (t == 3) {
            int a, b; cin >> a >> b;
            d[b] += val[a];
            cur += val[a];
        } else if (t == 4) {
            int a; cin >> a;
            cur -= d[a];
            d[a] = ogd[a];
            cur += ogd[a];
        }
        if (cur == sum) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}
