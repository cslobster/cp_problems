#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> ranges;

struct BIT {
    vector<int> tree;
    void init(int _n) { tree.resize(_n); }

    void upd(int i, int x) {
        while (i < tree.size()) {
            tree[i] = (tree[i] + x);
            i += (i & (-i));
        }
    }

    long long query(int i) {
        long long ans = 0;
        while (i > 0) {
            ans += tree[i];
            i -= (i & (-i));
        }
        return ans;
    }
};

int main() {
    int n;
    cin >> n;
    ranges.resize(n);
    BIT bit, bit2;
    bit.init(n + 1);
    bit2.init(n + 1);

    map<int, int> x, y;
    vector<int> id(n);
    iota(id.begin(), id.end(), 0);

    for (int i = 0; i < n; i++) {
        cin >> ranges[i].first >> ranges[i].second;
    }
    sort(id.begin(), id.end(), [](int a, int b) {
        if (ranges[a].first != ranges[b].first) return ranges[a].first < ranges[b].first;
        return ranges[a].second > ranges[b].second;
    });

    sort(ranges.begin(), ranges.end(), [](pair<int, int> a, pair<int, int> b){return a.second < b.second;});

    int yi = 1;
    for (int i = 0; i < n; i++) {
        if (!y.count(ranges[i].second)) {
            y[ranges[i].second] = yi;
            yi++;
        }
    }

    vector<int> ii(n);
    for (int i = 0; i < n; i++) {ii[id[i]] = i;}
    sort(ranges.begin(), ranges.end(), [](pair<int, int> a, pair<int, int> b){
        if (a.first != b.first) return a.first < b.first;
        return a.second > b.second;
    });
    vector<int> ans1(n);
    for (int i = n - 1; i >= 0; i--) {
        ans1[id[i]] = bit.query(y[ranges[i].second]);
        bit.upd(y[ranges[i].second], 1);
    }
    // index of id = new, val = old
    vector<int> ans2(n);

    for (int i = 0; i < n; i++) {
        ans2[id[i]] = bit2.query(n + 1 - y[ranges[i].second]);
        bit2.upd(n + 1 - y[ranges[i].second], 1);
    }

    for (int i = 0; i < n; i++) {
        cout << ans1[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < n; i++) {
        cout << ans2[i] << " ";
    }
    cout << endl;
}