#include <bits/stdc++.h>

using namespace std;

#define int long long

struct STMin {
    int n;
    std::vector<std::vector<int>> st;
    STMin(int n) : n(n), st(n + 1, std::vector<int>(40)) {}
    STMin() {}

    void init(std::vector<int> a) {
        for (int i = 1; i <= n; i++) {
            st[i][0] = a[i];
        }

        for (int j = 1; j <= 22; j++) {
            for (int i = 1; i + (1 << j) - 1 <= n; i++) {
                st[i][j] = std::min(st[i][j - 1], st[i + (1LL << (j - 1))][j - 1]);
            }    
        }
    }

    int query(int l, int r) {
        if (r < l) return (int)1e18;
        int g = std::__lg(r - l + 1);
        return std::min(st[l][g], st[r - (1LL << g) + 1][g]);
    }
};


struct STMax {
    int n;
    std::vector<std::vector<int>> st;
    STMax(int n) : n(n), st(n + 1, std::vector<int>(40)) {}
    STMax() {}

    void init(std::vector<int> a) {
        for (int i = 1; i <= n; i++) {
            st[i][0] = a[i];
        }

        for (int j = 1; j <= 22; j++) {
            for (int i = 1; i + (1 << j) - 1 <= n; i++) {
                st[i][j] = std::max(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
            }    
        }
    }

    int query(int l, int r) {
        if (r < l) return (int)-1e18;
        int g = std::__lg(r - l + 1);
        return std::max(st[l][g], st[r - (1 << g) + 1][g]);
    }
};

void solve() {
    int n;
    std::cin >> n;

    std::vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i];
    }

    STMin stmin(n);
    STMax stmax(n);
    stmin.init(a);
    stmax.init(a);
    int ans = 1e18;

    for (int i = 1; i <= n; i++) {
        int L = 1, R = i;
        auto check = [&](int x) {
            int range_mi = stmin.query(x, i);
            int range_ma = stmax.query(x, i);
            int out_mi = std::min(stmin.query(1, x - 1), stmin.query(i + 1, n));
            int out_ma = std::max(stmax.query(1, x - 1), stmax.query(i + 1, n));
            int ret = std::max(range_ma - range_mi, out_ma - out_mi);
            ans = std::min(ans, ret);
            return ret; 
        };

        while (L + 5 < R) {
            int Len = (R - L + 1) / 3;
            int Lm = L + Len;
            int Rm = L + 2 * Len;

            if (check(Lm) < check(Rm)) {
                R = Rm;
            } else {
                L = Lm;
            }
        }

        for (int j = 1; j <= i; j++) {
            std::cout << i << ' ' << j << ' ' << check(j) << '\n';
            check(j);
        }
    }

    std::cout << ans << '\n';
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