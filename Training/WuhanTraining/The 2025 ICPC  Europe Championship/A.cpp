#include <bits/stdc++.h>

using namespace std;
#define int long long

void tst() {
    std::cerr << std::endl;
}

template<typename T, typename... Ts>
void tst(T t, Ts... ts) {
    std::cerr << t;
    tst(ts...);
}

#define test tst

void solve() {
    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<int>> ans;

    std::map<std::array<int, 2>, int> mp;
    for (int i = 1; i <= m; i++) {
        std::vector<int> a;
        int u, v;
        std::cin >> u >> v;
        if (mp.count({u, v})) {
            std::cout << "NO\n";
            return;
        }
        mp[{v, u}] = 1;
        for (int i = 1; i <= n; i++) {
            if (i != u && i != v) {
                a.push_back(i);
            }
        }

        std::vector<int> s, t;
        s.push_back(u);
        s.push_back(v);
        for (auto x : a) {
            s.push_back(x);
        }
        std::reverse(a.begin(), a.end());
        for (auto x : a) {
            t.push_back(x);
        }
        t.push_back(u);
        t.push_back(v);
        ans.push_back(s);
        ans.push_back(t);
    }

    std::cout << "YES\n";
    std::cout << ans.size() << '\n';
    for (auto x : ans) {
        for (auto y : x) {
            std::cout << y << ' ';
        } std::cout << '\n';
    }
   
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