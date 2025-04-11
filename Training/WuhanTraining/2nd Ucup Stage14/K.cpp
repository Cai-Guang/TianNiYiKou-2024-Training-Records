#include <bits/stdc++.h>

using namespace std;

#define int long long
void solve() {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> ans(n + 1);
    int p = 0;
    for (int i = 1; i <= n; i++) {
        int x;
        std::cin >> x;
        if (x == 1) {
            ans[i] = p;
            p = (p + 1) % k;
        } else {
            p = (p - 1 + k) % k;
            ans[i] = p;
        }
    }
    for (int i = 1; i <= n; i++) {
        std::cout << ans[i] + 1 << " \n"[i == n];
    }
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    std::cin >> t;

    while (t --) {
        solve();
    }
}