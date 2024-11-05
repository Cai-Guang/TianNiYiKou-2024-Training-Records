#include <bits/stdc++.h>

using namespace std;

#define int long long

const int V = 20100;
const int E = 201000;
using ll = long long;
template<typename T>
struct MaxFlow {
    int s, t, vtot;
    int head[V], etot, cur[V];
    int pre[V];
    bool vis[V];
    T dis[V], cost, flow;
    struct edge {
        int v, nxt;
        T f, c;
    }e[E * 2];
    void addedge(int u, int v, T f, T c, T f2 = 0) {
        e[etot] = {v, head[u], f, c}; head[u] = etot++;
        e[etot] = {u, head[v], f2, -c};head[v] = etot++;
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
MaxFlow<int> g;

mt19937 mrand(0);

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    for (int i = 1; i <= 20; i++) {
        int n = mrand() % 100 + 2;
        int m = mrand() % (n * n) + 1;
        int s = n - 1, t = n;
        g.init(s, t, t);
        for (int i = 1; i <= m; i++) {
            int u, v, w, c;
            u = mrand() % n + 1;
            v = mrand() % n + 1;
            w = mrand() % 1000;
            c = mrand() % 1000;
            g.addedge(u, v, w, c);
        }
        auto [ans1, ans2] = g.sol();
        cout << ans1 << " " << ans2 << "\n";
    }

}