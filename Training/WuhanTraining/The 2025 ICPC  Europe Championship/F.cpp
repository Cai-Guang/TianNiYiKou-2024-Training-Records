#include <bits/stdc++.h>

using namespace std;
#define int long long

// void tst() {
//     std::cerr << std::endl;
// }

// template<typename T, typename... Ts>
// void tst(T t, Ts... ts) {
//     std::cerr << t;
//     tst(ts);
// }

// #define test tst


void solve() {
    int n;
    std::cin >> n;
    std::vector<std::string> s(n + 1);

    for (int i = 1; i <= n; i++) {
        std::cin >> s[i];
    }
    std::string t;
    std::cin >> t;

    // std::vector<int> idx(n + 1);
    // std::vector<std::vector<int>> v(300, std::vector<int>());
    // for (int i = 1; i <= n; i++) {
    //     v[s[i][idx[i]]].push_back(i);
    // }
    // for (auto x : t) {
    //     for (int i = 'a'; i <= 'z'; i++) {
    //         if (i == x) {
    //             continue;
    //         }
            
    //     }
    // }

    std::vector<std::vector<std::pair<int, int> > > vec(26);
    std::string ans;
    for (int i = 1; i <= n; i++) {
        int x = s[i][0] - 'a';
        vec[x].push_back({i, 0});
    }

    for (int i = 0; i < t.size(); i++) {
        int x = t[i] - 'a';
        

        while (1) {
            for (int j = 0; j < 26; j++) {
                if (j != x) {
                    if (!vec[j].size()) {
                        continue;
                    }
             
                    std::vector<std::array<int, 3>> q;
                    ans += char('a' + j);
                    for (auto [x, y] : vec[j]) {
                        y++;
                        if (y < s[x].size()) {
                            q.push_back({s[x][y] - 'a', x, y});
                        }
                    }

                    vec[j].clear();

                    for (auto [c, x, y] : q) {
                        vec[c].push_back({x, y});
                    }
                }
            }

            int cnt = 0;
            int sum = 0;
            for (int i = 0; i < 26; i++) {
                sum += vec[i].size();
                if (i == x) {
                    continue;
                }
                cnt += vec[i].size();
            }

            if (cnt == 0) {
                break;
            }
            
            if (sum <= 0) {
                std::cout << "YES\n";
                std::cout << ans << "\n";
                return;
            }
        }

        int sum = 0;
        for (int i = 0; i < 26; i++) {
            sum += vec[i].size();
        }

        if (sum == 0) {
            std::cout << "YES\n";
            std::cout << ans << "\n";
            return;
        }

        if (i == t.size() - 1) break;

        int j = x;

        std::vector<std::array<int, 3>> q;
        ans += char('a' + j);
        for (auto [x, y] : vec[j]) {
            y++;
            if (y < s[x].size()) {
                q.push_back({s[x][y] - 'a', x, y});
            }
        }
        vec[x].clear();
        for (auto [c, x, y] : q) {
            vec[c].push_back({x, y});
        }
        sum = 0;
        for (int i = 0; i < 26; i++) {
            sum += vec[i].size();
        }
        // std::cerr << i << " " << ans << " " << sum << std::endl;
        if (sum == 0) {
            std::cout << "YES\n";
            std::cout << ans << "\n";
            return;
        }
        

    }
    std::cout << "NO\n";
    // std::cout << ans << "\n";

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