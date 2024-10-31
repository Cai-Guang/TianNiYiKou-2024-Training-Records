#include <bits/stdc++.h>

int idx = 2, up = 0, up0 = 0, up1 = 0;
std::map<int, int> mp, mp0, mp1;
int S = 1, T = 2;
std::vector<int> Pow2, Log2, L, R;

std::vector<std::array<int, 3>> edges;
std::vector<std::vector<std::array<int, 2>>> G(101);

void addedge(int x, int y, int z) {
	G[x].push_back({y, z});
}

int base(int x) {
	while (!mp.count(x)) {
		mp[up] = ++idx;
		addedge(mp[up], mp[up - 1], 0);
		addedge(mp[up], mp[up - 1], 1);
		up ++;
	}
	return mp[x];
}

void init() {
	Pow2.assign(1e6 + 10, 0);
	Log2.assign(1e6 + 10, 0);
	L.assign(1e6 + 10, 0);
	R.assign(1e6 + 10, 0);
	mp[-1] = T;
	int base2 = 1;
	for (int i = 1; i <= 20; i++) {
		Pow2[base2 - 1] = 1;
		base2 *= 2;
	}
	Log2[0] = -1;
	for (int i = 1; i <= 1e6; i++) {
		Log2[i] = Log2[i / 2] + 1;
	}
}

std::map<int, int> have;
void dfs(int x, int pre) {
	for (auto [y, z] : G[x]) {
		dfs(y, pre * 2 + z);
	}
	if (!G[x].size()) {
		have[pre] ++;
	}
}
bool Test = false;
void cal(int L, int R, int fa, int bit) {
	if (Test) {
		std::cout << "Cal " << L << ' ' << R << ' ' << bit << std::endl;
		std::cout << std::bitset<20>(L) << std::endl;
		std::cout << std::bitset<20>(R) << std::endl;
	}
	if (R < L) return;
	std::vector<int> v;
	int l = L;
	if (L == 0) {
		v.push_back(0);
	}
	while (L) {
		v.push_back(L & 1);
		L /= 2;
	}
	L = l;
	if (L == R) {
		for (int i = bit + (L == 0); i > v.size(); i--) {
			addedge(fa, ++idx, 0);
			fa = idx;
		}
		for (int i = v.size() - 1; i >= 1; i--) {
			addedge(fa, ++idx, v[i]);
			fa = idx;
		}	
		addedge(fa, T, v[0]);
		return;
	}
	if (L == 0 && Pow2[R]) {
		// std::cout << bit << ' ' << Log2[R] << '\n';
		for (int i = bit; i >= Log2[R] + 1; i--) {
			addedge(fa, ++idx, 0);
			fa = idx;
		}
		addedge(fa, base(Log2[R] - 1), 0); 
		addedge(fa, base(Log2[R] - 1), 1); 
		return;
	}
	if (L * 2 - 1 == R && Pow2[R]) {
		// for (int i = bit + (L == 0); i >= base(Log2[R] - 1); i--) {
			
		for (int i = bit; i >= Log2[R] + 1; i--) {
			addedge(fa, ++idx, 0);
			fa = idx;
		}
		addedge(fa, base(Log2[R] - 1), 1); 
		return;
	}
	int i = bit;
	if ((L >> i & 1) && !(R >> i & 1)) {
		addedge(fa, ++idx, 1); 
		cal(L - (1ll << i), (L - (1ll << i)) | ((1ll << i) - 1), idx, bit);
		if (fa != S) {
			addedge(fa, ++idx, 0); 
			cal(R & (1ll << i), R, idx, bit - 1);
		} else {
			cal(R & (1ll << i), R, fa, bit - 1);
		}
	} else if (!(L >> i & 1) && (R >> i & 1)) {
		if (fa != S) {
			addedge(fa, ++idx, 0); 
			cal(L, (1ll << i) - 1, idx, bit - 1);
		} else {
			cal(L, (1ll << i) - 1, fa, bit - 1);
		}
		addedge(fa, ++idx, 1);
		cal(0, R - (1ll << i), idx, bit - 1);
	} else if ((L >> i & 1) && (R >> i & 1)) {
		addedge(fa, ++idx, 1);
		cal(L - (1ll << i), R - (1ll << i), idx, bit - 1);
	} else {
		if (fa != S) {
			addedge(fa, ++idx, 0); 
			cal(L, R, idx, bit - 1);
		} else {
			cal(L, R, fa, bit - 1);
		}
	}
}

void solve(int l, int r) {
	int lst = l;
	for (int i = l; i <= r; i++) {
		if (Pow2[i]) {
			if (Test) {
				// std::cout << lst << ' ' << i << '\n';
				// std::cout << std::bitset<20>(lst) << std::endl;
				// std::cout << std::bitset<20>(i) << std::endl;
			}
			cal(lst, i, S, Log2[i]);
			lst = i + 1;
		}
	}
	if (Test) {
		// std::cout << lst << ' ' << r << '\n';
		// std::cout << std::bitset<20>(lst) << std::endl;
		// std::cout << std::bitset<20>(r) << std::endl;
	}
	cal(lst, r, S, Log2[r]);
}

int main() {
	int l, r;
	std::cin >> l >> r;
	init();

	// Test = true;
	solve(l, r);

	std::cout << idx << '\n';
	for (int i = 1; i <= idx; i++) {
		std::cout << G[i].size() << ' ';
		for (auto [x, y] : G[i]) {
			std::cout << x << ' ' << y << ' ';
		} std::cout << '\n';
	}
	
	auto check = [&]() {
		if (idx > 100) {
			std::cout << "Too much point " << idx << std::endl;
		}

		dfs(1, 0);

		std::vector<int> ind(idx + 1), outd(idx + 1);

		for (int i = 1; i <= idx; i++) {
			for (auto [x, y] : G[i]) {
				outd[i] ++;
				ind[x] ++;
			}
		}

		for (int i = 1; i <= idx; i++) {
			if (!ind[i] && i != 1) {
				std::cout << "Duplicated Inpoint " << i << std::endl;
				return;
			}
		}

		for (int i = 1; i <= idx; i++) {
			if (!outd[i] && i != 2) {
				std::cout << "Duplicated Outpoint " << i << std::endl;
				return;
			}
		}

		if (Test) {
			for (auto [x, y] : have) {
				std::cout << x << ' ' << y << '\n';
			}
		}

		for (auto [x, y] : have) {
			if (y != 1) {
				std::cout << "Duplicated of " << x << std::endl;
				return;
			}
		}

		for (int i = l; i <= r; i++) {
			if (!have.count(i)) {
				std::cout << "Lack of " << i << std::endl;
				std::cout << std::bitset<20>(i) << std::endl;
				return;
			}
			have.erase(i);
		}

		if (have.size()) {
			std::cout << "Out of bound" << std::endl;

			for (auto [x, y] : have) {
				std::cout << x << ' ' << y << '\n';
				std::cout << std::bitset<20>(x) << std::endl;
			}
			return;
		}

		// std::cout << "AC" << std::endl; 
	};
	check();

	return 0;
} 