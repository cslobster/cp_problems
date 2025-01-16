#include <bits/stdc++.h>
using namespace std;

const int MXN = 150003, MXM = MXN * 4, MXZ = 17;

int n, m;
int a[MXN], tree[MXM];
int b[MXZ][MXN];
vector<pair<int, int>> queries[MXZ];
vector<array<int, 3>> qq;

void build(int p, int l, int r) {
    if (l == r) {tree[p] = a[l]; return;}

    int mid = (l + r)/2;
    build(2*p, l, mid);
    build(2*p + 1, mid + 1, r);

    tree[p] = gcd(tree[2*p], tree[2*p + 1]);
}

int query(int ind, int l, int r, int i, int j) {
    if (j < l || i > r) {
        return 0;
    }
    if (l >= i && r <= j) return tree[ind];
    return gcd(query(ind * 2, l, (l + r) / 2, i, j),
               query(ind * 2 + 1, (l + r) / 2 + 1, r, i, j));
}

int lcm(int a, int b) {
    return a * b / gcd(a, b);
}

void process(int l, int r, int z) {
    if (r == 0) return;
    qq.push_back({l, r, z});
    for (int ind = l; ind <= r; ind++) {
        a[ind] = lcm(a[ind], z);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // ifstream cin("test.in");
    // ofstream cout("test.out");
    cin >> n >> m;
    for (int i = 1; i <= n; i++) a[i] = 1;
    for (int i = 0; i < m; i++) {
        int l, r, z;
        cin >> l >> r >> z;
        b[z][l]++, b[z][r + 1]--;
        qq.push_back({l, r, z});
    }
    for (int i = 1; i < MXZ; i++) {
        for (int j = 1; j <= n; j++) {
            b[i][j] += b[i][j - 1];
            if (b[i][j] >= 1) {
                a[j] = lcm(a[j], i);
            }
        }
    }
    build(1, 1, n);
    for (auto &[l, r, z] : qq) {
        // cout << l << " " << r << " " << z << endl;
        int g = query(1, 1, n, l, r);
        if (g != z) {
            cout << "Impossible" << "\n";
            return 0;
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << a[i] << " ";
    }
}