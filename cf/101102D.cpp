#include <iostream>
#include <vector>
using namespace std;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int r, c;
        cin >> r >> c;
        vector<vector<int>> grid(r, vector<int>(c));
        vector<vector<int>> lc(r, vector<int>(c));
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                cin >> grid[i][j];
            }
        }

        for (int i = 0; i < r; i++) {
            int cnt = 0, val = -1;
            for (int j = 0; j < c; j++) {
                if (grid[i][j] == val) cnt++;
                else {
                    cnt = 1;
                    val = grid[i][j];
                }
                lc[i][j] = cnt;
            }
        }

        long long ans = 0;
        for (int j = 0; j < c; j++) {
            vector<pair<int, int>> s;
            int sum = 0, val = grid[r - 1][j];
            for (int i = r - 1; i >= 0; i--) {
                if (grid[i][j] != val) {
                    val = grid[i][j];
                    sum = 0;
                    s = vector<pair<int, int>>();
                }
                int cnt = 0;
                while (!s.empty() && s.back().first > lc[i][j]) {
                    sum -= (s.back().second + 1) * (s.back().first - lc[i][j]);
                    cnt += s.back().second + 1;
                    s.pop_back();
                }
                s.push_back({lc[i][j], cnt});
                sum += lc[i][j];
                ans += sum;
            }
        }
        cout << ans << "\n";
    }
}
