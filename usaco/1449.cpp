#include <bits/stdc++.h>
using namespace std;

const int MXN = 1e5 + 3;

int n;
int a[MXN], ans[MXN];
map<int, vector<int>> labels;

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

int cnt2(int x) {
    // number of groups it takes with x = x
    int cur = 0;
    for (auto &[l, v] : labels) {
        int prev = v[0];
        while (true) {
            cur++;
            auto it = upper_bound(v.begin(), v.end(), prev + x);
            if (it == v.end()) break;
            prev = *it;
        }
    }
    return cur;
}

int search3(int targ) {
    // FFFT
    int l = 1;
    int r = n + 1;
    while (l != r) {
        int mid = (l + r)/2;
        if (cnt2(mid) <= targ) {
            r = mid;
        }
        else {
            l = mid + 1;
        }
    }
    return l;
}

int search4(int targ) {
    // FFFT
    int l = 1;
    int r = n + 1;
    while (l != r) {
        int mid = (l + r)/2;
        if (cnt2(mid) < targ) {
            r = mid;
        }
        else {
            l = mid + 1;
        }
    }
    return l;
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
    cin >> n;
    for (int i = 0; i < n; i++) {
        int val; cin >> val;
        labels[val].push_back(i);
    }
    if (labels.size() <= 1e3) {
            // max ans = v.size(), min ans = 1
        for (auto &[l, v] : labels) {
            for (int x = n; x >= 1; x--) {
                int cur = 0;
                int prev = *v.begin();
                while (true) {
                    cur++;
                    auto it = upper_bound(v.begin(), v.end(), prev + x);
                    if (it == v.end()) break;
                    prev = *it;
                }
                ans[x] += cur;
            }
        }
        for (int i = 1; i <= n; i++) {
            cout << ans[i] << endl;
        }
        return 0;
    }
    for (auto &[l, v] : labels) {
        // max ans = v.size(), min ans = 1
        for (int targ = v.size(); targ >= 1; targ--) {
            // what are the ranges for this target answer?
            int left = search(v, targ); // FFT, first answer >= targ
            int right = search2(v, targ); // TTF, first answer < targ
            ans[left] += targ;
            ans[right] -= targ;
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << endl;
        ans[i + 1] += ans[i];
    }
}