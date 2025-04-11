#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve() {  
    const int M = 10;
    const int MM = 10;
    int n = rand() % M + 1;
    std::cout << n << '\n';
    for (int i = 1; i <= n; i++) {
        cout << rand() % MM << " ";
    }
    std::cout << '\n';
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    srand(time(0));
    int t = 10;
    std::cout << 10 << '\n';
    // std::cin >> t;

    while (t --) {
        solve();
    }
}