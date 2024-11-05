#include <bits/stdc++.h>

using namespace std;

#define int long long

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;

    std::vector<int> x(n + 1), y(n + 1), z(n + 1);

    std::map<int, int> Gx, Gy, Gz;

    for (int i = 1; i <= n; i++) {
        std::cin >> x[i] >> y[i] >> z[i];
        Gx[x[i]] ++;
        Gy[y[i]] ++;
        Gz[z[i]] ++;
    }

    std::vector<int> cnt(n + 10);

    for (int i = 1; i <= n; i++) {
        int X = Gx[x[i]];
        int Y = Gy[y[i]];
        int Z = Gz[z[i]];
        int mi = std::max({X, Y, Z});
        cnt[mi] ++;
    }

    for (int i = 0; i < n; i++) {
        if (i) cnt[i] += cnt[i - 1];
        std::cout << cnt[i] << " \n"[i == n - 1];
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