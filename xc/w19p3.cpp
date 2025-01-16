#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MXN = 1e7 + 3, MXM = 503;
class HashedString {
private:
    // change M and B if you want
    static const ll M = (1LL << 61) - 1;
    static const ll B;

    // pow[i] contains B^i % M
    static vector<ll> pow;

    // p_hash[i] is the hash of the first i characters of the given string
    vector<ll> p_hash;

    __int128 mul(ll a, ll b) { return (__int128)a * b; }
    ll mod_mul(ll a, ll b) { return mul(a, b) % M; }

public:
    HashedString(const string &s) : p_hash(s.size() + 1) {
        while (pow.size() < s.size()) { pow.push_back(mod_mul(pow.back(), B)); }
        p_hash[0] = 0;
        for (int i = 0; i < s.size(); i++) {
            p_hash[i + 1] = (mul(p_hash[i], B) + s[i]) % M;
        }
    }

    ll get_hash(int start, int end) {
        ll raw_val = p_hash[end + 1] - mod_mul(p_hash[start], pow[end - start + 1]);
        return (raw_val + M) % M;
    }
};
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());
vector<ll> HashedString::pow = {1};
const ll HashedString::B = uniform_int_distribution<ll>(0, M - 1)(rng);

int n, m;
string s, t;
int dp[MXM][MXM];
vector<int> pos;

int main() {
    cin >> s >> m;
    n = s.size();
    pos.push_back(0);
    for (int i = 0; i < n; i++) {
        t += s[n - i - 1];
        if (s[i] != s[n - i - 1] && i != 0 && i != n - 1) {
            pos.push_back(i);
        }
    }
    pos.push_back(n - 1);
    HashedString ss(s), tt(t);
    auto eq = [&](int i1, int j1, int i2, int j2) {
        return ss.get_hash(i1, j1) == tt.get_hash(i2, j2);
    };
    for (int len = 0; len < pos.size(); len++) {
        for (int x = 0; x + len < pos.size(); x++) {
            int y = x + len;
            int i = pos[x], j = pos[y];
            if (x != 0) {
                // go to pos[x - 1], pos[y]
                dp[x - 1][y] = max(dp[x - 1][y], dp[x][y] + pos[x] - pos[x - 1]);
            }
            if (y != pos.size() - 1) {
                // go to pos[x], pos[y + 1]
                dp[x][y + 1] = max(dp[x][y + 1], dp[x][y] + pos[y + 1]);
            }
        }
    }
    cout << dp[0][pos.size() - 1] << endl;
}