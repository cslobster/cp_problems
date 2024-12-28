#include <bits/stdc++.h>
using namespace std;

const int MXN = 2e5 + 3;

int n;
pair<int, int> movies[MXN];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> movies[i].second >> movies[i].first;
    }
    sort(movies, movies + n);
    int cnt = 0;
    int prevEnd = 0;
    for (int i = 0; i < n; i++) {
        if (movies[i].second < prevEnd) continue;
        cnt++;
        prevEnd = movies[i].first;
    }
    cout << cnt << endl;
}