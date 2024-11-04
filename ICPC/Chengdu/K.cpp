#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
// #define int long long

const int V = 101000;
const int E = 2010000;
template<typename T>
struct MaxFlow {
    int s, t, vtot;
    int head[V], etot, cur[V];
    int pre[V];
    bool vis[V];
    T dis[V], cost, flow;
    struct edges {
        int v, nxt;
        T f, c;
    }e[E * 2];
    void addedge(int u, int v, T f, T c, T f2 = 0) {
        e[etot] = {v, head[u], f, c}; head[u] = etot++;
        e[etot] = {u, head[v], f2, -c}; head[v] = etot++;
    }
    bool spfa() {
        T inf = numeric_limits<T>::max() / 2;
        for (int i = 1; i <= vtot; i++) {
            dis[i] = inf;
            vis[i] = false;
            pre[i] = -1;
            cur[i] = head[i];
        }
        dis[s] = 0;
        vis[s] = true;
        queue<int> q;
        q.push(s);
        while (!q.empty()) {
            int u = q.front();
            for (int i = head[u]; ~i; i = e[i].nxt) {
                int v = e[i].v;
                if (e[i].f && dis[v] > dis[u] + e[i].c) {
                    dis[v] = dis[u] + e[i].c;
                    pre[v] = i;
                    if (!vis[v]) {
                        vis[v] = 1;
                        q.push(v);
                    }
                }
            }
            q.pop();
            vis[u] = false;
        }
        return dis[t] < inf;
    }
    void augment() {
        int u = t;
        T f = numeric_limits<T>::max();
        while (~pre[u]) {
            f = min(f, e[pre[u]].f);
            u = e[pre[u] ^ 1].v;
        }
        flow += f;
        cost += f * dis[t];
        u = t;
        while (~pre[u]) {
            e[pre[u]].f -= f;
            e[pre[u] ^ 1].f += f;
            u = e[pre[u] ^ 1].v;
        }
    }
    pair<T, T> sol() {
        flow = cost = 0;
        while (spfa()) {
            augment();
        }
        return {flow, cost};
    }
    void init(int s_, int t_, int vtot_) {
        s = s_;
        t = t_;
        vtot = vtot_;
        etot = 0;
        for (int i = 1; i <= vtot; i++) {
            head[i] = -1;
        }
    }   
};

MaxFlow<int> G;

void solve() {
    int n;
    std::cin >> n;
    int idx = 0;
    std::vector<int> a(n + 1);
    std::set<int> s;
    std::vector have(n + 1, std::vector<int>());
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i];
        std::vector<int> v;
        for (int j = 1; j * j <= a[i]; j++) {
            if (a[i] % j == 0) {
                v.push_back(j);
                if (a[i] != j * j) {
                    v.push_back(a[i] / j);
                }
            }
        }
        have[i] = v;
        std::sort(v.begin(), v.end());
        for (auto x : v) {
            s.insert(x);
        }
    }
    std::map<int, int> id;
    for (auto x : s) { 
        id[x] = ++idx;
    }
    int S = idx + 1, t = S + 1, T = t + 1;
    G.init(S, T, T);
    for (auto x : s) {
        for (auto y : s) {
            if (x != y && x % y == 0) G.addedge(id[x], id[y], 1e8, -1);
        }
    }
    for (int i = 1; i <= n; i++) {
        G.addedge(S, id[a[i]], 1, 0);
    }
    for (auto [x, y] : id) {
        G.addedge(y, t, 1, 0);
    }
    G.addedge(t, T, n, 0);

    auto [flow, cost] = G.sol();

    std::cout << -cost << '\n';
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int t = 1;
    // std::cin >> t;
    while (t --) {
        solve();
    }
}