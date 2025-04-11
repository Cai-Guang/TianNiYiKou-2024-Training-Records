#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve() {
    int n;
    std::cin >> n;
    
    std::vector<std::vector<int>> adj(n + 1);
    for (int i = 1; i < n; i++) {
        int u, v;
        std::cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    std::vector<int> f(n + 1, 1E18), g(n + 1, 1E18);
    // f none
    // g exactly one is remained
    
    auto dfs = [&](auto &&self, int x, int fx) -> void {
        int sum = 0;
        int cntson = 0;
        for (auto y : adj[x]) {
            if (y == fx) continue;
            self(self, y, x);
            sum += f[y];
            cntson++;
        }
        if (cntson == 0) {
            f[x] = 2;
            g[x] = 0;
        } else {

            g[x] = sum;
            for (auto y : adj[x]) {
                if (y == fx) continue;

                sum -= f[y];
                sum += g[y]; 

                f[x] = std::min(f[x], sum + 1);
                
                sum += f[y];
                sum -= g[y];
            }
        }

    };
    dfs(dfs, 1, 0);


    // for (int i = 1; i <= n; i++) {
    //     std::cerr << f[i] << " \n"[i == n];
    // }
    // for (int i = 1; i <= n; i++) {
    //     std::cerr << g[i] << " \n"[i == n];
    // }

    std::cout << f[1] << "\n";

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