#include <bits/stdc++.h>
using namespace std;

using ll = long long;

string mult(string a, int b) {
    string ans = "";
    while (b) {
        if (b % 2 == 1) {
            ans += a;
        }
        a += a;
        b /= 2;
    }
    return ans;
}


int main() {
    string s; cin >> s;
    map<char, int> mp;
    int sum = 0;
    for (auto c : s) {
        mp[c]++;
    }
    string mid = "";
    string ans = "", ans2 = "";
    for (auto k : mp) {
        if (k.second % 2 == 1) {
            if (mid != "") {
                cout << "NO SOLUTION" << endl;
                return 0;
            }
            mid = k.first;
        }
        string ss = ""; ss += k.first;
        string temp = mult(ss, k.second / 2);
        ans += temp;
        ans2 = temp + ans2;
    }
    // cout << s.size() << " " << ans.size() << " " << mid.size() << " "<< ans2.size() << endl;
    cout << ans << mid << ans2 << endl;
}