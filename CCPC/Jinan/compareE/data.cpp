#include <bits/stdc++.h>

using namespace std;

#define int long long

std::mt19937_64 mrand(time(NULL));

int rnd(int l, int r) {
	return mrand() % (r - l + 1) + l;
}

void solve() {
    std::cout << rnd(1, 100) << " ";
    std::cout << rnd(1, 100) << " ";
    std::cout << rnd(1, 100) << " ";
    std::cout << rnd(1, 100) << " ";
    std::cout << rnd(1, 100) << " ";
    std::cout << rnd(1, 10000) << "\n";
}



signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int t = 1;
    std::cout << t << "\n"; 
//    std::cin >> t;
    while (t--) {
        solve();
    }
}
