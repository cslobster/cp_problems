#include <bits/stdc++.h>
using namespace std;

int main() {
    int k;
    cin >> k;
    vector<int> dist(k, 0x3f3f3f3f);
    dist[1] = 0;
    deque<int> dq;
    dq.push_front(1);
    while (!dq.empty()) {
        auto tp = dq.front();
        if (tp == 0) {
            cout << dist[0] + 1 << endl;
            return 0;
        }
        dq.pop_front();
        if (dist[tp] < dist[(tp * 10) % k]) {
            dist[(tp * 10) % k] = dist[tp];
            dq.push_front((tp * 10) % k);
        }
        if (dist[tp] + 1 < dist[(tp + 1) % k]) {
            dist[(tp + 1) % k] = dist[tp] + 1;
            dq.push_back((tp + 1) % k);
        }
    }
}
