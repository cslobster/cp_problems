#include <bits/stdc++.h>
using namespace std;

const int MXN = 1e5 + 3, MXM = 4e5 + 3, MXSQ = 350;

int n, k, q, sq;
int t[MXN], a[MXN], p[MXN], answer[MXN];
pair<int, int> queries[MXN];
vector<int> buckets[MXSQ];
map<int, int> v, l, r, mp;
int cnt[MXM];

void process(int ind, int &ans) {
    ans += cnt[l[ind]];
    cnt[v[ind]]++;
}

void undo(int ind) {
    cnt[v[ind]]--;
}

int main() {
    cin >> n >> k;
    sq = sqrt(n) + 1;
    for (int i = 0; i < n; i++) {
        cin >> t[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (t[i] == 2) a[i] = -a[i];
        p[i] = a[i];
        if (i) p[i] += p[i - 1];
    }
    cin >> q;
    for (int i = 0; i < q; i++) {
        cin >> queries[i].first >> queries[i].second;
        buckets[queries[i].first / sq].push_back(i);
    }
    vector<pair<int, pair<int, int>>> vv;
    for (int i = 0; i < n; i++) {
        vv.push_back({p[i], {i, 0}});
        vv.push_back({p[i] + k, {i, 1}});
        vv.push_back({p[i] - k, {i, 2}});
    }
    sort(vv.begin(), vv.end());
    int cnter = 0;
    for (int i = 0; i < vv.size(); i++) {
        if (i && vv[i].first == vv[i - 1].first) {
            cnter--;
        }
        if (vv[i].second.second == 0) {
            v[vv[i].second.first] = cnter;
        } else if (vv[i].second.second == 1) {
            l[vv[i].second.first] = cnter;
        } else {
            r[vv[i].second.first] = cnter;
        }
        mp[vv[i].first] = cnter;
        cnter++;
    }
    for (int xxx = 0; xxx <= sq; xxx++) {
        auto &b = buckets[xxx];
        if (b.empty()) continue;
        memset(cnt, 0, sizeof(cnt));
        sort(b.begin(), b.end(), [](int a, int b) {
            if (queries[a].second != queries[b].second) return queries[a].second < queries[b].second;
            return queries[a].first < queries[b].first;
        });
        int ans = 0;
        int mxr = sq * (xxx + 1) - 1;
        for (auto i : b) {
            auto &[left, right] = queries[i];
            for (int ind = mxr + 1; ind <= right; ind++) {
                process(ind, ans);
            }
            mxr = right;
            int ans2 = ans;
            for (int ind = left; ind <= min(right, sq * (xxx + 1) - 1); ind++) {
                process(ind, ans2);
            }
            answer[i] = ans2;
            for (int ind = left; ind <= min(right, sq * (xxx + 1) - 1); ind++) {
                undo(ind);
            }
        }
    }
    for (int i = 0; i < q; i++) {
        cout << answer[i] << endl;
    }
}