#include <bits/stdc++.h>
using namespace std;

string fix(int a) {
    string s = to_string(a);
    while (s.size() != 2) {
        s = '0' + s;
    }
    return s;
}

int main() {
    int t; cin >> t;
    while (t--) {
        int a, b; char c;
        cin >> a >> c >> b;
        char d = 'A';
        if (a > 12) d = 'P';
        if (a == 0) {
            a = 12;
            d = 'A';
        } else if (a == 12) {
            d = 'P';
        } else {
            a %= 12;
        }
        cout << fix(a) << ':' << fix(b) << " " << d << "M" << endl;
    }
}