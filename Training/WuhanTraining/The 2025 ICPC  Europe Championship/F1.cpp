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
        s[i] = ' ' + s[i];
    }
    std::string t;
    std::cin >> t;
    std::vector<std::string> ans(t.size() + 1, "");
    std::vector<int> is(t.size() + 10, 0);

    for (int i = 1; i <= n; i++) {
        std::vector<std::array<int, 26>> nxt(s[i].size() + 10, std::array<int, 26>{});
        for (int j = 0; j < 26; j++) {
            nxt[s[i].size() - 1][j] = s[i].size();
        }
        for (int j = s[i].size() - 1; j >= 1; j--) {
            nxt[j - 1] = nxt[j];
            nxt[j - 1][s[i][j] - 'a'] = j;
        }
        // for (int k = 1; k < s[i].size(); k++) {
        //     for (int j = 0; j < 26; j++) {
        //         std::cout << nxt[k][j] << " \n"[j == 25];
        //     }
        // }
        int idx = 0, k = 0;
        while (idx < s[i].size() && k < t.size()) {
            int now = idx;
            idx = nxt[idx][t[k] - 'a'];
            if (s[i][idx] == t[k]) is[k] ++;
            for (int j = now + 1; j < idx; j++) {
                ans[k] += s[i][j];
            }
            k ++;
        }
        for (int j = idx + 1; j < s[i].size(); j++) {
            ans[k] += s[i][j];
        }
    }
    std::string S = "";

    bool ok = true;
    for (int i = 0; i < t.size(); i++) {
        S += ans[i];
        if (is[i]) {
            S += t[i];
        }
        ok = ok & (is[i] != 0);
        // std::cout << is[i] << ' ';
    }
    
    if (ok) {
        std::cout << "NO\n";
        return;
    }

    std::cout << "YES\n";
    std::cout << S << '\n';
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    // freopen("F.in", "r", stdin);
    int t = 1;
    // std::cin >> t;

    while (t --) {
        solve();
    }
}