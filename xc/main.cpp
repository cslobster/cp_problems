#include <bits/stdc++.h>
using namespace std;
#define int long long

struct SEG {
	vector<int> a, tree;
	auto opp = min, def = LLONG_MAX;
	void init(vector<int> &_a) {
		a = _a;
		tree.resize(a.size() * 4, def);
	}
	int build(int node, int l, int r) {
		if (l > r) return def;
		if (l == r) return tree[node] = a[l];
		int mid = (r + l) / 2;
		return tree[node] = opp(build(node * 2, l, mid), build(node * 2 + 1, mid + 1, r));
	}
	int query(int node, int l, int r, int x, int y) {
		if (r <= y && l >= x) return tree[node];
		if (l > y || r < x) return def;
		int mid = (r + l) / 2;
		return opp(query(node * 2, l, mid, x, y), query(node * 2 + 1, mid + 1, r, x, y));
	}
	int upd(int node, int l, int r, int i, int j) {
		if (i > r || i < l) return tree[node];
		if (l == r) return tree[node] = j;
		int mid = (r + l) / 2;
		return tree[node] = opp(upd(node * 2, l, mid, i, j), upd(node * 2 + 1, mid + 1, r, i, j));
	}
};

signed main() {
	int n, q;
	cin >> n >> q;
	vector<int> a(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	SEG tree;
	tree.init(a);
	tree.build(1, 1, n);
	for (int i = 0; i < q; i++) {
		int x, y, z; cin >> x >> y >> z;
		if (x == 1) {
			tree.upd(1, 1, n, y, z);
		} else {
			cout << tree.query(1, 1, n, y, z) << endl;
		}
	}
}