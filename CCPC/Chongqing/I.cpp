#include <bits/stdc++.h>

using namespace std;

#define int long long
#ifndef Cai_Guang
#define debug //
#define test //
#endif

const int MOD = 998244353;

void solve() {
	std::vector<int> a(11);
	for (int i = 1; i <= 9; i++) {
		std::cin >> a[i];
	}
	
	int ans = 1;
	
	int x = std::min(a[1], a[2]);
	a[1] -= x;
	a[2] -= x;
	a[3] += x;
	
	if (a[1]) {
		int y = a[1] / 3;
		a[3] += y;
		a[1] -= y * 3;
		
		if (a[1] == 1) {
			for (int i = 2; i <= 9; i++) {
				if (a[i]) {
					a[i + 1] ++;
					a[i] --;
					a[1] --;
					break;
				}
			}
		} else if (a[1] == 2) {
			a[2] ++;
			a[1] -= 2;
		}
	}

	for (int i = 1; i <= 10; i++) {
		// std::cout << a[i] << " \n"[i == 10];
		for (int j = 1; j <= a[i]; j++) {
			ans *= i;
			ans %= MOD;
		}
	}
	
	std::cout << ans << '\n';
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
	std::cin >> t;
	while(t--) {
	    solve();
	}
}