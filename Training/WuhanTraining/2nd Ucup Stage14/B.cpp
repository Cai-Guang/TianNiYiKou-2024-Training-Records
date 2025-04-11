#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve() {
    int n;
    std::cin >> n;
    std::vector<std::pair<int, int> > a(n + 1);
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i].first;
        a[i].second = i;
        // std::cin >> a[i];
    }

    // int l = 1, r = n;
    
    std::vector<int> ans(n + 1);

    std::sort(a.begin() + 1, a.end());
    int target = a[1].first + a[n].first;
    for (int l = 1, r = n; l <= r; l++, r--) {
        if (a[l].first + a[r].first != target) {
            std::cout << "-1\n";
            return;
        } else {
            ans[a[l].second] = a[r].second;
            ans[a[r].second] = a[l].second;
        }
    }
    // for (int i = 1; i <= n; i++) {
    //     if (ans[i] == 0) {

    //         if (i == a[i]) {
    //             ans[i] = (l + r) / 2;
    //             if (n % 2 == 0) {
    //                 std::cout << "-1\n";
    //                 return;
    //             }
    //         } else if (i == a[a[i]]) {
    //             ans[i] = l;
    //             ans[a[i]] = r;
    //             l++;
    //             r--;
    //         } else {
    //             std::cout << "-1\n";
    //             return;
    //         }
    //     }
    // }

    for (int i = 1; i <= n; i++) {
        std::cout << ans[i] << " \n"[i == n];
    }


    // std::sort(a.begin() + 1, a.end());
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