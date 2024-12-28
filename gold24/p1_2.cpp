#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MXN = 1e5 + 3, MOD = 1e9 + 7;

int n;
map<int, vector<int>> label;

struct Ss {
    pair<int, int> a, b;
};

int time(pair<int, int> i, pair<int, int> j) {
    return j.second - i.first;
}

bool operator<(const Ss &a, const Ss &b) {
    int ta = time(a.a, a.b), tb = time(b.a, b.b);
    if (ta != tb) return ta < tb;
    return a.a.first < b.a.first;
}

int main() {
    ifstream cin("test.in");
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        label[a].push_back(i);
    }
    vector<int> ans(n + 1, 0);
    for (auto &[l, v] : label) {
        // if (l != 0) continue;
        set<pair<int, int>> segments;
        vector<int> curAns(n + 1, 0), ans2(n + 1, 0);
        multiset<Ss> whenMerge;
        for (int i = 0; i < v.size(); i++) {
            segments.insert({v[i], v[i]});
            if (i + 1 < v.size()) whenMerge.insert({{v[i], v[i]}, {v[i + 1], v[i + 1]}});
        }
        while (!whenMerge.empty()) {
            auto tp = *whenMerge.begin();
            whenMerge.erase(whenMerge.begin());
            if (!segments.count(tp.a) || !segments.count(tp.b)) continue;
            // merge these two segments at time t
            int t = time(tp.a, tp.b);
            curAns[t]++;
            cout << "merged: " << tp.a.first << " " << tp.a.second << " and " << tp.b.first << " " << tp.b.second << " so " << t << endl;
            auto seg = segments.insert({tp.a.first, tp.b.second}).first;

            // if not the first, add new tomerge
            auto prevSeg = segments.find(tp.a);
            auto nextSeg = segments.find(tp.b);
            if (prevSeg != segments.begin()) {
                prevSeg--;
                whenMerge.insert({*prevSeg, *seg});
            }
            nextSeg++;
            if (nextSeg != segments.end()) {
                whenMerge.insert({*seg, *nextSeg});
            }
            segments.erase(tp.a);
            segments.erase(tp.b);
        }
        ans2[0] = v.size();
        for (int i = 1; i <= n; i++) {
            ans2[i] = ans2[i - 1];
            ans2[i] -= curAns[i];
            ans[i] += ans2[i];
        }
    }
    for (int i = 1; i <= n; i++) cout << ans[i] << endl;
}