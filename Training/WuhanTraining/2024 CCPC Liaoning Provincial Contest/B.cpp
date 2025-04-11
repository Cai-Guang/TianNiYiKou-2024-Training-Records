#include <bits/stdc++.h>

using namespace std;

#define int long long

 
void solve() {
    std::string s;
    std::cin >> s;

    std::reverse(s.begin(), s.end());

    std::cout << s << '\n';
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