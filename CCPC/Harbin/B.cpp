#include <bits/stdc++.h>

#define int long long
using i64 = long long;

template<typename T>
struct Point {
	T x, y;
	Point() {}
	Point(T x, T y) : x(x), y(y) {}
	friend Point operator + (Point a, Point b) {
		return Point(a.x + b.x, a.y + b.y);
	}
	friend Point operator - (Point a, Point b) {
		return Point(a.x - b.x, a.y - b.y);
	}
	friend T operator * (Point a, Point b) {
		return a.x * b.x + a.y + b.y;
	}
	friend T operator ^ (Point a, Point b) {
		return a.x * b.y - a.y * b.x;
	}
	friend Point operator * (T a, Point b) {
		return Point(b.x * a, b.y * a);
	}
	friend Point operator * (Point b, T a) {
		return Point(b.x * a, b.y * a);
	}
	friend Point operator / (Point a, T b) {
		return Point(a.x / b, a.y / b);
	}
	friend bool operator < (Point a, Point b) {
		if (a.x == b.x) return a.y < b.y;
		return a.x < b.x;
	}
	friend bool operator > (Point a, Point b) {
		if (a.x == b.x) return a.y > b.y;
		return a.x > b.x;
	}
	friend bool operator == (Point a, Point b) {
		return a.x == b.x && a.y == b.y;
	}
	friend bool operator != (Point a, Point b) {
		return a.x != b.x || a.y != b.y;
	}
};

template<typename T>
T cross(Point<T> x, Point<T> a, Point<T> b) {
	return (a - x) ^ (b - x);
}

template<typename T>
T dis(Point<T> a, Point<T> b) {
	return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

template<typename T>
std::vector<Point<T>> convexHull(std::vector<Point<T>> ps) {
	if (ps.size() < 3) return ps;
	std::sort(ps.begin(), ps.end(), [&](Point<T> a, Point<T> b) {
		if (a.x != b.x) return a.x < b.x;
		return a.y < b.y;
	});
	int sz = ps.size();
	std::vector<Point<T>> convex(sz + 100), convex_hull;
	int top = 0;
	for (int i = 0; i < sz; i++) {
		auto x = ps[i];
		while (top >= 2 && cross(convex[top - 1], convex[top], x) < 0) {
			top --;
		}
		top ++;
		convex[top] = x;
	}
	for (int i = sz - 2; i >= 0; i--) {
		auto x = ps[i];
		while (top >= 2 && cross(convex[top - 1], convex[top], x) < 0) {
			top --;
		}
		top ++;
		convex[top] = x;
	}

	for (int i = 1; i < top; i++) {
		convex_hull.push_back(convex[i]);
	}

	return convex_hull;
}

int getS(std::vector<Point<int>> ps) {
	int ans = 0;
	if (ps.size() < 3) return 0;
	for (int i = 1; i + 1 < ps.size(); i++) {
		ans += std::abs(cross(ps[0], ps[i], ps[i + 1]));
	}
	return ans;
}

void solve() {
	int n;
	std::cin >> n;

	std::vector<Point<int>> ps;
	for (int i = 0; i < n; i++) {
		int x, y;
		std::cin >> x >> y;
		ps.push_back({x, y});
	}

	auto outside_convex_hull = convexHull(ps);

	int ans = getS(outside_convex_hull);
	if (outside_convex_hull.size() == n) {
		std::cout << -1 << '\n';
		return;
	}

	std::map<Point<int>, int> mp;

	for (auto x : outside_convex_hull) {
		mp[x] ++;
	}

	std::vector<Point<int>> inside_ps;
	for (auto x : ps) {
		if (!mp.count(x)) {
			inside_ps.push_back(x);
		}
	}

	auto inside_convex_hull = convexHull(inside_ps);

	int now = 0;
	int L = 0, R = 0;

	std::pair<int, int> mi = {(int)1e18, 0};
	for (int i = 0; i < outside_convex_hull.size(); i++) {
		mi = std::min(mi, {dis(outside_convex_hull[i], inside_convex_hull[now]), i});
	}

	L = R = mi.second;

	auto out_pre = [&](int x) {
		x --;
		if (x < 0) {
			x += outside_convex_hull.size();
		}
		return x;
	};

	auto out_nxt = [&](int x) {
		x ++;
		if (x >= outside_convex_hull.size()) {
			x -= outside_convex_hull.size();
		}
		return x;
	};

	auto in_pre = [&](int x) {
		x --;
		if (x < 0) {
			x += inside_convex_hull.size();
		}
		return x;
	};

	auto in_nxt = [&](int x) {
		x ++;
		if (x >= inside_convex_hull.size()) {
			x -= inside_convex_hull.size();
		}
		return x;
	};

	auto getDis = [&](int out, int in) {
		return dis(inside_convex_hull[in], outside_convex_hull[out]);
	};

	int Mi = 9e18;

	auto getPreS = [&](int x, int y) {
		return std::abs(cross(inside_convex_hull[y], outside_convex_hull[x], outside_convex_hull[out_pre(x)]));
	};
	
	auto getNxtS = [&](int x, int y) {
		return std::abs(cross(inside_convex_hull[y], outside_convex_hull[x], outside_convex_hull[out_nxt(x)]));
	};
	
	if (inside_convex_hull.size() <= 10) {
		for (int j = 0; j < inside_convex_hull.size(); j++) {
			for (int i = 0; i < outside_convex_hull.size(); i++) {
				Mi = std::min(Mi, getPreS(i, j));
			}
		}
		std::cout << ans - Mi << '\n';
		return;
	}
	
	auto getPreMin = [&](int in, int out, int is = 0) {
		int S = getPreS(out, in);
		if (is) {
			if (Mi == S) {
				std::cout << inside_convex_hull[in].x << ' ' << inside_convex_hull[in].y << '\n';
				std::cout << outside_convex_hull[out].x << ' ' << outside_convex_hull[out].y << '\n';
				std::cout << outside_convex_hull[out_pre(out)].x << ' ' << outside_convex_hull[out_pre(out)].y << '\n';
				exit(0);
			}
		}
		Mi = std::min(Mi, S);
	};
	
	auto getNxtMin = [&](int in, int out, int is = 0) {
		int S = getNxtS(out, in);
		if (is) {
			if (Mi == S) {
				std::cout << inside_convex_hull[in].x << ' ' << inside_convex_hull[in].y << '\n';
				std::cout << outside_convex_hull[out].x << ' ' << outside_convex_hull[out].y << '\n';
				std::cout << outside_convex_hull[out_nxt(out)].x << ' ' << outside_convex_hull[out_nxt(out)].y << '\n';
				exit(0);
			}
		}
		Mi = std::min(Mi, S);
	};
	
 	for (int i = 0; i < outside_convex_hull.size() * 2; i++) {
 		while (getPreS(L, now) >= getPreS(L, in_pre(now))) {
 			// std::cout << L << ' ' << now << '\n';
 			getPreMin(now, L);
 			getNxtMin(now, L);
 			now = in_pre(now);
 		}
 		// std::cout << L << ' ' << now << "!!!\n";
		getPreMin(now, L);
		getNxtMin(now, L);
 		L = out_pre(L);
 	}
	std::cout << ans - Mi << '\n';
 	
 	// std::cout << 
 	// for (int i = 0; i < outside_convex_hull.size() * 2; i++) {
 		// while (getPreS(L, now) >= getPreS(L, in_pre(now))) {
 			// // std::cout << L << ' ' << now << '\n';
 			// getPreMin(now, L, 1);
 			// getNxtMin(now, L, 1);
 			// now = in_pre(now);
 		// }
 		// std::cout << L << ' ' << now << "!!!\n";
		// getPreMin(now, L, 1);
		// getNxtMin(now, L, 1);
 		// L = out_pre(L);
 	// }
}

signed main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
 
	int t = 1;
	std::cin >> t;

	while (t --) {
		solve();
	}
}