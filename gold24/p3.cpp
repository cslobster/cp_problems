#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int N = 200000;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    for(int ii=0; ii<T; ii++) {
        int n; cin >> n;

        vector<pair<ll, ll>> tasks(n);
        multiset<ll> mySet;
        for (int i = 0; i < n; i++) {
            cin >> tasks[i].first >> tasks[i].second;
            tasks[i].first += tasks[i].second;
        }
        sort(tasks.begin(), tasks.end());

        ll numTasks = 0;
        ll newTime = 0;
        for (int i = 0; i < n; i++) {
            if (!mySet.empty()) {
                ll newSt = *mySet.begin();
                mySet.erase(mySet.begin());
                mySet.insert(newSt);
            } else
                newTime = 0;

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