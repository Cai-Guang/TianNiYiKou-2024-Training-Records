#include <bits/stdc++.h>

using namespace std;

#define int long long

 
void solve() {
    int n;
    std::cin >> n;

    int a, b, c;
    std::cin >> a >> b >> c;
    
    std::vector<int> x(n + 1), y(n + 1);
    for (int i = 1; i <= n; i++) {
        std::cin >> x[i] >> y[i];
    }
    int d;
    std::cin >> d;

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (x[i] + y[i] < c) {
            x[i] += d;
            if (x[i] > a) {
                x[i] = a;
            }
            if (x[i] + y[i] >= c) {
                ans ++;
            }
        }
    }
    
    std::cout << ans << '\n';
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    // std::cin >> t;

    while (t --) {
        solve();
    }
}