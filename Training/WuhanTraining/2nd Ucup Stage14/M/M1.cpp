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

    int ans = 1e18;

    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            for (int x = -200; x <= 200; x++) {
                // std::cout << 1;
                auto b = a;
                for (int l = i; l <= j; l++) {
                    b[l] += x;
                }
                int ma = -1e18, mi = 1e18;
                for (int l = 1; l <= n; l++) {
                    ma = std::max(ma, b[l]);
                    mi = std::min(mi, b[l]);
                }
                ans = std::min(ans, ma - mi);
            }
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