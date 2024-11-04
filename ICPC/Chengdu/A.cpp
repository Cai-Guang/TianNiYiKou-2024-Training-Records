#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
    std::string s;
    std::cin >> s;
    const int n = s.size();
    s = ' ' + s;

    int p = n;
    while (p >= 1 && s[p] == '>') {
        p--;
    }
    // p + 1 ~ n;
    if (n - p <= 2 || p == 0 || s[1] == '-') {
        std::cout << "No\n";
        return;
    }  

    std::vector<std::pair<int, int>> ans;
    for (int i = n; i > p + 2; i--) {
        ans.push_back({i - 4, 5});
    }
    for (int i = 1; i <= p; i++) {
        if (s[i] == '>') {
            ans.push_back({i, p - i + 4});
        }
    }

    std::cout << "Yes ";
    std::cout << ans.size() << "\n";
    for (auto [x, y] : ans) {
        std::cout << x << " " << y << "\n";;
    }

    
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int t = 1;
    std::cin >> t;
    while (t --) {
        solve();
    }
}