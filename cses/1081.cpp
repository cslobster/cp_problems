#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> x(n);
    int mx = 0;
    for (int i = 0; i < n; i++) {
        cin >> x[i];
        mx = max(mx, x[i]);
    }
    vector<int> occ(mx + 1);
    for (int i = 0; i < n; i++) {
        occ[x[i]]++;
    }
    for (int i = mx; i >= 1; i--) {
        int cnt = 0;
        for (int k = i; k <= mx; k += i) {
            cnt += occ[k];
        }
        if (cnt >= 2) {
            cout << i << endl;
            break;
        }
    }
}
