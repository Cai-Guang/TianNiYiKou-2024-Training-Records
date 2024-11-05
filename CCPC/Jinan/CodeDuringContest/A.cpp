#include <bits/stdc++.h>

using namespace std;

#define int long long

using i64 = long long;

void solve() {
    int n, m, k;
    std::cin >> n >> m >> k;
    std::vector a(n + 2, std::vector<std::string>  (m + 2));

    std::map<std::string, int> cnt;
    std::map<std::string, std::pair<int, int>> pos;
    for (int i = 1; i <= n; i++) {
        std::string s;
        std::cin >> s;
        for (int j = 1; j <= m; j++) {
            a[i][j] = s.substr((j - 1) * k, k);
            cnt[a[i][j]]++;
            pos[a[i][j]] = {i, j};
        }
    }

    for (auto [s, x] : cnt) {
        if (x == 1) {
            auto [a, b] = pos[s];
            std::cout<< a << " " << b << "\n";
            return;
        }
    }
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int t = 1;
    // std::cin >> t;
    while (t--) {
        solve();
    }
}