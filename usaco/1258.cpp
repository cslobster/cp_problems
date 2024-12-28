#include <bits/stdc++.h>
using namespace std;

const int MXN = 2003;

int n, q;
int h[MXN];
vector<int> ans[MXN];
int cnt = 0;

bool comp(int a, int b, int c, int d) {
    return (long long)a * (long long)d <= (long long)b * (long long)c;
}

void calc() {
    cnt = 0;
    for (int i = 0; i < n; i++) {
        ans[i].clear();
        for (int j = i + 1; j < n; j++) {
            if (ans[i].empty()) ans[i].push_back(j);
            else {
                int x2 = ans[i].back();
                // x1 = i, x3 = j
                int a = h[x2] - h[i], b = x2 - i;
                int c = h[j] - h[i], d = j - i;
                if (comp(a, b, c, d)) {
                    ans[i].push_back(j);
                }
            }
        }
        cnt += ans[i].size();
    }
}

int main() {
    ifstream cin("test.in");
    ofstream cout("test.out");
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }
    calc();
    cin >> q;
    while (q--) {
        int x, y;
        cin >> x >> y;
        h[x - 1] += y;
        // rebuild x
        cnt -= ans[x].size();
        ans[x].clear();
        for (int j = x + 1; j < n; j++) {
            if (ans[x].empty()) ans[x].push_back(j);
            else {
                int x2 = ans[x].back();
                // x1 = i, x3 = j
                int a = h[x2] - h[x], b = x2 - x;
                int c = h[j] - h[x], d = j - x;
                if (comp(a, b, c, d)) {
                    ans[x].push_back(j);
                }
            }
        }
        cnt += ans[x].size();

        // fix 1 to x - 1
        for (int i = 0; i < x - 1; i++) {
            auto lb = lower_bound(ans[i].begin(), ans[i].end(), x);
            if (*lb == x) {
                for (int j = x + 1; j < n; j++) {

                }
            } else {
                // check if you cam add x to list

            }
        }
    }
}