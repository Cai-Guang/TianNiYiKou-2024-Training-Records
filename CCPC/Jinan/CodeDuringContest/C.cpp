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

void solve() {

}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int t = 1;
    std::cin >> t;
    while (t--) {
        solve();
    }
}