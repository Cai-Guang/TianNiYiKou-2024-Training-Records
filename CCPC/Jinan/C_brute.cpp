#include <bits/stdc++.h>

using namespace std;

#define int long long

void test() {
    std::cerr << "\n";
}
template<typename T, typename... Args>
void test(T x, Args... args) {
    std::cerr << x << " ";
    test(args...);
}

using i64 = long long;

void type1(int a, int x, int b, int y) {
    std::cout << "POP " << a << " GOTO " << x << "; PUSH " << b << " GOTO " << y << "\n";
}

void type2(int b, int y) {
    std::cout << "HALT; PUSH " << b << " GOTO " << y << "\n";
}


signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int n = 3;
    std::vector<std::array<int, 4>> a(n + 1);
    std::map<int, std::vector<std::array<int, 4>>> ans;
    auto dfs = [&](auto self, int p)->void{
        if (p == n + 1) {
            int cnt = 0;
            int now = 1;
            std::vector<int> stk;

            while (cnt < 20) {
                cnt++;
                if (stk.size() == 0 && a[now][0] == 0) {
                    break;
                }
                if (stk.size() && stk.back() == a[now][1]) {
                    now = a[now][1];
                    stk.pop_back();
                } else {
                    stk.push_back(a[now][2]);
                    now = a[now][3];
                }
            }
            ans[cnt] = a;
            return;
        }



        for (int c3 = 1; c3 <= 3; c3++) {
            for (int c4 = 1; c4 <= 3; c4++) {
                for (int c1 = 0; c1 <= 3; c1++) {
                    if (c1 == 0) {
                        a[p] = {c1, 0, c3, c4};
                        self(self, p + 1);
                    } else {
                        for (int c2 = 1; c2 <= 3; c2++) {
                            a[p] = {c1, c2, c3, c4};
                            self(self, p + 1);
                        }
                    }
                }

            }
        }

    };
    dfs(dfs, 1);

    for (auto [x, q] : ans) {

        std::cerr << x << "\n";
        for (auto vec : q) {
            for (auto v : vec) {
                std::cerr << v << " ";
            }
            std::cerr << "\n";
        }
    }
}