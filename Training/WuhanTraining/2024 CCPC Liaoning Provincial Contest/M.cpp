#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve() {
    int n, k, t, m;
    std::cin >> n >> m >> k >> t;

    std::vector<int> c(k + 1000);
    for (int i = 1; i <= k; i++) {
        std::cin >> c[i];
    }

    std::vector<std::vector<int>> G(10, std::vector<int>(10, -1));
    std::vector<std::vector<int>> ID(10, std::vector<int>(10, -1));

    ID[1][1] = 2; ID[1][2] = 3; ID[1][3] = 4;
    ID[2][1] = 5; ID[2][2] = 1; ID[2][3] = 6;
    ID[3][1] = 7; ID[3][2] = 8; ID[3][3] = 9; 

    std::vector<std::pair<int, int>> d{{0, 0}, {2, 2}, {1, 1}, {1, 2}, {1, 3}, {2, 1}, {2, 3}, {3, 1}, {3, 2}, {3, 3}};

    int myy_have = n, used = 0;

    std::vector<int> have(m + 1);

    while (true) {
        bool op = false;
        // for (int i = 0; i <= m; i++) {
        //     std::cout << have[i] << " \n"[i == m];
        // }
        // for (int i = 1; i <= 3; i++) {
        //     for (int j = 1; j <= 3; j++) {
        //         std::cout << G[i][j] << " \n"[j == 3];
        //     }
        // }
        
        // op1
        for (int i = 1; i <= 9; i++) {
            auto [x, y] = d[i];
            if (used < myy_have and used < k and G[x][y] == -1) {
                used ++;
                G[x][y] = c[used];
                op = true;
                if (c[used] == t) {
                    myy_have ++;
                }
                if (c[used] == 0) {
                    G[x][y] = -1;
                    have[0] ++;
                    myy_have ++;
                    goto G;
                }
            }
        }

        // op2
        {
            std::set<int> s;
            for (int i = 1; i <= 9; i++) {
                auto [x, y] = d[i];
                if (G[x][y] != -1) {
                    s.insert(G[x][y]);
                }
            }

            if (s.size() == 9) {
                op = true;
                have[G[2][2]] ++;
                G[2][2] = -1;
                goto G;
            }
        }

        // op3
        {
            bool used_sp = false;
            {
                std::set<std::set<int>> yes; 
                {
                    for (int i = 1; i <= 3; i++) {
                        std::set<int> s;
                        for (int j = 1; j <= 3; j++) {
                            s.insert(ID[i][j]);
                            if (G[i][j] != G[i][1] or G[i][j] == -1) {
                                goto NO1;
                            }
                        }
                        yes.insert(s);
                        NO1:;
                    }
                }
                {
                    for (int i = 1; i <= 3; i++) {
                        std::set<int> s;
                        for (int j = 1; j <= 3; j++) {
                            s.insert(ID[j][i]);
                            if (G[j][i] != G[1][i] or G[j][i] == -1) {
                                goto NO2;
                            }
                        }
                        yes.insert(s);
                        NO2:;
                    }
                }
                {
                    std::set<int> s;
                    for (int i = 1; i <= 3; i++) {
                        s.insert(ID[i][i]);
                        if (G[i][i] != G[1][1] or G[i][i] == -1) {
                            goto NO3;
                        }
                    }
                    yes.insert(s);
                    NO3:;
                }
                {
                    std::set<int> s;
                    for (int i = 1; i <= 3; i++) {
                        s.insert(ID[3 - i + 1][i]);
            
                        if (G[3 - i + 1][i] != G[3][1] or G[3 - i + 1][i] == -1) {
                            goto NO4;
                        }
                    }
                    yes.insert(s);
                    NO4:;
                }
                if (yes.size()) {
                    op = true;
                    for (auto ids : yes) {
                        bool ok = true;
                        for (auto x : ids) {
                            auto [X, Y] = d[x];
                            if (G[X][Y] == -1) {
                                ok = false;
                            }
                        }
                        if (ok) {
                            myy_have += 5;
                            for (auto x : ids) {
                                auto [X, Y] = d[x];
                                if (x == 1) {
                                    used_sp = true;
                                    continue;
                                }
                                have[G[X][Y]] ++;
                                G[X][Y] = -1;
                            }
                        }
                    }
                }
            }

            for (int i = 1; i <= 9; i++) {
                for (int j = 1; j <= 9; j++) {
                    auto [X1, Y1] = d[i];
                    auto [X2, Y2] = d[j];
                    if (i != j and G[X1][Y1] == G[X2][Y2] and G[X1][Y1] != -1) {
                        if (i != 1) {
                            have[G[X1][Y1]] ++;
                            G[X1][Y1] = -1;
                        } else {
                            used_sp = true;
                        }
                        if (j != 1) {
                            have[G[X2][Y2]] ++;
                            G[X2][Y2] = -1;
                        } else {
                            used_sp = true;
                        }
                        myy_have ++;
                        op = true;
                    } 
                }
            }

            if (used_sp) {
                have[G[2][2]] ++;
                G[2][2] = -1;
                op = true;
            }
        }

        if (!op) {
            for (int i = 1; i <= 9; i++) {
                auto [x, y] = d[i];
                if (G[x][y] != -1) {
                    have[G[x][y]] ++;
                    G[x][y] = -1;
                }
            }
            break;
        } else {
            bool ok = true;
            for (int i = 1; i <= 9; i++) {
                auto [x, y] = d[i];
                if (G[x][y] != -1) {
                    ok = false;
                }
            }
            if (ok) {
                myy_have += 10;
            }
        }

        G:;
    }

    for (int i = 0; i <= m; i++) {
        std::cout << have[i] << " \n"[i == m];
    }

    // std::cout << myy_have << ' ' << used << '\n';

    if (myy_have > k) {
        std::cout << "Unhappy! " << myy_have - k << '\n';
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