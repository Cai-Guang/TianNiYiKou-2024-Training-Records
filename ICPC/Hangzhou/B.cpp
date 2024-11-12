#include <bits/stdc++.h>

using namespace std;

#define int long long
#ifndef Cai_Guang
#define debug //
#define test //
#endif

struct Info {
	int val;
	int v;
	Info(int _val = 0, int _v = 0) : val(_val), v(_v) {
	}
};

struct Tag {
	int v = -1;
	Tag(int _v = -1) : v(_v) {}
};

Info operator+(const Info &a, const Info &b) {
	return {a.val & b.val, a.v | b.v | (~(a.val | b.val | a.v | b.v))};
}

struct SegmentTree {
	int n;
	
	std::vector<Info> info;
	std::vector<Tag> tag;	
	std::vector<int> len;
	
	void apply(int u, Tag &tag, Tag f) {
		Info &x = info[u];
		if (f.v != -1) {
			tag.v &= f.v;
			if (len[u] == 1) {
				x.val &= f.v;
				x.v = 0;
			} else {
				x = x + (Info(f.v, 0) + Info(f.v, 0));
			}
		}
	}
	
	void build(int u, int l, int r) {
		if (l == r) {
			len[u] = r - l + 1;
			return;
		}
		int mid = (l + r) >> 1;
		pushdown(u);
		build(u << 1, l, mid);
		build(u << 1 | 1, mid + 1, r);
		info[u] = info[u << 1] + info[u << 1 | 1];
	}
	
	SegmentTree(int _n = 0) : n(_n) {
		info.assign(_n << 2, {});
		tag.assign(_n << 2, {});
		len.assign(_n << 2, {});
		build(1, 1, n);
	};
	
	void pushdown(int u) {
		apply(u << 1, tag[u << 1], tag[u]);
		apply(u << 1 | 1, tag[u << 1 | 1], tag[u]);
		tag[u] = Tag();
	}
	
	void modify(int u, int L, int R, int p, Info v) {
		if (p < L || p > R) return;
		if (L == R && L == p) {
			info[u] = v;
			return;
		}
		pushdown(u);
		int mid = (L + R) >> 1;
		modify(u << 1, L, mid, p, v);
		modify(u << 1 | 1, mid + 1, R, p, v);
		info[u] = info[u << 1] + info[u << 1 | 1];
	}
	
	void modify(int u, int L, int R, int l, int r, Tag v) {
		if (r < L || l > R) return;
		if (l <= L && R <= r) {
			apply(u, tag[u], v);
			return;
		}
		int mid = (L + R) >> 1;
		pushdown(u);
		modify (u << 1, L, mid, l, r, v);
		modify(u << 1 | 1, mid + 1, R, l, r, v);
		info[u] = info[u << 1] + info[u << 1 | 1];
	}
	
	Info query(int u, int L, int R, int l, int r) {
		if (l > r || r < L) {
			return {};
		}
		if (l <= L && R <= r) {
			return info[u];
		}
		int mid = (L + R) >> 1;
		pushdown(u);
		if (l <= mid && r > mid) {
			return query(u << 1, L, mid, l, r) + query(u << 1 | 1, mid + 1, R, l, r);
		} else if (l <= mid) {
			return query(u << 1, L, mid, l, r);
		} else {
			return query(u << 1 | 1, mid + 1, R, l, r);
		}
	}
	
	void modify(int p, Info v) {
		modify(1, 1, n, p, v);
	}
	
	void modify(int l, int r, Tag v) {
		modify(1, 1, n, l, r, v);
	}
	
	Info query(int l, int r) {
		if (r < l) return Info(-1, 0);
		return query(1, 1, n, l, r);
	}
	
	bool check(int x, int p) {
		return ((info[x].val >> p & 1) == 0) && ((info[x].v >> p & 1) == 0);
	}
	
	int findpos(int u, int L, int R, int p) {
		if (L == R) {
			return L;
		}
		int mid = (L + R) >> 1;
		pushdown(u);
		if (check(u << 1, p)) {
			return findpos(u << 1, L, mid, p);
		}
		return findpos(u << 1 | 1, mid + 1, R, p);
	}
	
	int find(int u, int L, int R, int l, int r, int p) {
		if (l <= L && R <= r) {
			if (check(u, p)) {
				return findpos(u, L, R, p);
			} else {
				return 0;
			}
		}
		if (L == R) {
			return L;
		}
		int mid = (L + R) >> 1;
		pushdown(u);
		int ans = 0;
		if (mid >= l) {
			ans += find(u << 1, L, mid, l, r, p);
		}
		if (r > mid) {
			ans += find(u << 1 | 1, mid + 1, R, l, r, p);
		}
		return ans;
	}
};

void solve() {
	int n, q;
	std::cin >> n >> q;
	// tr.n = n;
	SegmentTree tr(n);
	
	for (int i = 1; i <= n; i++) {
		int x;
		std::cin >> x;
		tr.modify(i, Info(x, 0));
	}
	
	for (int i = 1; i <= q; i++) {
		int op;
		std::cin >> op;
		if (op == 1) {
			int l, r, x;
			std::cin >> l >> r >> x;
			tr.modify(l, r, Tag(x));
		} else if (op == 2) {
			int s, x;
			std::cin >> s >> x;
			tr.modify(s, Info(x, 0));
		} else {
			int l, r;
			std::cin >> l >> r;
			if (l == r) {
				std::cout << 0 << '\n';
				continue;
			}
			Info ret = tr.query(l, r);
			int pos = -1;
			for (int j = 63; j >= 0; j--) {
				if (!(ret.val >> j & 1) && !(ret.v >> j & 1)) {
					pos = j;
					break;
				}
			} 
			if (pos == -1) {
				std::cout << ret.val << '\n';
			} else {
				int p = tr.find(1, 1, n, l, r, pos);
				int ls = tr.query(l, p - 1).val;
				int rs = tr.query(p + 1, r).val;
				std::cout << (ls & rs) << '\n';
			}
		}
	}
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