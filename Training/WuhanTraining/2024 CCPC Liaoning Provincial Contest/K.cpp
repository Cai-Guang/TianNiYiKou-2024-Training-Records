#include <bits/stdc++.h>

using namespace std;

#define int long long

const int M = 500005;
void solve() {
    int n;
    std::cin >> n;

    std::vector<std::array<int, 3>> query;
    std::vector<std::vector<int>> vec(500005);
    for (int i = 1; i <= n; i++) {
        int o;
        std::cin >> o;
        if (o == 1) {
            int x;
            std::cin >> x;
            vec[x].push_back(i);
        } else {
            int x;
            std::cin >> x;
            int l = vec[x].back();
            vec[x].pop_back();
            int r = i - 1;
            query.push_back({l, r, x});
        }
    }

    for (int i = 1; i <= 500000; i++) {
        while (vec[i].size()) {
            int l = vec[i].back();
            vec[i].pop_back();
            int r = n;
            query.push_back({l, r, i});
        }
    }

    
    std::vector<int> ans;
    auto dfs = [&](auto &self, int l, int r, std::vector<std::array<int, 3>> &query, std::bitset<M> mask) -> void {
        
        
        
        int mid = (l + r) / 2;
        std::vector<std::array<int, 3>> L, R;
        for (auto [ql, qr, x] : query) {
            if (ql <= l && qr >= r) {
                mask |= (mask << x);
            } else {
                if (ql <= mid) {
                    L.push_back({ql, qr, x});
                }
                if (qr > mid) {
                    R.push_back({ql, qr, x});
                }
            }
        }

        if (l == r) {
            ans.push_back(mask.count() - 1);
            // std::cout << mask << "\n";
            return;
        }

        self(self, l, mid, L, mask);
        self(self, mid +1, r, R, mask);
    };

    std::bitset<M> mask;
    mask[0] = 1;

    dfs(dfs, 1, n, query, mask);

    for (int i = 0; i < n; i++) {
        std::cout << ans[i] << "\n";
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