#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(2 * n + 1);
    for (int i = 1; i <= 2 * n; i++) {
        std::cin >> a[i];
    }

    std::sort(a.begin() + 1, a.end());

    int f = 0, z = 0;
    for (int i = 1; i <= n; i++) {
        f += a[i];
    }
    for (int i = 1 + n; i <= 2 * n; i++) {
        z += a[i];
    }

    std::cout << z - f << '\n';
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