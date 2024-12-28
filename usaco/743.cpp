#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream cin("art2.in");
    ofstream cout("art2.out");
    int n;
    cin >> n;
    vector<int> a(n);
    vector<vector<int>> events;
    vector<int> st(n + 1, -1), ed(n + 1, -1);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        ed[a[i]] = i;
        if (st[a[i]] == -1) st[a[i]] = i;
    }
    for (int i = 1; i <= n; i++) {
        if (st[i] != -1) {
            events.push_back({st[i], i, 0});
            events.push_back({ed[i], i, 1});
        }
    }
    int c = 0, ans = 0;
    sort(events.begin(), events.end());
    stack<int> s;
    for (auto e : events) {
        if (e[2] == 0) {
            s.push(e[1]);
            c++;
            ans = max(ans, c);
        } else {
            if (s.top() != e[1]) {
                cout << -1 << endl;
                return 0;
            }
            s.pop();
            c--;
        }
    }



    cout << ans << endl;
}