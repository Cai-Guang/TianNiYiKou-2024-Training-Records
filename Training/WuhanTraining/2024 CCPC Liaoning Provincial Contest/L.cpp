#include <bits/stdc++.h>

using namespace std;

#define int long long

int calcPin(int n) {
    int ans = n;
    for (int i = 1; i <= 1E18; i *= 100) {
        ans -= n / (4 * i);
        if (i > 1E17) break;
        ans += n / (100 * i);
    }
    return ans;
}
 
void solve() {
    int k;
    std::cin >> k;

    int lo = 2024, hi = 4E18;
    while (lo + 1 < hi) {

        auto check = [&](int mid) {
            int tot = mid - 2024;
            
            int pin = calcPin(mid) - calcPin(2024);
            if (pin < k) return false;
            return true;
        };

        int mid = (lo + hi) / 2;
        if (check(mid)) {
            hi = mid;
        } else {
            lo = mid;
        }
    }
    std::cout << hi << "\n";
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