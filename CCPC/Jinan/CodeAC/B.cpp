#include <bits/stdc++.h>

using namespace std;

#define int long long
void test() {
    std::cerr << "\n";
}
template<typename T, typename... Args>
void test(T x, Args... args) {
    std::cerr << x << " ";
    test(args...);
}
using i64 = long long;

void solve() {
    int n;
    std::cin >> n;

    std::array<int, 5> cnt{};

    for (int i = 1; i <= n; i++) {
        std::string s;
        std::cin >> s;
        if (s[1] == 'D') {
            cnt[1]++;
        } else if (s[1] == 'C') {
            cnt[2]++;
        } else if (s[1] == 'H') {
            cnt[3]++;
        } else if (s[1] == 'S') {
            cnt[4]++;
        } else {
            assert(0);
        }
    }

    int t1, t2, t3, t4, t5, t6;
    std::cin >> t1 >> t2 >> t3 >> t4 >> t5 >> t6;

    int ans = 0;
    for (int c1 = 0; c1 <= 5; c1++) {
        for (int c2 = 0; c2 <= 5; c2++) {
            for (int c3 = 0; c3 <= 5; c3++) {
                for (int c4 = 0; c4 <= 5; c4++) {
                    for (int p1 = 1; p1 <= 4; p1++) {
                        for (int p2 = 1; p2 <= 4; p2++) {

                            int tot = (c1 + c2 + c3 + c4) * 5;
                            if (tot > n) continue;
                            auto have = cnt;

                            if (t1) {
                                have[1] += 3;
                            }
                            if (t2) {
                                have[2] += 3;
                            }
                            if (t3) {
                                have[3] += 3;
                            }
                            if (t4) {
                                have[4] += 3;
                            }
                            if (t5) have[p1]++;
                            if (t6) have[p2]++;

                            // test(c1, c2, c3, c4, p1, p2, tot, n, have[1], have[2], have[3], have[4]);
                            if (c1 * 5 <= have[1] && c2 * 5 <= have[2] && c3 * 5 <= have[3] && c4 * 5 <= have[4]) {
                                ans = std::max(ans, tot / 5);
                            }
                        }
                    }
                }
            }
        }
    }
    std::cout << ans << "\n";
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