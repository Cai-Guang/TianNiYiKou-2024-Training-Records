#pragma GCC ("Ofast, unroll-loops")
#pragma comment(linker, "/STACK:1024000000,1024000000")

#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N=5e4+8;
int Lg[N];

void solve() {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> a(n + 1), b(n + 1);

    std::map<int, int> mp;

    int mi = 2e9;
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i];
        mi = std::min(mi, a[i]);
        b[i] = a[i];
    }
    std::map<int, int> ct;

    for (int i = 1; i <= n; i++) {
        ct[a[i]] ++;
    }

    if (ct.size() == 1) {
        std::cout << k << ' ' << (1ll + k) * 1ll * k / 2 << '\n';
        return;
    }

    int GCD = 0;
    for (int i = 1; i <= n; i++) {
        GCD = std::__gcd(GCD, a[i] - mi);
    }

    int cnt = 0, ans = 0;

    std::vector st(n + 1, std::vector<std::pair<int, int>>(32));
    for (int i = 1; i <= n; i++) {
        st[i][0] = {a[i], i};
    }
    for (int i = 1; i <= 30; i++) {
        for (int j = 1; j + (1 << i) - 1 <= n; j++) {
            st[j][i] = std::min(st[j][i - 1], st[j + (1ll << (i - 1))][i - 1]);
        }
    }

    auto querymi = [&](int l, int r) {
        int len = r - l + 1;
        int LG = Lg[len];
        return std::min(st[l][LG], st[r - (1ll << LG) + 1][LG]);
    };

    bool check = true;
    auto sol = [&](int x) {
        check = true;
        if (x <= mi || x - mi > k) {
            return;
        }
        std::function<void(int, int, int)> cal = [&](int l, int r, int y) {
            if (l == r) {
                if ((a[l] + x - mi) % y != 0) {
                    check = false;
                }
            }
            if (l >= r || !check) {
                return;
            }
            auto [MI, pos] = querymi(l, r);
            
            MI += x - mi;
            if (MI % y != 0) {
                check = false;
                return;
            }
            cal(l, pos - 1, MI);
            cal(pos + 1, r, MI);
        };
        cal(1, n, 1);
        if (check) {
            cnt ++;
            ans += x - mi;
        }
    };

    for (int g = 1; g * g <= GCD; g++) {
        if (GCD % g == 0) {
            sol(g);
            if (GCD != g * g) {
                sol(GCD / g);
            }
        }
    }

    std::cout << cnt << ' ' << ans << '\n';
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int t = 1;
    std::cin >> t;
    Lg[0] = -1;
    for (int i = 1; i < N; i++) {
        Lg[i] = Lg[i / 2] + 1;
    }
    while (t--) {
        solve();
    }
}