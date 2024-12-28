#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    int ans = 1;
    char prev = '-';
    int i = -1;
    for (int j = 0; j < s.size(); j++) {
        if (s[j] != prev) {
            i = j - 1;
            prev = s[j];
        } else {
            ans = max(ans, j - i);
        }
    }
    cout << ans << endl;
}