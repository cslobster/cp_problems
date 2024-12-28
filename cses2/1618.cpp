#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ll n;
    cin >> n;
    ll ans = 0;
    ll biggestMult = 5;
    while (n >= biggestMult) {
        ans += n / biggestMult;
        biggestMult *= 5;
    }
    cout << ans << endl;
}