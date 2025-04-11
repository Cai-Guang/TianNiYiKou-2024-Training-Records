#include <bits/stdc++.h>

using namespace std;

#define int long long


void solve() {
    int n, m;

    std::cin >> n >> m;
    
    if ((n * m) % 4) {
        std::cout << "NO\n";
        return;
    }

    if (n == 2 && m == 2) {
        std::cout << "NO\n";
        return;
    }

    int idx = 0;

    bool is = n & 1;

    if (!is) {
        std::swap(n, m);
    }

    std::vector<std::vector<int>> ans(n + 10, std::vector<int>(m + 10));
    auto add14 = [&](int x, int y) {
        ++idx;
        for (int i = 1; i <= 4; i++) {
            ans[x][y + i - 1] = idx;
        }
    };
    auto add41 = [&](int x, int y) {
        ++idx;
        for (int i = 1; i <= 4; i++) {
            ans[x + i - 1][y] = idx;
        }
    };
    auto add24 = [&](int x, int y) {
        add14(x, y);
        add14(x + 1, y);
    };
    auto add42 = [&](int x, int y) {
        add41(x, y);
        add41(x, y + 1);
    };

    auto add26 = [&](int x, int y) {
        add14(x, y + 1);
        ++idx;
        ans[x][y] = ans[x + 1][y] = ans[x + 1][y + 1] = ans[x + 1][y + 2] = idx;
        ++idx;
        ans[x][y + 5] = ans[x + 1][y + 5] = ans[x + 1][y + 4] = ans[x + 1][y + 3] = idx;
    };

    auto add62 = [&](int x, int y) {
        add41(x + 1, y);
        ++idx;
        ans[x][y] = ans[x][y + 1] = ans[x + 1][y + 1] = ans[x + 2][y + 1] = idx;
        ++idx;
        ans[x + 5][y] = ans[x + 5][y + 1] = ans[x + 4][y + 1] = ans[x + 3][y + 1] = idx;
    };

    if (n == 2) {
        if (m % 4 == 0) {
            for (int i = 1; i <= m; i += 4) {
                add24(1, i);
            }
        } else {
            add26(1, 1);
            for (int i = 7; i <= m; i += 4) {
                add24(1, i);
            }
        }
    } else if (m == 2) {
        if (n % 4 == 0) {
            for (int i = 1; i <= n; i += 4) {
                add42(i, 1);
            }
        } else {
            add62(1, 1);
            for (int i = 7; i <= n; i += 4) {
                add42(i, 1);
            }
        }
    } else {
        int k = m / 12;
        int mod = m % 12;

        if (mod == 4 || mod == 8 || mod == 0) {
            for (int i = 1; i < n; i += 2) {
                for (int j = 1; j <= m; j += 4) {
                    add24(i, j);
                }
            }
        } else if (mod == 2) {
            for (int i = 1; i < n; i += 2) {
                int j = 1;
                for (int d = 1; d < k; d ++) {
                    add24(i, j);
                    j += 4;
                    add24(i, j);
                    j += 4;
                    add24(i, j);
                    j += 4;
                }
                add24(i, j);
                j += 4;
                add24(i, j);
                j += 4;
                add26(i, j);
                j += 6;
            }
        } else if (mod == 10) {
            for (int i = 1; i < n; i += 2) {
                int j = 1;
                for (int d = 1; d <= k; d ++) {
                    add24(i, j);
                    j += 4;
                    add24(i, j);
                    j += 4;
                    add24(i, j);
                    j += 4;
                }
                add24(i, j);
                j += 4;
                add26(i, j);
                j += 6;
            }
        } else if (mod == 6) {
            for (int i = 1; i < n; i += 2) {
                int j = 1;
                for (int d = 1; d <= k; d ++) {
                    add24(i, j);
                    j += 4;
                    add24(i, j);
                    j += 4;
                    add24(i, j);
                    j += 4;
                }
                add26(i, j);
                j += 6;
            }
        }

        if (n & 1) {
            for (int j = 1; j <= m; j += 4) {
                add14(n, j);
            }
        }
    }

    std::cout << "YES\n";

    if (is) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                std::cout << ans[i][j] << " \n"[j == m];
            }
        }
    } else {
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                std::cout << ans[j][i] << " \n"[j == n];
            }
        }
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