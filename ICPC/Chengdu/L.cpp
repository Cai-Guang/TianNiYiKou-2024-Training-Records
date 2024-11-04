
#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
    int a, b, c;
    std::cin >> a >> b >> c;
    std::cout << 100 << '\n';
    for (int i = 1; i <= 50; i++) {
        std::cout << a << ' ';
    }
    for (int i = 51; i <= 95; i++) {
        std::cout << b << ' ';
    }
    for (int i = 96; i <= 99; i++) {
        std::cout << c << ' ';
    }
    std::cout << (int)1e9 << '\n';
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