#include <bits/stdc++.h>
using namespace std;

const int MX = 1e5 + 2;
int p[MX], a[MX], b[MX];
int n, m, q;

int* shuffle(int* a, int* b) {
    int ans[MX];
    for (int i = 0; i < n; i++) {
        ans[i] = a[b[i]];
    }
    for (int i = 0; i < n; i++) {
        a[i] = ans[i];
    }
}

int main() {
    ifstream cin("shuffle.in");
    ofstream cout("shuffle.out");
    cin >> n >> m >> q;
    iota(p, p + n, 0);
    iota(a, a + n, 0);
    iota(b, b + n, 0);
    for (int i = 0; i < m; i++) {
        int a; cin >> a;
        p[a - 1] = i;
    }
    rotate(p, p + 1, p + n);
    int k = n - m + 1;
    while (k) {
        if (k % 2 == 1) shuffle(a, p);
        shuffle(p, p);
        k /= 2;
    }
    for (int i = 0; i < q; i++) {
        int x; cin >> x;
        cout << a[(n + m - 1 - x) % n] + 1 << endl;
    }
}