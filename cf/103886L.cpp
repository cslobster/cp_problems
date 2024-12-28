#include <bits/stdc++.h>
using namespace std;

const int MXN = 503, MXK = 12, MXM = (1 << 12);

struct Fossil {
    int i, j, w;
};

int n, k, m;
char grid[MXN][MXN];
Fossil fossils[MXK];

int main() {
    cin >> n >> k >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }
    for (int i = 0; i < k; i++) {

    }
}