#include <bits/stdc++.h>
#define int long long
using namespace std;
using i64 = long long;


void solve() {
    int n;
    std::cin >> n;
    int mx = -1;
    std::vector<int> ans;
    for (int i = 1; i <= n; i++) {
        int x;
        std::cin >> x;
        if (x > mx) {
            mx = x;
            ans.clear();
            ans.push_back(i);
        } else if (mx == x) {
            ans.push_back(i);
        }

    }

    for (int i = 0; i < ans.size(); i++) {
        std::cout << ans[i] << " \n"[i == ans.size() - 1];
    }
}
signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}