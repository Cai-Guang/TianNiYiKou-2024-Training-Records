#include <bits/stdc++.h>
#define int long long
using namespace std;
using i64 = long long;

void solve() {
    int n;
    std::cin >> n;

    std::vector<int> a(n + 1);

    std::vector<int> c(9), emp(9), C(7);

    for (int i = 1; i <= n; i++) {
        std::cin >> a[i];
    }

    int ans = 0;

    std::vector<int> d(9);

    std::vector<int> cnt(10000);

    auto check = [&]() -> void {
        cnt.assign(10000, 0);
        c.assign(9, 0);
        cnt[0] ++;
        int ok_cnt = 0;
        std::vector<int> ok(9);
        for (int i = 1; i < 9; i++) {
            if (!d[i]) {
                ok_cnt ++;
                ok[i] = 1;
            }
        }
        std::vector<int> have(9);
        std::vector<int> need(9);

        for (int i = 1; i < 9; i++) {
            need[i] = -d[i];    
        }

        int st = -1;
        for (int i = 1; i <= n; i++) {
            have[a[i]] ++;
            if (have[a[i]] >= d[a[i]] && !ok[a[i]]) {
                ok_cnt ++;
                ok[a[i]] = 1;
            }
            if (ok_cnt == 8) {
                st = i;
                break;
            }
        }

        auto to_c = [&]() -> int {
            int ret = 0;
            for (int i = 1; i <= 8; i++) {
                ret *= 3;
                ret += c[i];
            }
            return ret;
        };

        auto to_need = [&]() -> int {
            int ret = 0;
            for (int i = 1; i <= 8; i++) {
                ret *= 3;
                ret += need[i];
            }
            return ret;
        };

        auto minus = [&](int pos) {
            c[a[pos]] ++;
            if (c[a[pos]] >= 3) {
                c[a[pos]] -= 3;
            }
            cnt[to_c()] ++;
        };
        auto plus = [&](int pos) {
            need[a[pos]] += 1;
            if (need[a[pos]] >= 3) {
                need[a[pos]] -= 3;
            }
        };
        for (int i = 1; i < st; i++) {
            plus(i);
        }
        if (st == -1) return;

        have[a[st]] --;

        for (int l = 1, r = st; r <= n; r++) {
            have[a[r]] ++;
            plus(r);
            while (l < r and have[a[l]] > d[a[l]]) {
                have[a[l]] --;
                minus(l);
                l ++;
            }
            ans += cnt[to_need()];
        }
    };

    auto dfs = [&](auto &&self, int pos) -> void {
        if (pos == 7) {
            d.assign(9, 0);
            for (int i = 1; i <= 6; i++) {
                for (int j = 0; j < 3; j++) {
                    d[i + j] += C[i];
                }
            }
            check();
            return;
        }

        for (int i = 0; i < 3; i++) {
            C[pos] = i;
            self(self, pos + 1);
        }
    };

    dfs(dfs, 1);

    std::cout << ans << '\n';
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