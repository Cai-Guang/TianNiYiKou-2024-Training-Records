#include <bits/stdc++.h>

using namespace std;

#define int long long
#ifndef Cai_Guang
#define debug //
#define test //
#endif

void solve() {
	int n;
	std::string s, t;
	std::cin >> n >> s >> t;
	
	for (int i = 0; i < n; i++) {
		if (s[i] == '1' || t[i] == '1') {
			continue;
		} else {
			std::cout << 0 << '\n';
			return;
		}
	}
	
	std::cout << 1 << '\n';
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