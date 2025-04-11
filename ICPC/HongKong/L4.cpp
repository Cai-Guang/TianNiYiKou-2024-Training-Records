#include <bits/stdc++.h>
#define int long long
using namespace std;
using i64 = long long;
int n, m;
std::pair<std::vector<std::string>, std::vector<std::vector<int>>> cal1(std::vector<std::vector<int>> v, int to) {
    std::vector<std::string> op;

    for (int delta = m - 2, j = m - 1; delta >= 0 && j > 0; delta --, j--) {
            int i = j - delta;
            if (j < 1 || j > m) continue;
            // std::cout << i << ' ' << j << '\n';
            std::string tmp1 = "";
            int x = i, y = j + 1;
            int xx = i + 1, yy = j;
            int X = 1, Y = 1;

            for (int k = 1; k < i; k++) {
                v[X][Y] ^= 1;
                tmp1 += 'D';
                X ++;
            }
            for (int k = 1; k < j; k++) {
                v[X][Y] ^= 1;
                tmp1 += 'R';
                Y ++;
            }

            for (; x <= n && y <= m && xx <= n && yy <= m; x ++, y ++, xx ++, yy ++, X ++, Y ++) {
                if (v[x][y] != to) {
                    v[X][Y] ^= 1;
                    v[x][y] ^= 1;
                    tmp1 += "RD";
                } else {
                    v[X][Y] ^= 1;
                    v[xx][yy] ^= 1;
                    tmp1 += "DR";
                }
            }

            v[X][Y] ^= 1;

            while (X < n) {
                X ++;
                tmp1 += 'D';
                v[X][Y] ^= 1;
            }
            while (Y < m) {
                Y ++;
                tmp1 += 'R';
                v[X][Y] ^= 1;
            }

            op.push_back(tmp1);
    }


    // std::cout << "After1" << '\n';
    // for (int i = 1; i <= n; i++) {
    //     for (int j = 1; j <= m; j++) {
    //         std::cout << v[i][j] << " \n"[j == m];
    //     }
    // }
    // std::cout << '\n';
        

    for (int delta = 2 - n, i = n - 1; i > 0 && delta <= 0; delta ++, i --) {
            int j = delta + i;
            if (j < 1 || j > m) continue;
            // std::cout << i << ' ' << j << '\n';
            std::string tmp1 = "";
            int x = i, y = j + 1;
            int xx = i + 1, yy = j;
            int X = 1, Y = 1;

            for (int k = 1; k < i; k++) {
                v[X][Y] ^= 1;
                tmp1 += 'D';
                X ++;
            }
            for (int k = 1; k < j; k++) {
                v[X][Y] ^= 1;
                tmp1 += 'R';
                Y ++;
            }

            for (; x <= n && y <= m && xx <= n && yy <= m; x ++, y ++, xx ++, yy ++, X ++, Y ++) {
                if (v[xx][yy] != to) {
                    v[X][Y] ^= 1;
                    v[xx][yy] ^= 1;
                    tmp1 += "DR";
                } else {
                    v[X][Y] ^= 1;
                    v[x][y] ^= 1;
                    tmp1 += "RD";
                }
            }

            v[X][Y] ^= 1;

            while (X < n) {
                X ++;
                tmp1 += 'D';
                v[X][Y] ^= 1;
            }
            while (Y < m) {
                Y ++;
                tmp1 += 'R';
                v[X][Y] ^= 1;
            }

            op.push_back(tmp1);
            // std::cout << "After " << i << ' ' << j << '\n';
            // for (int i = 1; i <= n; i++) {
            //     for (int j = 1; j <= m; j++) {
            //         std::cout << v[i][j] << " \n"[j == m];
            //     }
            // }
            // std::cout << '\n';


    }

    // std::cout << "After2" << '\n';
    // for (int i = 1; i <= n; i++) {
    //     for (int j = 1; j <= m; j++) {
    //         std::cout << v[i][j] << " \n"[j == m];
    //     }
    // }
    // std::cout << '\n';

    return {op, v};
}


std::pair<bool, std::vector<std::string>> cal(std::vector<std::vector<int>> v, int to) {
    auto [op1, v1] = cal1(v, to);
    std::vector<std::string> op = op1;
    v = v1;

    // std::vector<std::string> op; 

    for (int delta = 0, i = 1; i < n && delta >= 2 - n; delta --, i ++) {
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
                if (v[x][y] != to) {
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

    for (int delta = m - 2, j = m - 1; delta >= 0 && j > 0; delta --, j--) {
            int i = j - delta;
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
                if (v[x][y] != to) {
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


    // for (int i = 1; i <= n; i++) {
    //     for (int j = 1; j <= m; j++) {
    //         std::cout << v[i][j] << " \n"[j == m];
    //     }
    // }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (v[i][j] != to) {
                return {false, {}};
            }
        }
    }
    if (op.size() < 400) {
        return {true, op};
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
    bool ok = false;
    std::vector<std::string> op;
    std::unordered_map<std::string, int> mp;
    for (int id = 0; id <= 1; id++) {
        auto [ok1, op1] = cal(v, id);
        
        if (ok1) {
            ok = true;
            op = op1;
        } else {
            auto v1 = v;
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= m; j++) {
                    if (i == 1 || j == m) {
                        v1[i][j] ^= 1;
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
            auto [ok2, op2] = cal(v1, id);
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
            for (auto x : op) {
                std::cout << x << '\n';
            }
            return;
        }
    }

    std::cout << "NO\n";
}
signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);


    srand(428);
    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}