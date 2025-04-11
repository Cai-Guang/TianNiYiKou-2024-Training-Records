#include <bits/stdc++.h>

using namespace std;

#define int long long

 
void solve() {
    int n;
    std::cin >> n;

    std::vector<int> x(n + 1), y(n + 1);

    for (int i = 1; i <= n; i++) {
        std::cin >> x[i] >> y[i];
    }

    std::vector<double> dp(n + 1);

    auto Dis = [&](int i, int j) -> double {
        return std::sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]));
    };

    for (int i = 1; i <= n; i++) {
        double ma = 0;
        for (int j = i; j >= 1; j--) {
            ma = std::max(ma, Dis(i, j));
            dp[i] = std::max(dp[j - 1] + ma, dp[i]);
        }
    }

    std::cout << std::fixed << std::setprecision(10) << dp[n] << '\n';
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