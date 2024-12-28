#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int MAX = 5e5 + 5, MOD = 1e9 + 7;

int n, lp, recR, good[MAX]; char A[MAX]; ll sum[2], dp[MAX]; vector<int> pts;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    dp[0] = sum[0] = good[0] = 1;

    for (int i = 1; i <= n; i++){
        cin >> A[i];
        good[i] = true;

        // Insert [i - 2, i - 2]
        if (i - 1 >= 1 and A[i - 1] == 'B')
            pts.push_back(i - 1);

        // Update bad positions to transition from
        vector<int> npts;

        for (int p : pts){
            if (p - 1 >= 0 and good[p - 1]){
                good[p - 1] = false;
                if (p - 1 >= lp)
                    sum[(p - 1) % 2] = (sum[(p - 1) % 2] - dp[p - 1] + MOD) % MOD;
                npts.push_back(p - 1);
            }
        }
        pts = npts;

        // Update for nearest R
        if (A[i] == 'R')
            recR = i;

        // Only consider bound...i
        int bound = max(i - 2 * (i - recR + 1) + 1, 0); // the point on the left of the range, earliest valid bc of recent R
        // lp = earliest index already subtracted, in this case you have to subtract from lp...bound since everything < bound is invalid
        while (lp < bound){
            sum[lp % 2] = (sum[lp % 2] - dp[lp] * good[lp] + MOD) % MOD;
            lp++;
        } // everything that is valid (>lp) should be added to the sum?
        while (lp > bound){
            lp--;
            sum[lp % 2] = (sum[lp % 2] + dp[lp] * good[lp]) % MOD;
        }

        // Choose to not paint
        dp[i] = (dp[i - 1] * (A[i] == 'X') + sum[i % 2]) % MOD;
        sum[i % 2] = (sum[i % 2] + dp[i]) % MOD;
    }
    cout << dp[n] << "\n";
}