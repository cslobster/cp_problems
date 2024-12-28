#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MXN = 2e5 + 3;

struct Particle {
    int type; ll p, s;
    int i;
    // type: 0 for +, 1 for -
    Particle *prev = nullptr, *next = nullptr;
    Particle(int t, ll pos, ll speed, int _i) {
        type = t;
        p = pos;
        s = speed;
        i = _i;
    }
};

struct Particles {
    Particle *a, *b;
    Particles(Particle *i, Particle *j) {
        a = i;
        b = j;
    }
};

ll meetingTime(Particles p1) {
    Particle *a = p1.a, *b = p1.b;
    assert(b->type != a->type);
    ll dist = b->p - a->p;
    ll speedSum = a->s + b->s;
    return 2 * ((dist + speedSum - 1) / speedSum) - b->type;
}

bool operator<(const Particles &p1, const Particles &p2) {
    ll t1 = meetingTime(p1);
    ll t2 = meetingTime(p2);
    return t2 < t1;
}

int n;
Particle* particles[MXN];
ll pp[MXN], ss[MXN], ans[MXN];

void clear() {
    memset(particles, 0, sizeof(particles));
}

void solve() {
    priority_queue<Particles> pq;

    cin >> n;
    for (int i = 0; i < n; i++) cin >> pp[i];
    for (int i = 0; i < n; i++) cin >> ss[i];
    for (int i = 0; i < n; i++) {
        ll p = pp[i], s = ss[i];
        particles[i] = new Particle(i % 2, p, s, i);
        if (i) {
            particles[i]->prev = particles[i - 1];
            particles[i - 1]->next = particles[i];
            pq.push({particles[i - 1], particles[i]});
        }
        ans[i] = -1;
    }
    while (!pq.empty()) {
        Particles p = pq.top();
        pq.pop();
        if (ans[p.a->i] != -1 || ans[p.b->i] != -1) continue;
        // this is the next to disappear
        ll time = meetingTime(p);
        ans[p.a->i] = time;
        ans[p.b->i] = time;
        // p1, p2, p3, p4
        // destroy p1 -> p2, p2 -> p3, p3 -> p4
        // replace with p1 -> p4
        if (p.a->prev != nullptr && p.b->next != nullptr) {
            p.a->prev->next = p.b->next;
            p.b->next->prev = p.a->prev;
            Particles temp(p.a->prev, p.b->next);
            pq.push(temp);
        }
    }
    for (int i = 0; i < n; i++) {
        cout << ans[i];
        if (i != n - 1) cout << " ";
    }
    cout << endl;
}

int main() {
    int t; cin >> t;
    while (t--) solve();
}



11000
00011
