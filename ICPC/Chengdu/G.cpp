#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

#define int long long

void solve() {
    int n;
    std::cin >> n;

    std::vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i];
    }
    
    std::set<int> s;
    for (int i = 1; i <= n; i++) {
        s.insert(a[i]);
        if (i > 1) {
            int And = a[i] & a[i - 1];
            int Or = a[i] | a[i - 1];
            int Xor = a[i] ^ a[i - 1];
            s.insert(And);
            s.insert(Xor);
            s.insert(Or);
            s.insert(And ^ a[i]);
            s.insert(And ^ a[i - 1]);
            s.insert((And ^ a[i - 1]) | (And ^ a[i]));
            s.insert(0);
        }
    }
    std::cout << s.size() << '\n';
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