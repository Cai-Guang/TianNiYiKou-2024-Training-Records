#include <bits/stdc++.h>

using namespace std;
#define int long long

void tst() {
    std::cerr << std::endl;
}

template<typename T, typename... Ts>
void tst(T t, Ts... ts) {
    std::cerr << t;
    tst(ts...);
}

#define test tst

void solve() {
    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<int>> adj(n + 1);
    for (int i = 1; i <= m; i++) {
        int u, v;
        std::cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    std::vector<int> dis1(n + 1, 1E18), disn(n + 1, 1E18);
    auto bfs = [&](int s, std::vector<int> &dis) {
        std::queue<int> q;
        std::vector<int> vis(n + 1);
        q.push(s);
        vis[s] = true;
        dis[s] = 0;
        while (!q.empty()) {
            int x = q.front();
            q.pop();

            for (auto y : adj[x]) {
                if (vis[y] == 0) {
                    vis[y] = 1;
                } else if (vis[y] == 1) {
                    vis[y] = 2;
                    q.push(y);
                    dis[y] = dis[x] + 1;
                }
                if (vis[y] == false) {
                    vis[y] = true;
                }
            }
        }

    };

    
    bfs(1, dis1);
    bfs(n, disn);
    for (int i = 1; i <= n; i++) {
        std::cout << dis1[i] << " \n"[i == n];
    }
    
    for (int i = 1; i <= n; i++) {
        std::cout << disn[i] << " \n"[i == n];
    }
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    // std::cin >> t;

    while (t --) {
        solve();
    }
}