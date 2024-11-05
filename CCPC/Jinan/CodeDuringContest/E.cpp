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
    int A, B, C, X, Y, D;
    std::cin >> A >> B >> C >> X >> Y >> D;

    std::vector dp(D + 1, std::vector<int>(X + Y + 1, 1e18));
    dp[0][0] = 0;
    for (int i = 1; i <= D; i++) {
        if (i >= X) dp[i][X] = std::min(dp[i - X][0] + A, dp[i][X]);
        for (int j = X + 1; j <= X + Y; j++) {
            dp[i][j] = std::min(dp[i][j], dp[i - 1][j - 1] + B);
        }
        dp[i][X + Y] = std::min(dp[i][X + Y], dp[i - 1][X + Y] + C);
        for (int j = 1; j <= X + Y; j++) {
            dp[i][0] = std::min(dp[i][j], dp[i][0]);
        }
    }
    int mi = 1e18;
    for (int i = 1; i <= X + Y; i++) {
        mi = std::min(mi, dp[D][i]);
    }
    std::cout << mi << '\n';
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