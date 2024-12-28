#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int N = 2e5 + 3;
multiset<ll> mySet;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    for(int ii = 0; ii < t; ii++) {
        int n; cin >> n;
        vector<pair<ll, ll>> tasks(n);
        for (int i = 0; i < n; i++) {
            cin >> tasks[i].first >> tasks[i].second;
            tasks[i].first += tasks[i].second;
        }
        sort(tasks.begin(), tasks.end());
        ll numTasks = 0, newTime = 0;
        vector<ll> s(n, 0);
        for (int i = 0; i < n; i++) {
            if (!mySet.empty()) {
                ll newSt = *mySet.begin();
                mySet.erase(mySet.begin()), mySet.insert(newSt);
            } else
                newTime = s[i];

            numTasks++;
            newTime += tasks[i].second;
            mySet.insert(tasks[i].second);

            if (newTime > tasks[i].first) {
                newTime -= *prev(mySet.end());
                mySet.erase(prev(mySet.end()));
                numTasks--;
            }
        }
        cout << numTasks << '\n';
    }
    return 0;
}