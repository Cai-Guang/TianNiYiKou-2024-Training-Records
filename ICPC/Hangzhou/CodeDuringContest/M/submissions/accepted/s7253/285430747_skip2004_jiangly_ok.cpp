#include<bits/stdc++.h>
using std::cin, std::cout;
using pr = std::pair<int, int>;
using u32 = unsigned;
using puu = std::pair<u32, u32>;
using ll = long long;
std::vector<std::tuple<u32, u32, u32>> P;
std::vector<pr> factor(int x) {
	std::vector<pr> o;
	if(x % 2 == 0) o.emplace_back(2, __builtin_ctz(x)), x >>= __builtin_ctz(x);
	for(auto [u, iu, lim] : P) {
		if(u * u > x) break;
		if(x * iu < lim) {
			int count = 0;
			do {
				count += 1;
				x *= iu;
			} while(x * iu < lim);
			o.emplace_back(u, count);
		}
	}
	if(x > 1) o.emplace_back(x, 1);
	return o;
}
const int N = 200005;

pr o[N];
int m;
int n, k, a[N], max[N];

void clear() {
	for(int i = 1;i <= n;++i) {
		a[i] = max[i] = 0;
	}
	m = 0;
}
void solve() {
	if(1) {
		cin >> n >> k;
		for(int i = 1;i <= n;++i) {
			cin >> a[i];
		}
	} else {
		static std::mt19937 gen;
		n = gen() % 10 + 1; k = gen() % 30 + 1;
		for(int i = 1;i <= n;++i) {
			a[i] = gen() % 50 + 1;
		}
	}
	if(0) {
		int s0 = 0, s1 = 0;
		for(int i = 1;i <= k;++i) {
			int ok = 1;
			for(int j = 1;j <= n;++j) {
				int gcd = 0, min = 2e9;
				for(int k = j;k <= n;++k) {
					gcd = std::gcd(gcd, a[k] + i);
					min = std::min(min, a[k] + i);
					ok = ok && min == gcd;
				}
			}
			if(ok) {
				s0 += 1;
				s1 += i;
			}
		}
		static std::ofstream fout("std.out");
		fout << s0 << ' ' << s1 << '\n';
	}
	std::vector<int> st;
	for(int i = 1;i <= n;++i) {
		for(;st.size() && st.back() >= a[i];) {
			st.pop_back();
		}
		if(st.size()) max[i] = std::max(max[i], st.back());
		st.push_back(a[i]);
	}
	st = {};
	for(int i = n;i >= 1;--i) {
		for(;st.size() && st.back() >= a[i];) {
			st.pop_back();
		}
		if(st.size()) max[i] = std::max(max[i], st.back());
		st.push_back(a[i]);
	}
	int fail = 0;
	for(int i = 1;i <= n;++i) if(max[i]) {
		int u = max[i], v = a[i];
		if(v - u >= u) o[m++] = pr(u, v - u);
		else fail = 1;
	}
	if(fail) {
		cout << 0 << ' ' << 0 << '\n';
		return ;
	}
	if(!m) {
		cout << k << ' ' << (ll) k * (k + 1) / 2 << '\n';
		return ;
	}
	pr z = o[--m];
	auto res = factor(z.second);
	ll ans0 = 0, ans1 = 0;
	auto dfs = [&](auto dfs, int idx, int s) {
		if(idx == (int) res.size()) {
			int num = s - z.first;
			if(1 <= num && num <= k) {
				int ok = 1;
				for(int i = 0;i < m;++i) {
					ok = ok && o[i].second % u32(o[i].first + num) == 0;
				}
				if(ok) {
					ans0 += 1;
					ans1 += num;
				}
			}
			return ;
		}
		for(int j = 0;j <= res[idx].second;++j, s *= res[idx].first) {
			dfs(dfs, idx + 1, s);
		}
	};
	dfs(dfs, 0, 1);
	cout << ans0 << ' ' << ans1 << '\n';
}
int main() {
	std::ios::sync_with_stdio(false), cin.tie(0);
	for(int i = 3;i <= 40000;++i) {
		int ok = 1;
		for(int j = 2;j * j <= i;++j) {
			if(i % j == 0) {
				ok = 0;
				break;
			}
		}
		if(ok) {
			u32 ii = 1;
			for(int j = 0;j < 5;++j) ii *= 2 - ii * i;
			assert(ii * i == 1u);
			P.emplace_back(i, ii, -1u / i);
		}
	}
	int t; cin >> t;
	for(int i = 0;i < t;++i) {
		solve();
		clear();
	}
}
