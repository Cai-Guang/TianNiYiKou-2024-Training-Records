#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
#define int long long
const int MOD = 1E9 + 7;

void solve() {
    int n, q;
    std::cin >> n >> q;
    std::string s;
    std::cin >> s;
    s = ' ' + s;
    std::vector a(n + 1, std::vector<int> (n + 1));
    auto b = a;
    auto c = a;
    std::vector<int> pre(n + 1);
    for (int i = 1; i <= n; i++) {
        pre[i] = pre[i - 1] + (s[i] == '?');
    }

    if (s[1] == 'a') {
        a[0][0] = 1;
    } else if (s[1] == 'b') {
        b[0][0] = 1;
    } else if (s[1] == 'c') {
        c[0][0] = 1;
    } else if (s[1] == '?') {
        a[1][0] = b[0][1] = c[0][0] = 1;
    } else {
        assert(0);
    }
    for (int i = 2; i <= n; i++) {
        int sum = pre[i - 1];
        std::vector na(n + 1, std::vector<int> (n + 1));
        auto nb = na;
        auto nc = na;
        for (int x1 = 0; x1 <= sum; x1++) {
            for (int x2 = 0; x2 <= sum; x2++) {
                if (s[i] == 'a') {
                    na[x1][x2] += b[x1][x2];
                    na[x1][x2] += c[x1][x2];
                    na[x1][x2] %= MOD;
                } else if (s[i] == 'b') {
                    nb[x1][x2] += a[x1][x2];
                    nb[x1][x2] += c[x1][x2];
                    nb[x1][x2] %= MOD;
                } else if (s[i] == 'c') {
                    nc[x1][x2] += a[x1][x2];
                    nc[x1][x2] += b[x1][x2];
                    nc[x1][x2] %= MOD;
                } else if (s[i] == '?') {
                    na[x1 + 1][x2] += b[x1][x2];
                    na[x1 + 1][x2] += c[x1][x2];
                    nb[x1][x2 + 1] += a[x1][x2];
                    nb[x1][x2 + 1] += c[x1][x2];
                    nc[x1][x2] += a[x1][x2];
                    nc[x1][x2] += b[x1][x2];
                    na[x1 + 1][x2] %= MOD;
                    nb[x1][x2 + 1] %= MOD;
                    nc[x1][x2] %= MOD; 
                } else {
                    assert(0);
                }
            }
        }
        a = std::move(na);
        b = std::move(nb);
        c = std::move(nc);
    }

    std::vector f(n + 1, std::vector(n + 1, std::vector<int>(n + 1)));
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            int k = pre[n] - i - j;
            if (k < 0) continue;
            f[i][j][k] = (a[i][j] + b[i][j] + c[i][j]) % MOD;
        }
    }

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            for (int k = 0; k <= n; k++) {
                if (i) f[i][j][k] += f[i - 1][j][k];
                if (j) f[i][j][k] += f[i][j - 1][k];
                if (k) f[i][j][k] += f[i][j][k - 1];
                if (i && j) f[i][j][k] -= f[i - 1][j - 1][k];
                if (i && k) f[i][j][k] -= f[i - 1][j][k - 1];
                if (j && k) f[i][j][k] -= f[i][j - 1][k - 1];
                if (i && j && k) f[i][j][k] += f[i - 1][j - 1][k - 1];
                f[i][j][k] %= MOD;
                f[i][j][k] += MOD;
                f[i][j][k] %= MOD;
            }
        }
    }

    for (int i = 1; i <= q; i++) {
        int A, B, C;
        std::cin >> A >> B >> C;
        std::cout << f[A][B][C] << '\n';
    }
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int t = 1;
    // std::cin >> t;
    while (t --) {
        solve();
    }
}