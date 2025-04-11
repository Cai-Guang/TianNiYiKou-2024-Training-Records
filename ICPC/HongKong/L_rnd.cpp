#include <bits/stdc++.h>
#define int long long
using namespace std;
using i64 = long long;
int n, m;

std::pair<bool, std::vector<std::string>> cal(std::vector<std::vector<int>> v) {
    std::vector<std::string> op;

    for (int delta = m - 2; delta >= -n; delta --) {
        for (int i = 1; i <= n; i++) {
            int j = delta + i;
            if (j < 1 || j > m) continue;
            // std::cout << i << ' ' << j << '\n';
            std::string tmp1 = "";
            std::string tmp2 = "";

            for (int k = 1; k < i; k++) {
                tmp1 += 'D';
                tmp2 += 'D';
            }
            for (int k = 1; k < j; k++) {
                tmp1 += 'R';
                tmp2 += 'R';
            }

            int x = i, y = j + 1;
            int xx = i + 1, yy = j;
            int X = i, Y = j;

            for (; x <= n && y <= m && xx <= n && yy <= m; x ++, y ++, xx ++, yy ++, X ++, Y ++) {
                if (!v[x][y]) {
                    v[x][y] ^= 1;
                    v[xx][yy] ^= 1;
                    tmp1 += "RD";
                    tmp2 += "DR";
                } else {
                    tmp1 += "DR";
                    tmp2 += "DR";
                }
            }

            while (X < n) {
                X ++;
                tmp1 += 'D';
                tmp2 += 'D';
            }
            while (Y < m) {
                Y ++;
                tmp1 += 'R';
                tmp2 += 'R';
            }

            op.push_back(tmp1);
            op.push_back(tmp2);
        }
    }


    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (!v[i][j]) {
                return {false, {}};
            }
        }
    }

    return {true, op};
}
int rnd(int l, int r) {
    return rand() % (r - l + 1) + l;
}
void solve() {
    // std::cin >> n >> m;
    n = m = 200;
    std::vector<std::vector<int>> s(n + 1, std::vector<int>(m + 1));
    std::vector<std::vector<int>> v(n + 1, std::vector<int>(m + 1));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            s[i][j] = rnd(0, 1);
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            v[i][j] = s[i][j] == s[1][1];
        }
    }

    // return;

    bool ok = false;
    std::vector<std::string> op;
    std::map<std::string, int> mp;
    auto [ok1, op1] = cal(v);
    
    if (ok1) {
        ok = true;
        op = op1;
    } else {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (i == 1 || j == m) {
                    v[i][j] ^= 1;
                }
            }
        }
        std::string str;
        for (int i = 1; i < m; i++) {
            str += "R";
        }
        for (int i = 1; i < n; i++) {
            str += "D";
        }
        auto [ok2, op2] = cal(v);
        if (ok2) {
            ok = true;
            op = op2;
            op.push_back(str);
        }
    }

    if (ok) {
        std::cout << "YES\n";
        for (auto x : op) {
            mp[x] ++;
        }
        op.clear();
        for (auto [x, y] : mp) {
            if (y & 1) {
                op.push_back(x);
            }
        }
        // std::cout << op.size() << '\n';
        if (op.size() > 400) {
            std::cout << op.size() << std::endl;
        }
        // for (auto x : op) {
        //     std::cout << x << '\n';
        // }
    } else {
        // std::cout << "NO\n";
    }
}
signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    srand(time(NULL));
    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}