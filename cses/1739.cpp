#include <bits/stdc++.h>
using namespace std;

struct BIT2 {
    vector<vector<int>> tree;
    int m;
    BIT2(int n) {
        tree.resize(n + 1, vector<int> (n + 1));
        m = n;
    }

    void upd(int x, int y, int val) {
        while (x <= m) {
            updy(x, y, val);
            x += (x & -x);
        }
    }

    void updy(int x, int y, int val) {
        while (y <= m) {
            tree[x][y] += val;
            y += (y & -y);
        }
    }
    int query(int x, int y) {
        int ans = 0;
        int y1;
        while (x > 0) {
            y1 = y;
            while (y1 > 0) {
                ans += tree[x][y1];
                y1 -= (y1 & -y1);
            }
            x -= (x & -x);
        }
        return ans;
    }
};

int main() {
    int n, q;
    cin >> n >> q;
    vector<vector<char>> forest(n + 1, vector<char>(n + 1));
    BIT2 tree(n);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            char c;
            cin >> c;
            forest[i][j] = (c == '.') ? 0 : 1;
            if (forest[i][j]) {
                tree.upd(i, j, 1);
            }
        }
    }
    for (int i = 0; i < q; i++) {
        int t;
        cin >> t;
        if (t == 1) {
            int y, x;
            cin >> x >> y;
            forest[x][y] = 1 - forest[x][y];
            tree.upd(x, y, forest[x][y]);
        } else {
            int y1, x1, y2, x2;
            cin >> x1 >> y1 >> x2 >> y2;
            int ans = tree.query(x2, y2) - tree.query(x1 - 1, y2) - tree.query(x2, y1 - 1)
                    + tree.query(x1 - 1, y1 - 1);
            cout << ans << endl;
        }
    }
}