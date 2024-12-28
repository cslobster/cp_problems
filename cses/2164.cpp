#include <bits/stdc++.h>
using namespace std;

int f(int n, int k) {
    if (n == 1) return 1;
    if (k < (n + 1) / 2) {
        return 2 * k;
    }
}

int main() {
    int n; cin >> n;
    vector<int> prev(n + 1);
    vector<int> nxt(n + 1);

    for (int i = 1; i <= n; i++) {
        prev[i] = i - 1;
        nxt[i] = i + 1;
    }
    prev[1] = n;
    nxt[n] = 1;
    int cnt = n;
    int i = 1;
    while (cnt >= 0) {
        cout << nxt[i] << endl;
        int next = nxt[nxt[i]];
        prev[next] = i;
        nxt[i] = next;
        i = next;
        cnt--;
    }
}