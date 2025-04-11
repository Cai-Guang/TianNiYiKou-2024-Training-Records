#include <bits/stdc++.h>
#define int long long
using namespace std;
using i64 = long long;

void solve() {
    int n, m;
    std::cin >> n >> m;

    std::vector<std::string> s(n + 1);
    std::vector<std::vector<int>> v(n + 1, std::vector<int>(m + 1));

    for (int i = 1; i <= n; i++) {
        std::cin >> s[i];
        s[i] = ' ' + s[i];
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            v[i][j] = s[i][j] == s[1][1];
        }
    }

    std::vector<std::array<int, 4>> op;

    for (int i = 1; i + 1 <= n; i++) {
        for (int j = 2; j <= m; j++) {
            if (v[i][j] == 0) {
                v[i][j] ^= 1;
                v[i + 1][j - 1] ^= 1;
                op.push_back({i, j, i + 1, j - 1});
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (!v[i][j]) {
                std::cout << "NO\n";
                return;
            }
        }
    }

    std::cout << "YES\n";
    
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