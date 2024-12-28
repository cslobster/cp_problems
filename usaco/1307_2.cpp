#include <bits/stdc++.h>
using namespace std;

const int MXN = 303;

int n;
vector<int> a, b;

int p[MXN];
int ans[2][MXN][19][19][3];

void solve(int x) {
    for (int i = 0; i < n; i++) {
        for (int l = 0; l < 19; l++) {
            for (int r = 0; r < 19; r++) {

            }
        }
    }
}

void read_string(vector<int> &v) {
    string s;
    cin >> s;
    for (auto c : s) {
        v.push_back(c - '0');
    }
}

int main() {
    cin >> n;
    read_string(a), read_string(b);

    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }

}