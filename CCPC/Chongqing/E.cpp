#include <bits/stdc++.h>

using namespace std;

#define int long long
#ifndef Cai_Guang
#define debug //
#define test //
#endif

void solve() {
	int n, m;
	std::cin >> n >> m;
	
	std::vector<int> a(n + 1), d(n + 1);
	
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}
	
	for (int i = 1; i <= m; i++) {
		int u, v;
		std::cin >> u >> v;
		d[u] ++;
		d[v] ++;
	}
	
	int ans = 0;
	
	if (n == 1) {
		std::cout << a[1] << '\n';
		return;
	}
	
	std::vector<int> v;
	for (int i = 1; i <= n; i++) {
		if (d[i] > 1) {
			ans = std::max(ans, a[i]);
		} else if (d[i] == 1) {
			v.push_back(a[i]);
		}
	}
	std::sort(v.begin(), v.end(), std::greater<int>());
	
	if (v.size() >= 2) {
		ans = std::max(ans, v[1]);
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
	// std::cin >> t;
	while(t--) {
	    solve();
	}
}