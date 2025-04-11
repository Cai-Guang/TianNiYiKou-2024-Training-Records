#include <bits/stdc++.h>

using namespace std;

#define int long long

 
void solve() {
    int n;
    std::cin >> n;

    std::vector<std::vector<int>> G(n + 1, std::vector<int>());
    std::vector<int> a(n + 1);

    a[0] = 2200;

    for (int i = 1; i <= n; i++) {
        int f;
        std::cin >> f >> a[i];
        G[f].push_back(i);
    }

    std::vector<int> have, used;
    std::vector<int> need(n + 1);
    auto dfs = [&](auto && self, int x) -> void {
        for (auto y : G[x]) {
            self(self, y);
            need[x] += need[y];
        }
        if (G[x].size() == 0) {
            need[x] = a[x];
        } else if (x != 0) {
            have.push_back(a[x]);
            used.push_back(need[x]);
        } else {
            if (need[x] > a[x]) {
                std::cout << "NO\n";
                exit(0);
            }
        }
    };

    dfs(dfs, 0);

    std::sort(used.begin(), used.end());
    std::sort(have.begin(), have.end());

    for (int i = 0; i < have.size(); i++) {
        if (have[i] < used[i]) {
            std::cout << "NO\n";
            return;
        }
    }
    
    std::cout << "YES\n";
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