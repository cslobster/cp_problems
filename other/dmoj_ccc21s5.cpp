#include <bits/stdc++.h>
using namespace std;

const int MXN = 150003, MXM = MXN * 4, MXZ = 17;

int n, m;
int a[MXN], tree[MXM];
int b[MXZ][MXN];
vector<pair<int, int>> queries[MXZ];
vector<array<int, 3>> qq;

void build1(int p, int l, int r) {
    if (l == r) {tree[p] = a[l]; return;}

    int mid = (l + r)/2;
    build1(2*p, l, mid);
    build1(2*p + 1, mid + 1, r);

    tree[p] = gcd(tree[2*p], tree[2*p + 1]);
}

int query1(int p, int l, int r, int x, int y) {
    if (l == r) { return tree[p]; }

    int mid = (l + r)/2;
    int ans = 720720;
    if (x <= mid) {
        ans = gcd(ans, query1(2 * p, l, mid, x, y));
    }
    if (y >= mid + 1) {
        ans = gcd(ans, query1(2 * p + 1, mid + 1, r, x, y));
    }

    return ans;
}

void build (int i = 1, int treeleft = 1, int treeright = 150001){

    //When we encounter a leaf node
    if (treeleft == treeright){

        tree[i] = a[treeleft];

    }

    else{

        //Calculate midpoint, use int division to discard remainder
        int mid = treeleft + (treeright - treeleft) / 2;
        build (i * 2, treeleft, mid);
        build (i * 2 + 1, mid + 1, treeright);
        tree[i] = std::gcd(tree[i * 2], tree[i * 2 + 1]);

    }

}

//Query function for segment tree
int query (int i, int treeleft = 1, int treeright = 150001, int left, int right){

    //Out of range
    if (left > right){
        return 0;
    }

    //Segment of the tree is a part of the range
    if (left == treeleft && right == treeright){
        return tree[i];
    }

    //Calculate mid
    int mid = treeleft + (treeright - treeleft) / 2;

    //If segment is partially in range, recurse deeper down the segment tree until corresponding nodes are found
    //The min and max functions are important here to ensure that the proper range is being queried with each recurse
    return std::gcd(query (left, std::min(mid, right), i * 2, treeleft, mid), query (std::max(mid + 1, left), right, i * 2 + 1, mid + 1, treeright));

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
    // ifstream cin("test.in");
    // ofstream cout("test.out");
    cin >> n >> m;
    for (int i = 1; i <= n; i++) a[i] = 1;
    for (int i = 0; i < m; i++) {
        int l, r, z;
        cin >> l >> r >> z;
        queries[z].push_back({l, r});
        qq.push_back({l, r, z});
    }
    for (int i = 1; i < MXZ; i++) {
        if (queries[i].size() == 0) continue;
        for (auto &[l, r] : queries[i]) {
            b[i][l]++, b[i][r + 1]--;
        }
        for (int j = 1; j <= n; j++) {
            b[i][j] += b[i][j - 1];
            if (b[i][j] >= 1) {
                a[j] = lcm(a[j], i);
            }
        }
        /*
        // int l = 0, r = 0;
        // sort(queries[i].begin(), queries[i].end());
        // for (auto &[nl, nr] : queries[i]) {
        //     if (nl > r) {
        //         process(l, r, i);
        //         l =  nl, r = nr;
        //         continue;
        //     }
        //     if (l <= nl && r >= nr) {
        //         continue;
        //     }
        //     if (l <= nl && r <= nr) {
        //         r = nr;
        //         continue;
        //     }
        //     assert(false);
        // }
        //
        // process(l, r, i);
        */
    }
    build(1, 1, n);
    for (auto &[l, r, z] : qq) {
        int g = query(1, 1, n, l, r);
        // for (int j = l + 1; j <= r; j++) {
            // g = gcd(g, a[j]);
        // }
        if (g != z) {
            cout << "Impossible" << endl;
            return 0;
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << a[i] << " ";
    }
}