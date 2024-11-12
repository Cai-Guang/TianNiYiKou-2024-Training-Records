#include <bits/stdc++.h>

using namespace std;

#define int long long
#ifndef Cai_Guang
#define debug //
#define test //
#endif

void solve() {
	system("g++ std.cpp -o std.exe");
	system("g++ my.cpp -o my.exe");
	system("g++ data.cpp -o data.exe");
}

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

#ifdef Cai_Guang
//freopen("1.in", "r", stdin);
localTest = true;
#endif
   
	int t = 1;
	// std::cin >> t;
	while(t--) {
	    solve();
	}
}