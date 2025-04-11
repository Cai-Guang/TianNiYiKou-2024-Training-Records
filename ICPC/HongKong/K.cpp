#include <bits/stdc++.h>
#define int long long
using namespace std;
using i64 = long long;

void solve() {
    std::string s;
    std::cin >> s;

    int n = s.size();
    s = ' ' + s;
    
    std::vector<std::array<int, 2>> nxt(n + 2);
    
    int lstL = n + 1, lstR = n + 1;

    for (int i = n; i >= 0; i--) {
        nxt[i][0] = lstL;
        nxt[i][1] = lstR;
        if (s[i] == 'L') {
            lstL = i;
        } else {
            lstR = i;
        }
    }

    int q;
    std::cin >> q;
    for (int i = 1; i <= q; i++) {
        std::string t;
        std::cin >> t;

        int lst = 0;
        if (t[0] == 'R') {
            if (s[1] != 'R') {
                goto G;
            }
        }
        if (t.back() == 'L') {
            if (s.back() != 'L') {
                goto G;
            }
        }

        lst = nxt[0][t[0] == 'R'];

        if (lst > n) {
            goto G;
        }

        for (int j = 1; j < t.size(); j++) {
            // std::cout << lst << ' ';
            if (nxt[lst][t[j] == 'R'] <= n) {
                lst = nxt[lst][t[j] == 'R'];
            } else {
                goto G;
            }
        }

        std::cout << "YES\n";
        continue;
        G:;
        std::cout << "NO\n";
    }
}
signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}