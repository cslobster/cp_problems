#include <bits/stdc++.h>
using namespace std;

template <size_t Nb> struct Bitset : bitset<Nb> {
    template <typename... Args> Bitset(Args... args) : bitset<Nb>(args...) {}

    static constexpr int N = Nb;
    static constexpr int array_size = (Nb + 63) / 64;

    union raw_cast {
        array<uint64_t, array_size> a;
        Bitset b;
    };

    int _Find_prev(size_t i) const {
        if (i == 0) return -1;
        if ((*this)[--i] == true) return i;
        size_t M = i / 64;
        const auto &a = ((raw_cast *)(this))->a;
        uint64_t buf = a[M] & ((1ull << (i & 63)) - 1);
        if (buf != 0) return M * 64 + 63 - __builtin_clzll(buf);
        while (M--) {
            if (a[M] != 0) return M * 64 + 63 - __builtin_clzll(a[M]);
        }
        return -1;
    }

    inline int _Find_last() const { return _Find_prev(N); }
};

const int MXN = 2003;

int n, q;
int h[MXN];
Bitset<MXN> ans[MXN];
int cnt = 0;

void fastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

// bool comp(int a, int b, int c, int d) {
//     return (long long)a * (long long)d <= (long long)b * (long long)c;
// }


bool comp(int ind, int i1, int i2) {
    // does index i2 to ind have a greater slope than index i1 to ind
    int d1 = abs(ind - i1), d2 = abs(ind - i2);
    long long h1 = h[i1] - h[ind], h2 = h[i2] - h[ind];
    return h2 * d1 >= h1 * d2;
}



void calc() {
    // cnt = 0;
    for (int i = 0; i < n; i++) {
        // ans[i].clear();
        for (int j = i + 1; j < n; j++) {
            if (ans[i].count() == 0) ans[i].set(j);
            else {
                int x2 = ans[i]._Find_last();
                // x1 = i, x3 = j
                // int a = h[x2] - h[i], b = x2 - i;
                // int c = h[j] - h[i], d = j - i;
                if (comp(i, x2, j)) {
                    ans[i].set(j);
                }
            }
        }
        cnt += (int)ans[i].count();
    }
}

int main() {
    fastIO();
    // ifstream cin("test.in");
    // ofstream cout("test.out");
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }
    calc();
    cin >> q;
    while (q--) {
        int x, y;
        cin >> x >> y;
        x--;
        h[x] += y;
        // fix 1 to x - 1
        for (int i = 0; i < x; i++) {
            int it = ans[i]._Find_next(x);
            int it2 = ans[i]._Find_prev(it);
            if (!comp(i, it2, x)) {
                continue;
            }
            if (!ans[i][x]) {
                ans[i].set(x);
                cnt++;
            }
            while (it < MXN && !comp(i, x, it)) {
                cnt--;
                ans[i].set(it, 0);
                it = ans[i]._Find_next(it);
            }
        }

        // rebuild x
        cnt -= (int)ans[x].count();
        ans[x].reset();
        for (int j = x + 1; j < n; j++) {
            if (ans[x].count() == 0) ans[x].set(j);
            else {
                int x2 = ans[x]._Find_last();
                // x1 = i, x3 = j
                // int a = h[x2] - h[x], b = x2 - x;
                // int c = h[j] - h[x], d = j - x;
                if (comp(x, x2, j)) {
                    ans[x].set(j);
                }
            }
        }
        cnt += (int)ans[x].count();

        cout << cnt << "\n";
    }
}