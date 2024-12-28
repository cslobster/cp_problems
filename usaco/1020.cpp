#include <bits/stdc++.h>
using namespace std;

const int MXN = 1e5 + 3;

int n;
vector<int> adj[MXN];
int dp[MXN];

bool check2(vector<int> &v, int mid, int k) {
    int l = 0, r = v.size() - 1;
    while (l < r) {
        if (l == mid) {l++; continue;}
        if (r == mid) {r--; continue;}
        if (v[l] + v[r] < k) return false;;
        l++, r--;
    }
    return true;
}


bool dfs(int node, int par, int k) {
    vector<int> v;
    for (auto ch : adj[node]) if (ch != par) {
        if (!dfs(ch, node, k)) return false;
        v.push_back(dp[ch] + 1);
    }
    if (node == 1) {
        if (v.size() % 2 == 1) v.push_back(0);
        sort(v.begin(), v.end());
        return check2(v, -1, k);
    }

    if (v.size() % 2 == 0) {
        v.push_back(0);
    }
    sort(v.begin(), v.end());

    int l = -1;
    int r = v.size();
    while (l < r - 1) {
		int mid = l + (r - l) / 2;
        if (check2(v, mid, k)) {
            l = mid;
        }
        else {
            r = mid;
        }
    }
    if (l == -1) return false;

    dp[node] = v[l];
    return true;
}

bool check(int k) {
    for (int i = 1; i <= n; i++) dp[i] = 1;
    return dfs(1, -1, k);
}

int main() {
    ifstream cin("deleg.in");
    ofstream cout("deleg.out");

    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int l = 0;
    int r = n + 1;
    while (l < r - 1) {
		int mid = l + (r - l) / 2;
        if (check(mid)) {
            l = mid;
        }
        else {
            r = mid;
        }
    }
    cout << l << endl;
}