#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
typedef long long ll;

// Fast modular exponentiation
ll power(ll base, ll exp) {
    ll res = 1;
    base %= MOD;
    while (exp > 0) {
        if (exp & 1) res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp >>= 1;
    }
    return res;
}

// Count ways to fill space between two blues
ll count_between_blues(string& s) {
    int n = s.length();

    // Find positions of all R's
    vector<int> r_pos;
    for(int i = 0; i < n; i++) {
        if(s[i] == 'R') r_pos.push_back(i);
    }

    // If no R's, just need to ensure we can get from B to B
    if(r_pos.empty()) {
        // Can leave everything white, or place any valid interval pattern
        // that makes both ends blue
        // Formula: floor((n+2)/2) ways
        return (n + 2) / 2;
    }

    // With R's, let's count spaces between fixed positions
    ll result = 1;

    // Handle space before first R
    int first_space = r_pos[0];
    if(first_space > 0) {
        // We need to reach this R position with a red section
        // Can have any number of white spaces
        result = (result * (first_space + 1)) % MOD;
    }

    // Handle space after last R
    int last_space = n - 1 - r_pos.back();
    if(last_space > 0) {
        // Need to reach end B with a blue section
        // Can have any number of white spaces
        result = (result * (last_space + 1)) % MOD;
    }

    // Handle spaces between consecutive R's
    for(int i = 1; i < r_pos.size(); i++) {
        int gap = r_pos[i] - r_pos[i-1] - 1;
        if(gap > 0) {
            // Need to connect these R's with valid red/blue pattern
            // Can insert white spaces anywhere in between
            // Formula: floor((gap+2)/2) ways to place intervals
            result = (result * ((gap + 2) / 2)) % MOD;
        }
    }

    return result;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s = "RXXXX";  // Test between two blues
    cout << count_between_blues(s) << "\n";
    return 0;
}