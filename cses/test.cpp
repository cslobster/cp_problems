#include <bits/stdc++.h>
using namespace std;
const int MX = INT_MAX;

class RMQ {
private:
    vector<int> a, b;
    int sz, n;
public:
    void setup(vector<int> &x) {
        a = x;
        n = x.size();
        sz = sqrt(n);
        b.resize(n / sz + 1, MX);
        int ans = MX;
        for (int i = 0; i < n; i++) {
            b[i / sz] = min(b[i / sz], x[i]);
            ans = min(ans, b[i / sz]);
        }
    }
    int query(int l, int r) {
        int st = l / sz;
        int ed = r / sz;
        // left leftover
        int ans = MX;
        if (st == ed) {
            for (int i = l; i <= r; i++) {
                ans = min(ans, a[i]);
            }
        } else {
            for (int i = l; i <= (st + 1) * sz - 1; i++) {
                ans = min(ans, a[i]);
            }
            for (int i = st + 1; i <= ed - 1; i++) {
                ans = min(ans, b[i]);
            }
            for (int i = ed * sz; i <= r; i++) {
                ans = min(ans, a[i]);
            }
        }
        return ans;
    }
};

int main() {
//    int n;
//    cin >> n;
//    vector<int> a(n);
//    for (int i = 0; i < n; i++) {
//        cin >> a[i];
//    }
//    RMQ rmq;
//    rmq.setup(a);
//    cout << rmq.query(2, 12);
    pair<int, int> a = {3, 5};
    pair<int, int> b = {4, 2};
    pair<int, int> c = min(a, b);
    cout << c.first << " " << c.second << endl;
}


/*
 * 16      5 8 6 126     2 7 2 6     7 1 7 9     16 2 3 2
 */