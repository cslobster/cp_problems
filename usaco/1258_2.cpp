#include <bits/stdc++.h>
using namespace std;

const int MXN = 2003;

int n, q;
int h[MXN];
set<int> ans[MXN];
int cnt = 0;

void fastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

// bool comp(int a, int b, int c, int d) {
//     return (long long)a * (long long)d <= (long long)b * (long long)c;
// }


bool comp(int ind, int i1, int i2) {
    // does index i2 to ind have a greater slope than index i1 to ind
    int d1 = abs(ind - i1), d2 = abs(ind - i2);
    long long h1 = h[i1] - h[ind], h2 = h[i2] - h[ind];
    return h2 * d1 >= h1 * d2;
}



void calc() {
    // cnt = 0;
    for (int i = 0; i < n; i++) {
        // ans[i].clear();
        for (int j = i + 1; j < n; j++) {
            if (ans[i].empty()) ans[i].insert(j);
            else {
                int x2 = *ans[i].rbegin();
                // x1 = i, x3 = j
                // int a = h[x2] - h[i], b = x2 - i;
                // int c = h[j] - h[i], d = j - i;
                if (comp(i, x2, j)) {
                    ans[i].insert(j);
                }
            }
        }
        cnt += (int)ans[i].size();
    }
}

int main() {
    fastIO();
    // ifstream cin("test.in");
    // ofstream cout("test.out");
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }
    calc();
    cin >> q;
    while (q--) {
        int x, y;
        cin >> x >> y;
        x--;
        h[x] += y;
        // fix 1 to x - 1
        for (int i = 0; i < x; i++) {
            auto lb = ans[i].lower_bound(x);
            if (*lb != x) {
                // check if you can add x to list
                lb--;
                int x2 = *lb;
                if (comp(i, x2, x)) {
                    ans[i].insert(x);
                    lb++;
                    cnt++;
                }  else {
                    continue;
                }
            }
            lb++;
            while (lb != ans[i].end() && !comp(i, x, *lb)) {
                lb = ans[i].erase(lb);
                cnt--;
            }
        }

    /*
        for (int j = 0; j <= x - 1; j++) {
            auto it = ans[j].lower_bound(x);
            bool add = false;
            if ((*it) == x) {
                add = true;
                it++;
            } else {
                --it;
                if (comp(j, (*it), x)) {
                    ans[j].insert(x);
                    cnt++;
                    add = true;
                    it++;
                    it++;
                }
            }
            if (add) {
                while (it != ans[j].end() && !comp(j, x, (*it))) {
                    it = ans[j].erase(it);
                    cnt--;
                }
            }
        }

*/


        // rebuild x
        cnt -= (int)ans[x].size();
        ans[x].clear();
        for (int j = x + 1; j < n; j++) {
            if (ans[x].empty()) ans[x].insert(j);
            else {
                int x2 = *ans[x].rbegin();
                // x1 = i, x3 = j
                // int a = h[x2] - h[x], b = x2 - x;
                // int c = h[j] - h[x], d = j - x;
                if (comp(x, x2, j)) {
                    ans[x].insert(j);
                }
            }
        }
        cnt += (int)ans[x].size();

        cout << cnt << "\n";
    }
}