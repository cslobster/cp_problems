#include <bits/stdc++.h>
using namespace std;

const int MXN = 5003;

int n, x;
int a[MXN], order[MXN];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> x;
    for (int i = 0; i < n; i++) cin >> a[i];
    iota(order, order + n, 0);
    sort(order, order + n, [](const int &aa, const int &bb){return a[aa] < a[bb];});
    for (int ind = 0; ind < n; ind++) {
        int i = order[ind];
        int targ = x - a[i];
        int l = ind + 1, r = n - 1;
        while (l < r) {
            int sum = a[order[l]] + a[order[r]];
            if (sum == targ) {
                cout << order[l] + 1 << " " << order[r] + 1 << " " << i + 1 << endl; return 0;
            }
            if (sum < targ) l++;
            else r--;
        }
    }
    cout << "IMPOSSIBLE\n";
}