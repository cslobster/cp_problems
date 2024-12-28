#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s; cin >> s;
        int a=0, b=0;
        for (auto c : s) {
            if (c == 'A') a++;
            else b++;
        }
        if (b>a) cout << "B" << endl;
        else cout << "A" << endl;
    }
}