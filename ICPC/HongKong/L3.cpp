#include <bits/stdc++.h>
#define int long long
using namespace std;
using i64 = long long;

void solve() {

    int n, m;
    std::cin >> n >> m;
    std::vector<std::string> s(n + 1);
    for (int i = 1; i <= n; i++) {
        std::cin >> s[i];
        s[i] = ' ' + s[i];
    }

    std::vector<std::vector<int>> v(n + 1, std::vector<int> (m + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            v[i][j] = (s[i][j] == 'W');
        }
    }

    auto work = [&](int n, int m, std::vector<std::vector<int>>, int target) -> std::pair<bool, std::vector<std::string> > {

        std::vector<std::string> operations;

        for (int stx = n; stx > 1; stx--) {
            int x = stx, y = 1;
            std::string tmp(stx, 'R');
            

        }

        for (int sty = m; sty > 1; sty--) {
            int x = 1, y = sty;
        }
    };

    auto [flag, operations] = work(n, m, v, 0);

    if (flag == true) {
        std::cout << "YES\n";
        std::cout << operations.size() << "\n";
        for (auto s : operations) {
            std::cout << s << "\n";
        }
        return;
    }

    work(n, m, v, 1);

    if (flag == true) {
        std::cout << "YES\n";
        std::cout << operations.size() << "\n";
        for (auto s : operations) {
            std::cout << s << "\n";
        }
        return;
    }

    std::cout << "NO\n";
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