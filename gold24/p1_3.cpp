#include <bits/stdc++.h>
using namespace std;

vector<int> calc_groups(const vector<int>& positions) {
    int n = positions.back() - positions.front();
    vector<int> res(n + 1);
    fill(res.begin(), res.end(), 1);
    for(int k = 1; k <= n; k++) {
        int groups = 1;
        int i = 0;
        while(i < positions.size()) {
            int target = positions[i] + k + 1;
            i = lower_bound(positions.begin() + i, positions.end(), target) - positions.begin();
            if(i < positions.size()) groups++;
        }
        res[k - 1] = groups;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> ans(n+1);
    unordered_map<int, vector<int>> positions;
    for(int i = 0; i < n; i++) {
        int l;
        cin >> l;
        positions[l].push_back(i);
    }

    bool flag = true;
    for(const auto& [label, pos] : positions) {
        if(pos.size() > 10) {
            flag = false;
            break;
        }
    }

    vector<int> changes(n + 2, 0);
    if(flag) {
        map<vector<int>, vector<int>> pattern_groups;
        for(const auto& [label, pos] : positions) {
            if(pos.size() == 1) {
                changes[1]++;
                continue;
            }

            vector<int> pattern;
            for(int i = 0; i < pos.size(); i++) {
                pattern.push_back(i == 0 ? 0 : pos[i] - pos[0]);
            }

            if(!pattern_groups.count(pattern)) {
                pattern_groups[pattern] = calc_groups(pattern);
            }
            const vector<int>& groups = pattern_groups[pattern];

            int maxGap = pos.back() - pos.front();
            changes[maxGap + 1]++;

            for(int k = 1; k <= maxGap; k++) {
                changes[k] += groups[k - 1];
                changes[k + 1] -= groups[k - 1];
            }
        }
    } else {
        for(const auto& [label, pos] : positions) {
            if(pos.size() == 1) {
                changes[1]++;
                continue;
            }

            int maxGap = pos.back() - pos.front();
            changes[maxGap + 1]++;

            for(int k = 1; k <= maxGap; k++) {
                int groups = 1;
                int i = 0;
                while(i < pos.size()) {
                    int target = pos[i] + k + 1;
                    i = lower_bound(pos.begin() + i, pos.end(), target) - pos.begin();
                    if(i < pos.size()) groups++;
                }
                changes[k] += groups;
                changes[k + 1] -= groups;
            }
        }
    }

    int sum = 0;
    for(int k = 1; k <= n; k++) {
        sum += changes[k];
        cout << sum << '\n';
    }

    return 0;
}