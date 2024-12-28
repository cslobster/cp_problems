#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int b; cin >> b; a[b] = 1;
    }
    for (int i = 1; i <= n; i++) {
        if (a[i] == 0) {
            cout << i << endl;
            return 0;
        }
    }
}