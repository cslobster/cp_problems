#include <bits/stdc++.h>
using namespace std;

int main() {
    // ifstream cin("test.in");
    // ofstream cout("test.out");
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> colors(m), c2(m);
        vector<set<int>> c3(m);
        vector<int> lastOcc(n + 1, -1);
        bool wrong = false;
        // CASE 1 & INPUT
        for (int i = 0; i < m; i++) {
            int c; cin >> c;
            vector<int> vis(n + 1);
            for (int j = 0; j < c; j++) {
                int a; cin >> a;
                if (wrong) continue;
                colors[i].push_back(a);
                c3[i].insert(a);
                if (!vis[a]) c2[i].push_back(a);
                if (!vis[a] && lastOcc[a] != -1 && lastOcc[a] != i - 1) {
                    wrong = true;
                    continue;
                }
                vis[a] = true;

                lastOcc[a] = i;
            }
        }
        if (wrong) {
            cout << "NO" << endl;
            continue;
        }
        // CASE 2 & 3
        vector<int> par(n + 1, -1);
        for (int x = 0; x < m; x++) {
            stack<int> st;
            st.push(0);
            vector<bool> vis(n + 1);
            for (auto c : colors[x]) {
                if (!vis[c]) {
                    if (!st.empty()) {
                        if (par[c] != -1 && par[c] != st.top()) {
                            wrong = true; break;
                        }
                        par[c] = st.top();
                    }
                    st.push(c);
                } else {
                    if (st.top() != c) {
                        wrong = true; break;
                    }
                    st.pop();
                }
                vis[c] = true;
            }
        }
        if (wrong) {
            cout << "NO" << endl;
            continue;
        }
        vector<int> order; set<int> s;
        for (auto c : c2[0]) {
            s.insert(c);
            order.push_back(c);
        }
        for (int x = 0; x < m - 1; x++) {
            vector<int> un, un2;
            for (auto c : order) {
                if (c3[x + 1].count(c)) {
                    un.push_back(c);
                }
            }
            for (auto c : c2[x + 1]) {
                if (s.count(c)) {
                    un2.push_back(c);
                }
            }
            if (un != un2) {
                wrong = true;
                break;
            }
            // merge order and c2[x + 1]
            vector<int> nw(0);
            int r = 0, l = 0;
            while (r < order.size() || l < c2[x + 1].size()) {
                if (r >= order.size()) {
                    nw.push_back(c2[x + 1][l]);
                    l++; continue;
                }
                if (l >= c2[x + 1].size()) {
                    nw.push_back(order[r]);
                    r++; continue;
                }
                if (order[r] == c2[x + 1][l]) {
                    nw.push_back(order[r]);
                    r++, l++; continue;
                }
                if (!c3[x + 1].count(order[r])) {
                    nw.push_back(order[r]);
                    r++;
                } else if (!s.count(c2[x + 1][l])) {
                    nw.push_back(c2[x + 1][l]);
                    l++;
                } else {
                    assert(false);
                }
            }
            order.clear();
            s.clear();
            for (auto c : nw) {
                order.push_back(c);
                s.insert(c);
            }
        }

        if (wrong) {
            cout << "NO" << endl;
            continue;
        }
        cout << "YES" << endl;
    }
}