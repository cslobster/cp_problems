#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> c(n);
    for (int i = 0; i < n; i++) cin >> c[i];
    vector<vector<bool>> dp(k + 1, vector<bool>(k + 1));
    dp[0][0] = true;
    for (int i = 0; i < n; i++) {
        for (int j = k; j >= 0; j--) {
            for (int l = k; l >= 0; l--) {
                if (j >= c[i] && l >= c[i])
                    dp[j][l] = dp[j][l] | dp[j - c[i]][l - c[i]];
                if (j >= c[i])
                    dp[j][l] = dp[j][l] | dp[j - c[i]][l];
            }
        }
    }
    vector<int> ans;
    for (int i = 0; i <= k; i++) {
        if (dp[k][i]) ans.push_back(i);
    }
    cout << ans.size() << "\n";
    for (auto e : ans) {
        cout << e << " ";
    }
}