#include <bits/stdc++.h>
using namespace std;
int n;
const int MAXN = 1e5 * 2 + 1;
vector<int> tp(MAXN);
vector<int> pathLength(MAXN);
vector<int> visited(MAXN);
queue<int> q;
int steps = 0;

void dfs(int node) {
    q.push(node);
    if (visited[node]) {
        steps += pathLength[node];
        return;
    }
    visited[node] = true;
    steps++;
    dfs(tp[node]);
}

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> tp[i];
    }
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            steps = 0;
            dfs(i);
            int d = 1;
            while (!q.empty()) {
                if (q.front() == q.back()) {
                    d = 0;
                }
                pathLength[q.front()] = steps;
                steps -= d;
                q.pop();
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << pathLength[i] << ' ';
    }
}