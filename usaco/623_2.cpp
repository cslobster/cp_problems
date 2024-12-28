#include <bits/stdc++.h>
using namespace std;

int A, B, n, m;
int par[2010 * 2010];

struct DSU2 {
//    int par[2005 * 2005];

    void set() {
        for (int i = 0; i < n * m; i++) {
            par[i] = i;
        }
    }

    int getPar(int x) {
        return x == par[x] ? x : par[x] = getPar(par[x]);
    }
//    int getPar(int x) {
//        if (par[x] == x) return x;
//        return getPar(par[x]);
//    }

    bool join(int x, int y) {
        int px = getPar(x);
        int py = getPar(y);
        if (px != py) {
            if (rand() % 2) swap(x, y);
            par[px] = py;
            return true;
        }
        return false;
    }
};

struct DSU {

    void set() {
        for (int i = 0; i < n * m; i++) {
            par[i] = i;
        }
    }

    int getPar(int x) {
        return x == par[x] ? x : par[x] = getPar(par[x]);
    }

    bool join(int x, int y) {
        int X = getPar(x);
        int Y = getPar(y);
        if (X == Y) return false;
        par[X] = par[Y] = par[x] = par[y] = rand() % 2 ? X : Y;
        return true;
    }
};


inline int flatten(int x, int y) {
    return x * m + y;
}

int main() {
    ifstream cin("fencedin.in");
    ofstream cout("fencedin.out");
    cin >> A >> B >> n >> m;
    vector<int> a(n + 1), b(m + 1);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < n; i++) {
        a[i] = a[i + 1] - a[i];
    }
    a[n] = A - a[n];
    sort(a.begin(), a.end());
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }
    sort(b.begin(), b.end());
    for (int i = 0; i < m; i++) {
        b[i] = b[i + 1] - b[i];
    }
    b[m] = B - b[m];
    sort(b.begin(), b.end());
    n++, m++;
    DSU2 dsu;
    dsu.set();
    long long cost = 0;
    for (int ai = 0, bi = 0; ai < n || bi < m;) {
         if (bi == m || (ai < n && a[ai] < b[bi])) {
            for (int i = 0; i + 1 < m; i++) {
                if (dsu.join(flatten(ai, i), flatten(ai, i + 1))) {
                    cost += a[ai];
                }
            }
            ai++;
        } else {
            for (int i = 0; i + 1 < n; i++) {
                if (dsu.join(flatten(i, bi), flatten(i + 1, bi))) {
                    cost += b[bi];
                }
            }
            bi++;
        }
//         cout << ai << " " << bi << endl;
    }
    cout << cost;

}