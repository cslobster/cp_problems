#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    map<char, vector<char>> adj;
    vector<string> s(n);
    map<char, int> in;
    for (int i = 0; i < n; i++) {
       cin >> s[i];
    }
    for (int i = 0; i < n - 1; i++) {
        // comparing i and i + 1
       for (int j = 0; j < s[i].size(); j++) {
           if (j >= s[i].size()) {
               cout << "Impossible\n"; return 0;
           }
           if (s[i][j] == s[i + 1][j]) continue;
           adj[s[i][j]].push_back(s[i + 1][j]);
           in[s[i + 1][j]]++;
           break;
       }
    }
    queue<char> q;
    for (int i = 0; i < 26; i++) {
        char c = 'a' + i;
        if (in[c] == 0) q.push(c);
    }
    int cnt = 0;
    string ans = "";
    while (!q.empty()) {
        char c = q.front();
        q.pop();
        ans += c;
        cnt++;
        for (auto ch : adj[c]) {
            in[ch]--;
            if (in[ch] == 0) q.push(ch);
        }
    }
    if (cnt == 26) cout << ans << endl;
    else cout << "Impossible\n";
}