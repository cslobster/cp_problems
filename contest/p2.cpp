#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MXN = 1e5 + 3;

int n, m, q;
ll val[MXN][2];

ll value(int xx) {
    if (xx == 1 || xx == 3) return 1e18;
    return -1e18;
}

ll validate(ll a, int xx) {
    if (xx == 0 || xx == 2) {
        if (a < 0) return -1e18;
        return a;
    }
    if (a > 0) return 1e18;
    return a;
}

ll opt(ll a, ll b, int xx) {
    if (xx == 0) {
        // positive closest to 0
        if (a >= 0 && b < 0) return a;
        if (a < 0 && b < 0) return -1e18;
        if (b >= 0 && a < 0) return b;
        assert(a >= 0 && b >= 0);
        return min(a, b);
    }
    if (xx == 1) {
        // negative closest to 0
        if (a > 0 && b > 0) return 1e18;
        if (a > 0 && b <= 0) return b;
        if (b > 0 && a <= 0) return a;
        assert(a <= 0 && b <= 0);
        return max(a, b);
    }
    if (xx == 2) {
        // largest positive
        if (a < 0 && b < 0) return -1e18;
        return max(a, b);
    }
    assert(xx == 3);
    // largest negative
    if (a > 0 && b > 0) return 1e18;
    return min(a, b);
}

struct Seg {
    vector<ll> tree;
    int ii, xx;
    void build (int ind, int l, int r) {
        if (l > r) return;
        if (l == r) {
            tree[ind] = validate(val[l][ii], xx);
            // cout << l << " " << val[l][ii] << " FFF " << xx << " " << tree[ind] << endl;
            return;
        }
        build(ind * 2, l, (l + r) / 2);
        build(ind * 2 + 1, 1 + (l + r) / 2, r);
        tree[ind] = opt(tree[ind * 2], tree[ind * 2 + 1], xx);
    }

    Seg(int _sz, int _i, int _xx) {
        // _sz++;
        ii = _i;
        xx = _xx;
        tree.resize(_sz * 4, value(_xx));
        build(1, 1, _sz);
    }
    ll query(int ind, int l, int r, int i, int j) {
        if (i == 3 && j == 3) {
            // cout << "VAL: " << ind << " " << l << " " << r << endl;
        }
        if (j < l || i > r) {
            return value(xx);
        }
        if (l >= i && r <= j) return validate(tree[ind], xx);
        ll ans = validate(query(ind * 2, l, (l + r) / 2, i, j), xx);
        ans = opt(ans, query(ind * 2 + 1, (l + r) / 2 + 1, r, i, j), xx);
        return ans;
    }
};


struct Seg2 {
    vector<ll> tree;
    int ii, xx;
    void build (int ind, int l, int r) {
    }
    Seg2(int _sz, int _i, int _xx) {
        _sz++;
        ii = _i;
        xx = _xx;
        tree.resize(_sz * 4);
        build(1, 1, _sz);
    }
    ll query(int ind, int l, int r, int i, int j) {
        ll ans = value(xx);
        for (int idx = i; idx <= j; idx++) {
            ans = opt(ans, val[idx][ii], xx);
        }
        return ans;
    }
};


int main() {
    cin >> n >> m >> q;
    for (int i = 1; i <= n; i++) cin >> val[i][0];
    for (int i = 1; i <= m; i++) cin >> val[i][1];
    Seg asp(n, 0, 0), asn(n, 0, 1), abp(n, 0, 2), abn(n, 0, 3);
    Seg bsp(m, 1, 0), bsn(m, 1, 1), bbp(m, 1, 2), bbn(m, 1, 3);
    // for (int i = 1; i <= n; i++) {
        // cout << i << " " << asp.query(1, 1, n, i, i) << endl;
    // }
    for (int i = 0; i < q; i++) {
        int al, ar, bl, br;
        cin >> al >> ar >> bl >> br;
        ll ans = -1e18;
        // what are a's options?
        ll spA = asp.query(1, 1, n, al, ar);
        ll snA = asn.query(1, 1, n, al, ar);
        ll bpA = abp.query(1, 1, n, al, ar);
        ll bnA = abn.query(1, 1, n, al, ar);

        // what are b's options?
        ll spB = bsp.query(1, 1, m, bl, br);
        ll snB = bsn.query(1, 1, m, bl, br);
        ll bpB = bbp.query(1, 1, m, bl, br);
        ll bnB = bbn.query(1, 1, m, bl, br);
        
        if (abs(spA) != (long long)1e18) {
            // if a has a small positive, b will try big negative
            if (abs(bnB) != (long long)1e18) {
                ans = max(ans, spA * bnB);
            } else {
                // or else will take small postive
                ans = max(ans, spA * spB);
            }
        }
        if (abs(snA) != (long long)1e18) {
            // if a has a small negative, be will try big positive
            if (abs(bpB) != (long long)1e18) {
                ans = max(ans, snA * bpB);
            } else {
                // or else will take small negative
                ans = max(ans, snA * snB);
            }
        }
        if (abs(bpA) != (long long)1e18) {
            // if a has big positive, b will choose big negative
            if (abs(bnB) != (long long)1e18) {
                ans = max(ans, bpA * bnB);
            } else {
                // or else will take small positive
                ans = max(ans, bpA * spB);
            }
        }
        if (abs(bnA) != (long long)1e18) {
            // if a has big negative, b will choose big positive
            if (abs(bpB) != (long long)1e18) {
                ans = max(ans, bnA * bpB);
            } else {
                // or else will take small negative
                ans = max(ans, bnA * snB);
            }
        }
        cout << ans << endl;
    }
}