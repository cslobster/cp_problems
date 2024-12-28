#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        int cur = -1, amt = 0;
        vector<int> l;
        for (int i = 1; i <= n; i++) {
            if (i != n) l.push_back(i);
            l.push_back(i);
        }
        reverse(l.begin(), l.end());
        while (k) {
            if (cur + 1 >= 2 * n) {
                break;
            }
            cur++;
            if (k <= l[cur]) {
                break;
            }
            k -= l[cur];
        }
        cout << cur + 1 << endl;
    }
}