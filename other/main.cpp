#include <bits/stdc++.h>
using namespace std;

using ll = long long;

mt19937_64 rnd; // 64-bit
long long val(bool positive)
{
    long long ans = rnd();
    if(positive)
        return abs(ans);
    else
        return ans;
}

/*

    In this section of the code the input data must be added, be careful at the way the input data is described in the problem statement,
copies might be necessary sometimes

*/

// Here you should generate the input data, for local testing I recommend small input data which makes testing your solution easier
void gentest()
{
    // Generate random test data within constraints
    int N = rnd() % 100 + 1; // Number of jobs (small for local testing)
    long long M = rnd() % 10000 + 1; // Maximum time Alex can work (small for local testing)
    vector<int> T(N), P(N); // Completion times and payments

    for (int i = 0; i < N; ++i) {
        T[i] = rnd() % 1000 + 1; // Random completion time between 1 and 10
        P[i] = rnd() % 10000 + 1; // Random payment between 1 and 100
    }

    // Store the generated data for reuse in other functions
    ofstream fout("input_data.txt");
    fout << N << " " << M << "\n";
    for (int i = 0; i < N; ++i) fout << T[i] << " ";
    fout << "\n";
    for (int i = 0; i < N; ++i) fout << P[i] << " ";
    fout << "\n";
    fout.close();
}

// Here you should add a correct solution, often suboptimal, hence the brute force name
ll bruteforce()
{
    ifstream fin("input_data.txt");
    static const ll NMAX = 500;
    static const ll bulan = 3000;
    ll n, m, i, j, ans = 0, maxx = 0, dp[bulan + NMAX + 2];
    struct job {
        int64_t val, cost;
    }v[NMAX + 1];
    auto cond = [&](job &a, job &b) {
        return a.val * b.cost > a.cost * b.val;
    };
    fin >> n >> m;
    memset(dp, 0, sizeof(dp));
    for (i = 0; i != n; ++ i)
        fin >> v[i].cost;
    for (i = 0; i != n; ++ i)
        fin >> v[i].val;
    if (m > bulan) {
        sort(v, v + n, cond);
        ans = (m - bulan) / v[0].cost * v[0].val;
        m = (m - bulan) % v[0].cost + bulan;
    }
    for (i = 1; i <= m; ++ i) {
        for (j = 0; j != n; ++ j)
            if (i >= v[j].cost)
                dp[i] = max(dp[i], dp[i - v[j].cost] + v[j].val);
        maxx = max(maxx, dp[i]);
    }
    ans += maxx;
    return ans;
}

// Here you should add a fast solution which is incorrect, hence the efficient name
ll efficient()
{
    ifstream fin("input_data.txt");

    const int MXN = 503, MXM = 2503, MXXX = 4003;

    int n; ll m;
    ll dp[MXXX], t[MXN], p[MXN];
    int order[MXN];

    auto comp = [&](int i, int j) {
        return p[i] * t[j] > p[j] * t[i];
    };

    fin >> n >> m;
    iota(order, order + n, 0);
    for (int i = 0; i < n; i++) fin >> t[i];
    for (int i = 0; i < n; i++) fin >> p[i];
    ll ans = 0, cur = 0;
    if (m >= MXM) {
        sort(order, order + n, comp);
        cur = ((m - (MXN - 1LL)) / t[order[0]]) * p[order[0]];
        m = (m - (MXN - 1LL)) % t[order[0]] + MXN - 1LL;
    }
    for (int i = 1; i <= m; i++) dp[i] = -1e18;
    dp[0] = 0;
    for (int i = 0; i < n; i++) {
        for (ll w = t[i]; w <= m; w++) {
            if (dp[w - t[i]] == -1e18) continue;
            dp[w] = max(dp[w], dp[w - t[i]] + p[i]);
            ans = max(ans, dp[w]);
        }
    }
    return ans + cur;

}

// In case you have different answers, this function will allow you to print the data fast
void printinput()
{

}

int main()
{
    // seed is randomly chosen, makes rnd return different numbers every time
    int seed = std::random_device{}();
    rnd.seed(seed);

    int t = 0;
    while(t <= 10000)
    {
        gentest();
        t++;
        // continue;
        cout << "E" << endl;
        int brute = bruteforce();
        int eff = efficient();
        if(brute != eff)
        {
            cout << "Brute: " << brute << '\n';
            cout << "Efficient: " << eff << '\n';
            // printinput();
            return 0;
        }
    }
    return 0;
}