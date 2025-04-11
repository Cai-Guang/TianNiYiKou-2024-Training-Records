#include <bits/stdc++.h>

using namespace std;

#define int long long

 
void solve() {
    std::string t;
    std::getline(std::cin, t);
    int n;
    std::cin >> n;

    std::set<std::string> st;
    for (int i = 1; i <= n; i++) {
        std::string s;
        std::cin >> s;
        for (auto &x : s) {
            x = std::tolower(x);
        }

        st.insert(s);
    }

    std::stringstream ss(t);

    std::string s;
    int ans = 0;
    while (ss >> s) {
        if (!std::isalpha(s.back())) {
            s.pop_back();
        }
        for (auto &x : s) {
            x = std::tolower(x);
        }
        // std::cerr << s << std::endl;
        if (!st.count(s)) {
            ans++;
            st.insert(s);
        }
    }
    std::cout << ans << "\n";
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