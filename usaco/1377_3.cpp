#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MXN = 2e5 + 3, INF = 2e9;

struct Query {
    int x, y, d;
};

int n, q, hn, vn;
int h[MXN], v[MXN], ans[MXN][2];
set<int> vs, hs;
Query queries[MXN];
int startParity[MXN];
vector<int> hPath, vPath;

pair<int, int> move(int steps, int x, int y, int hi, int vi, int startParity) {
    int turn = startParity; // 1 for H move, 0 for V move
    int mv = steps / 2;
    vi += steps / 2, hi += steps / 2;
    if (steps % 2 == 1) {
        if (startParity == 0) vi++;
        else hi++;
    }
    if (hi >= hPath.size() || vi >= vPath.size()) return {-1, -1};
    return {hPath[hi], vPath[vi]};
}

bool check(int d, int steps, int x, int y, int hi, int vi, int startParity) {
    auto [nx, ny] = move(steps, x, y, hi, vi, startParity);
    if (nx == -1) return false;
    int dist = nx + ny - x - y;
    return dist <= d;
}

int main() {
    // ifstream cin("text.in");
    cin >> n >> q;
    for (int i = 0; i < n; i++) {
        char c; cin >> c;
        if (c == 'H') {
            cin >> h[hn++];
            hs.insert(h[hn - 1]);
        } else {
            cin >> v[vn++];
            vs.insert(v[vn - 1]);
        }
    }
    sort(h, h + hn);
    sort(v, v + vn);

    int prevParity = 1 - (v[0] % 2);
    for (int i = 0; i < vn; i++) {
        if (v[i] % 2 == 1 - prevParity) {
            prevParity = v[i] % 2;
            hPath.push_back(v[i]);
        }
    }

    prevParity = 1 - (h[0] % 2);
    for (int i = 0; i < hn; i++) {
        if (h[i] % 2 == 1 - prevParity) {
            prevParity = h[i] % 2;
            vPath.push_back(h[i]);
        }
    }

    for (int i = 0; i < q; i++) {
        ans[i][0] = -1, ans[i][1] = -1;
        int x, y, d; cin >> x >> y >> d;
        startParity[i] = 0;
        // search to find which V road
        auto vi = vs.lower_bound(x);
        auto hi = hs.lower_bound(y);
        int vr, hr;
        if (vi != vs.end()) vr = *vs.lower_bound(x);
        else vr = -1;
        if (hi != hs.end()) hr = *hs.lower_bound(y);
        else hr = -1;
        assert(!(vr == -1 && hr == -1));
        if (vr == -1) {
            ans[i][0] = x + d;
            ans[i][1] = y;
            continue;
        }
        if (hr == -1) {
            ans[i][0] = x;
            ans[i][1] = y + d;
            continue;
        }
        if (!(vr == x && hr == y)) {
            // not on both roads, bad!
            if (vr == x) {
                // only on V road, simulate to get to intersection!!
                // goal is hr
                int dist = hr - y;
                assert(dist >= 0);
                if (dist % 2 == 1) startParity[i] = 1;
                if (d - dist <= 0) {
                    // already there !!
                    ans[i][0] = x;
                    ans[i][1] = y + d;
                    continue;
                }
                d -= dist;
                y = hr;
            } else if (hr == y) {
                // only on H road
                int dist = vr - x;
                assert(dist >= 0);
                if (dist % 2 == 1) startParity[i] = 1;
                if (d - dist <= 0) {
                    // already made it
                    ans[i][0] = x + d;
                    ans[i][1] = y;
                    continue;
                }
                d -= dist;
                x = vr;
            } else {
                // ?????
                assert(vr == x || hr == y);
            }
        }
        queries[i] = {x, y, d};
    }

    hs.insert(INF);
    vs.insert(INF);
    // what is the path if you start on even coordinates?
    // horizontal path
    // start on v[0]


    for (int i = 0; i < q; i++) {
        if (ans[i][0] != -1) continue;
        auto &[x, y, d] = queries[i];
        // binary search to find what segment you are originally on
        int vi = lower_bound(vPath.begin(), vPath.end(), y) - vPath.begin();
        int hi = lower_bound(hPath.begin(), hPath.end(), x) - hPath.begin();
        // if you can just jump to the answer
        if (vPath[vi] != y) vi--;
        if (hPath[hi] != x) hi--;
        if (startParity[i] == 1) {
            if (hi + 1 < hPath.size() && x + d <= hPath[hi + 1]) {
                ans[i][0] = x + d;
                ans[i][1] = y;
                continue;
            }
        } else {
            if (vi + 1 < vPath.size() && y + d <= vPath[vi + 1]) {
                ans[i][0] = x;
                ans[i][1] = y + d;
                continue;
            }
        }
        int change = y + x - vPath[vi] - hPath[hi];
        if (change % 2 == 1) startParity[i] = 1 - startParity[i];
        d += change;
        x = hPath[hi], y = vPath[vi];
        int l = 0;
        int r = 1e9;
        while (l != r) {
            int mid = (l + r + 1)/2;
            if (check(d, mid, x, y, hi, vi, startParity[i])) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        if (l == 0) {
            if (startParity[i] == 0) y += d;
            else x += d;
            ans[i][0] = x, ans[i][1] = y;
            continue;
        }
        auto [nx, ny] = move(l, x, y, hi, vi, startParity[i]);
        int finalDirection = startParity[i];
        if (l % 2 == 1) finalDirection = 1 - finalDirection;
        // 0 for H, 1 for V
        int distLeft = d - (nx + ny - x - y);
        if (finalDirection == 0) ny += distLeft;
        else nx += distLeft;
        ans[i][0] = nx, ans[i][1] = ny;
    }
    for (int i = 0; i < q; i++) {
        cout << ans[i][0] << " " << ans[i][1] << endl;
    }
}
