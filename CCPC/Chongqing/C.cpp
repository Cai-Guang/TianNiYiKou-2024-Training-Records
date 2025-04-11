#include <bits/stdc++.h>

using namespace std;

#define int long long
#ifndef Cai_Guang
#define debug //
#define test //
#endif

void solve() {
	int n;
	std::cin >> n;
	
	std::string s, t;
	std::cin >> s >> t;
	
	s = ' ' + s;
	t = ' ' + t;
	
	int cnts = 0, cntt = 0;
	for (int i = 1; i <= n; i++) {
		cnts += s[i] == '#';
	}
	for (int i = 1; i <= n; i++) {
		cntt += t[i] == '#';
	}
	
	if (cnts == n && cntt == n) {
		std::cout << "Yes\n";
		for (int i = 1; i <= 7; i++) {
			std::cout << std::string(n, '#') << '\n';
		}
		return;
	} else if ((cnts == n && cntt != 0) || (cnts != 0 && cntt == n)) {
		std::cout << "No\n";
		return;
	}
	
	std::vector G(10, std::vector<int>(n + 3));
	
	for (int i = 1; i <= n; i++) {
		if (s[i] == '#') {
			G[1][i] = 1;
		} 
		if (t[i] == '#') {
			G[7][i] = 1;
		}
	}

	if (cnts != 0) {
		for (int i = 1; i <= n; i++) {
			if (G[1][i] == 0) {
				G[2][i] = 1;
			}
		}
	}
	if (cntt != 0) {
		for (int i = 1; i <= n; i++) {
			if (G[7][i] == 0) {
				G[6][i] = 1;
			}
		}
	}
	if (cnts == 0 || cntt == 0) {
		std::cout << "Yes\n";
		for (int i = 1; i <= 7; i++) {
			for (int j = 1; j <= n; j++) {
				std::cout << (G[i][j] ? "#" : ".");
			} std::cout << '\n';
		}
		return;
	}
	
	std::vector<int> v;
	
	for (int i = 1; i <= n; i++) {
		if (G[2][i] == 1) {
			int l = i - 1, r = i;
			for (int j = i; j <= n + 1; j++) {
				if (!G[2][j]) {
					r = j;
					break;
				}
			}
			if (l != 0)
				G[3][l] = 1, v.push_back(l);
			else if (r != n + 1)
				G[3][r] = 1, v.push_back(r);
			break;
		}
	}
	for (int i = 1; i <= n; i++) {
		if (G[6][i] == 1) {
			int l = i - 1, r = i;
			for (int j = i; j <= n + 1; j++) {
				if (!G[6][j]) {
					r = j;
					break;
				}
			}
			if (l != 0)
				G[5][l] = 1, v.push_back(l);
			else if (r != n + 1)
				G[5][r] = 1, v.push_back(r);
			break;
		}
	}
	
	for (int i = 1; i <= n; i++) {
		if (G[3][i] && G[5][i]) {
			G[4][i + 1] = 1;
			goto G;
		}
	}
	
	for (int i = 1; i <= n; i++) {
		if (G[3][i + 1] && G[5][i]) {
			G[4][i] = 1;
			goto G;
		}
	}
	for (int i = 1; i <= n; i++) {
		if (G[3][i - 1] && G[5][i]) {
			G[4][i] = 1;
			goto G;
		}
	}
	
	std::sort(v.begin(), v.end());
	
	for (int i = v[0] + 1; i <= v[1] - 1; i++) {
		G[4][i] = 1;
	}
	
	G:;
	
	std::cout << "Yes\n";
	for (int i = 1; i <= 7; i++) {
		for (int j = 1; j <= n; j++) {
			std::cout << (G[i][j] ? "#" : ".");
		} std::cout << '\n';
	}
	// cout << '\n';
	
	
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