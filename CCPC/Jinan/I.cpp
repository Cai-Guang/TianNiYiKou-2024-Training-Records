#include <bits/stdc++.h>

using namespace std;

#define int long long



void test() {
    std::cerr << "\n";
}
template<typename T, typename... Args>
void test(T x, Args... args) {
    std::cerr << x << " ";
    test(args...);
}

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::vector<std::vector<int>> adj(n + 1);
    std::vector<int> d(n + 1);
    for (int i = 1; i < n; i++) {
        int u, v;
        std::cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        d[u]++;
        d[v]++;
    }

    int root = 0;
    for (int i = 1; i <= n; i++) {
        if (d[i] % 2 == 0) {
            root = i;
            break;
        }
    }

    if (root == 0) {
        for (int i = 1; i <= n; i++) {
            for (auto j : adj[i]) {
                if (d[i] == 1 && d[j] == 2) {
                    root = i;
                    goto G;
                }
            }
        }
    }
    G:;
    if (root == 0) {
        root = 1;
        std::vector<int> f(n + 1), sz(n + 1, 1);
        auto dfs = [&](auto self, int x, int fx) {
            for (auto y : adj[x]) {
                if (y == fx) continue;
                self(self, y, x);
                sz[x] += sz[y];
                f[x] = std::max(f[x], f[y]);
            }
            f[x] = std::max(f[x], n - f[x]);
        };

        root = std::min_element(f.begin() + 1, f.end()) - f.begin();
    }

    std::vector<int> lst(n + 1);
    std::vector<std::pair<int, int>> ans;

    std::vector<int> fa(n + 1), dep(n + 1);
    auto dfs = [&](auto self, int x, int fx) -> void {
        std::vector<std::pair<int, int> > vec;
        for (auto y : adj[x]) {
            if (y == fx) continue;
            dep[y] = dep[x] + 1;
            fa[y] = x;
            self(self, y, x);
            if (lst[y] != y) {
                vec.push_back({1, lst[y]});
            } else {
                vec.push_back({0, lst[y]});
            }
        }
        std::sort(vec.begin(), vec.end());
        for (int i = 0; i + 1 < vec.size(); i += 2) {
            ans.push_back({vec[i].second, vec[i + 1].second});
        }

        if (vec.size() % 2 == 1) {
            lst[x] = vec.back().second;
        } else {
            lst[x] = x;
        }

    };
    dfs(dfs, root, 0);



    if (lst[root] == root) {
        lst[root] = 0;
    } else if (fa[lst[root]] != root) {
        ans.push_back({lst[root], root});
        lst[root] = 0;
    }


    if (lst[root]) {
        std::cout << "-1\n";
    } else {
        std::cout << ans.size() << "\n";
        for (auto [x, y] : ans) {
            std::cout << x << " " << y << "\n";
        }
    }
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int t = 1;
    std::cin >> t;
    while (t--) {
        solve();
    }
}