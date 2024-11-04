#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
#define int long long

const int N = 1e6 + 10;
int Lg2[N];

void solve() {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> a(n + 1), p(n + 1), to(n + 1);

    std::vector st(n + 1, std::vector<int>(40, 0));

    for (int i = 1; i <= n; i++) {
        std::cin >> a[i];
        p[a[i]] = i;
        st[a[i]][0] = i;
        to[i] = i;
    }

    if (n % 2 == 0) {
        if (k != 1) {
            std::cout << -1 << std::endl;
        } else {
            for (int i = 1; i <= n; i++) {
                std::cout << ((a[i] & 1) ? a[i] + 1 : a[i] - 1) << " \n"[i == n];
            }
        }
        return;
    }
    if (k >= n) {
        std::cout << "-1\n";
        return;
    }

    int cnt = 0;
    std::vector<int> ans(n + 1);

    for (int j = 1; j <= 30; j++) {
        int len = (1ll << j);
        for (int i = 1; i + len - 1 <= n; i++) {
            st[i][j] = std::min(st[i][j - 1], st[i + (1ll << (j - 1))][j - 1]);
        }
    }

    std::vector<array<int, 8>> v;

    for (int i = 1; i + 2 <= n; i+= 2) {
        std::array<int, 8> a;
        for (int j = i; j <= i + 2; j++) {
            a[j - i] = j;  
        }
        a[3] = i + 1;  
        a[4] = i + 2;  
        a[5] = i;
        a[6] = i;
        a[7] = i + 2;
        v.push_back(a);  
    } 
    for (int i = 1; i + 2 <= n; i+= 2) {
        std::array<int, 8> a;
        for (int j = i; j <= i + 2; j++) {
            a[j - i] = j;  
        }
        a[3] = i + 2;  
        a[4] = i;  
        a[5] = i + 1;
        a[6] = i;
        a[7] = i + 2;
        v.push_back(a);  
    } 

    auto get = [&](int L, int R) {
        if (R < L) return (int)1e9;
        int Lg = __lg(R - L + 1);
        return std::min(st[L][Lg], st[R - (1ll << Lg) + 1][Lg]);
    };

    auto cal = [&](int lo, int hi, auto x, auto y, int mi) {
        int num = a[mi];

        int L, R;

        if (num > x[7]) {
            if (num & 1) {
                L = num - 1;
            } else {
                L = num + 1;
            }
        } else if (num < x[6]) {
            if (num & 1) {
                L = num + 1;
            } else {
                L = num - 1;
            }
        } else {
            for (int i = 3; i < 6; i++) {
                if (x[i - 3] == num) {
                    L = x[i];
                }
            }
        }

    
        if (num > y[7]) {
            if (num & 1) {
                R = num - 1;
            } else {
                R = num + 1;
            }
        } else if (num < y[6]) {
            if (num & 1) {
                R = num + 1;
            } else {
                R = num - 1;
            }
        } else {
            for (int i = 3; i < 6; i++) {
                if (y[i - 3] == num) {
                    R = y[i];
                }
            }
        }
        return std::make_pair(L, R);
    };
    auto print = [&](auto x) {
        int lo = x[6], hi = x[7];

        for (int i = 1; i < lo; i++) {
            if (i & 1) {
                to[i] = i + 1;
            } else {
                to[i] = i - 1;
            }
        }
        for (int i = 0; i < 3; i++) {
            to[x[i]] = x[i + 3];
        }
        for (int i = hi + 1; i <= n; i++) {
            if (i & 1) {
                to[i] = i - 1;
            } else {
                to[i] = i + 1;
            }
        }
        for (int i = 1; i <= n; i++) {
            std::cout << to[a[i]] << " \n"[i == n];
        }
    };


	std::nth_element(v.begin(), v.begin() + k - 1, v.end(), [&](std::array<int, 8> x, std::array<int, 8> y) {
        std::vector<int> q;
        int lo = std::min(x[6], y[6]), hi = std::max(x[7], y[7]);

        int mi = get(lo + 3, hi - 3);
        std::vector<int> Q;

        if (mi != 1E9) {
            auto [L, R] = cal(lo, hi, x, y, mi);
            Q.push_back(a[mi]);
        }
        for (int i = 1; i <= 3; i++) {
            Q.push_back(x[i - 1]);
            Q.push_back(y[i - 1]);
        }
        std::sort(Q.begin(), Q.end(), [&](int a, int b) {
            return p[a] < p[b];
        });
        for (auto val : Q) {
            auto [l, r] = cal(lo, hi, x, y, p[val]);
            if (l != r) {
                return l < r;
            }
        }
    });
    
    print(v[k - 1]);
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    Lg2[0] = -1;
    for (int i = 1; i <= 1e6; i++) {
        Lg2[i] = Lg2[i / 2] + 1;
    }
    int t = 1;
    std::cin >> t;
    while (t --) {
        solve();
    }
}