#include <bits/stdc++.h>
using namespace std;

const int MXN = 1e5 + 3;

int n;
int ans[MXN], ans2[MXN], nxt[MXN];
vector<int> labels[MXN];

int cnt(vector<int> &v, int x) {
    // number of groups it takes with x = x
    int cur = 0;
    int prev = *v.begin();
    while (true) {
        cur++;
        auto it = upper_bound(v.begin(), v.end(), prev + x);
        if (it == v.end()) break;
        prev = *it;
    }
    return cur;
}

int cnt2(vector<int> &v, int x) {
    // number of groups it takes with x = x
    int cur = 0;
    int prev = *v.begin();
    while (true) {
        cur++;
        if (prev + x + 1 >= n) break;
        int it = nxt[prev + x + 1];
        if (it == -1) break;
        prev = it;
    }
    return cur;
}

int search(vector<int> &v, int targ) {
   // FFFT
    int l = 1;
    int r = n;
    while (l != r) {
        int mid = (l + r)/2;
        if (cnt(v, mid) <= targ) {
            r = mid;
        }
        else {
            l = mid + 1;
        }
    }
    return l;
}

int search2(vector<int> &v, int targ) {
    // FFFT
    int l = 1;
    int r = n + 1;
    while (l != r) {
        int mid = (l + r)/2;
        if (cnt2(v, mid) < targ) {
            r = mid;
        }
        else {
            l = mid + 1;
        }
    }
    return l;
}

int search22(vector<int> &v, int targ) {
    // FFFT
    int l = 1;
    int r = n + 1;
    while (l != r) {
        int mid = (l + r)/2;
        if (cnt(v, mid) < targ) {
            r = mid;
        }
        else {
            l = mid + 1;
        }
    }
    return l;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 0; i < n; i++) {
        int val; cin >> val;
        labels[val].push_back(i);
    }
    int sq = sqrt(n);
    for (int l = 1; l <= n; l++) {
        auto &v = labels[l];
        if (v.empty()) continue;
        if (v.size() <= 10) {
            for (int targ = v.size(); targ >= 1; targ--) {
                // what are the ranges for this target answer?
                // int left = search(v, targ); // FFT, first answer >= targ
                int right = search22(v, targ); // TTF, first answer < targ
                // ans2[left] += targ;
                if (right <= n) ans2[right]--;
                ans2[1]++;
            }
            continue;
        }
        fill(nxt, nxt + n, -1);
        for (auto e : v) nxt[e] = e;
        for (int i = v.back(); i >= 0; i--) {
            if (nxt[i] == -1) nxt[i] = nxt[i + 1];
        }
        if (v.size() > sq) {
            for (int x = n; x >= 1; x--) {
                int cur = cnt2(v, x);
                ans[x] += cur;
            }
        } else {
            for (int targ = v.size(); targ >= 1; targ--) {
                // what are the ranges for this target answer?
                // int left = search(v, targ); // FFT, first answer >= targ
                int right = search2(v, targ); // TTF, first answer < targ
                // ans2[left] += targ;
                if (right <= n) ans2[right]--;
                ans2[1]++;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << ans[i] + ans2[i] << "\n";
        ans2[i + 1] += ans2[i];
    }
}