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

std::pair<bool, std::vector<std::string>> cal1(std::vector<std::vector<int>> v) {
    std::vector<std::string> op;

    for (int delta = m - 2; delta >= 0; delta --) {
        for (int i = 1; i <= n; i++) {
            int j = delta + i;
            if (j < 1 || j > m) continue;
            // std::cout << i << ' ' << j << '\n';
            std::string tmp1 = "";

            for (int k = 1; k < i; k++) {
                tmp1 += 'D';
            }
            for (int k = 1; k < j; k++) {
                tmp1 += 'R';
            }

            int x = i, y = j + 1;
            int xx = i + 1, yy = j;
            int X = i, Y = j;

            for (; x <= n && y <= m && xx <= n && yy <= m; x ++, y ++, xx ++, yy ++, X ++, Y ++) {
                if (!v[x][y]) {
                    v[x][y] ^= 1;
                    tmp1 += "RD";
                } else {
                    tmp1 += "DR";
                }
            }

            while (X < n) {
                X ++;
                tmp1 += 'D';
            }
            while (Y < m) {
                Y ++;
                tmp1 += 'R';
            }

            op.push_back(tmp1);
        }
    }


    std::cout << "After1" << '\n';
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            std::cout << v[i][j] << " \n"[j == m];
        }
    }
        

    for (int delta = -n; delta <= 0; delta ++) {
        for (int i = 1; i <= n; i++) {
            int j = delta + i;
            if (j < 1 || j > m) continue;
            // std::cout << i << ' ' << j << '\n';
            std::string tmp2 = "";

            for (int k = 1; k < i; k++) {
                tmp2 += 'D';
            }
            for (int k = 1; k < j; k++) {
                tmp2 += 'R';
            }

            int x = i, y = j + 1;
            int xx = i + 1, yy = j;
            int X = i, Y = j;

            for (; x <= n && y <= m && xx <= n && yy <= m; x ++, y ++, xx ++, yy ++, X ++, Y ++) {
                if (!v[xx][yy]) {
                    v[xx][yy] ^= 1;
                    tmp2 += "DR";
                } else {
                    tmp2 += "RD";
                }
            }

            while (X < n) {
                X ++;
                tmp2 += 'D';
            }
            while (Y < m) {
                Y ++;
                tmp2 += 'R';
            }

            op.push_back(tmp2);
        }
    }

    std::cout << "After2" << '\n';
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            std::cout << v[i][j] << " \n"[j == m];
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
void solve() {
    std::cin >> n >> m;

    std::vector<std::string> s(n + 1);
    std::vector<std::vector<int>> v(n + 1, std::vector<int>(m + 1));

    for (int i = 1; i <= n; i++) {
        std::cin >> s[i];
        s[i] = ' ' + s[i];

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
    auto [ok1, op1] = cal1(v);
    
    if (ok1) {
        ok = true;
        op = op1;
    } else {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (i != 1 && j != m) {
                    v[i][j] ^= 1;
                }
                // std::cout << v[i][j] << " \n"[j == m];
            }
        }
        std::string str;
        for (int i = 1; i < m; i++) {
            str += "R";
        }
        for (int i = 1; i < n; i++) {
            str += "D";
        }
        auto [ok2, op2] = cal1(v);
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
        std::cout << op.size() << '\n';
        // if (op.size() > 400) {
        //     std::cout << op.size() << '\n';
        // }
        for (auto x : op) {
            std::cout << x << '\n';
        }
    } else {
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