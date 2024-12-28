#include <bits/stdc++.h>
using namespace std;

using ll = long long;


ofstream fout("test.out");
// #define cout fout

struct Node {
    char val;
    ll sz;
    Node *left, *right;
    Node(char c, ll _sz, Node *l, Node *r) {
        val = c, sz = _sz, left = l, right = r;
    }

    void print_substring(ll start, ll end) {
        start = max(start, 0ll);
        end = min(end, sz - 1);
        cout << start << " " << end << endl;
        if (start > end) {
            return;
        }
        if (val != '*') {
            cout << val;
        } else {
            left->print_substring(start, end);
            right->print_substring(start - left->sz, end - left->sz);
        }
    }


    void print(ll l, ll r) {
        if (val != '*') {
            cout << val; return;
        }
        // both; only left
        if (l < left->sz) {
            left->print(l, min(r, left->sz - 1));
            if (left->sz <= r) {
                right->print(0, r - left->sz);
            }
        }
        // only right
        else {
            right->print(l - left->sz, r - left->sz);
        }
    }


    void print2(ll l, ll r) {
        cout << l << " " << r << endl;
        if (l >= sz) return;
        if (val != '*') {
            cout << val; return;
        }
        left->print2(l, r);
        if (r - left->sz >= 0) right->print2(0, r - left->sz);
    }
};

void printTree(Node *root) {
    if (root == nullptr) return;
    printTree(root->left);
    cout << root->val;
    printTree(root->right);
}

const ll MXN = 2e5 + 3, inf = 1e18;

ll l, r, n;
map<char, Node*> mp;
pair<char, string> q[MXN];

int main() {
    // ifstream cin("test.in");
    cin >> l >> r >> n;
    for (int i = 0; i < n; i++) {
        cin >> q[i].first >> q[i].second;
    }
    reverse(q, q + n);
    for (int i = 0; i < n; i++) {
        string s = q[i].second;
        Node *root = nullptr;

        for (char j : s) {
            if (root == nullptr) {
                if (mp.count(j)) root = mp[j];
                else root = new Node(j, 1, nullptr, nullptr);
            } else {
                Node *b = nullptr;
                if (mp.count(j)) b = mp[j];
                else b = new Node(j, 1, nullptr, nullptr);
                root = new Node('*', min(inf, root->sz + b->sz), root, b);
            }
        }
        mp[q[i].first] = root;
    }
    // cout << "bdebbb" << endl;
    mp['a']->print(l - 1, r - 1);
}