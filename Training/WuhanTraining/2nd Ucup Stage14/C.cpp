#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")

#include <bits/stdc++.h>

using namespace std;

#define int long long

int cmp(double x) {
    if (fabs(x) < 1e-8) return 0;
    return x < 0 ? -1 : 1;
}

struct point {
    double x, y;
    double dist(const point &p) const {
        return (x - p.x) * (x - p.x) + (y - p.y) * (y - p.y);
    }

    friend bool operator < (const point& p1, const point &p2) {
        if (p1.x == p2.x) {
            return p1.y < p2.y;
        }
        return p1.x < p2.y;
    }
    friend bool operator > (const point& p1, const point &p2) {
        if (p1.x == p2.x) {
            return p1.y > p2.y;
        }
        return p1.x > p2.y;
    }

    friend point operator-(const point &p1, const point &p2) {
        return {p1.x - p2.x, p1.y - p2.y};
    }
};

void circle_center(point& p0, point& p1, point& p2, point &c) {
    double a1 = p1.x - p0.x;
    double b1 = p1.y - p0.y;
    double c1 = (a1 * a1 + b1 * b1) / 2;
    double a2 = p2.x - p0.x;
    double b2 = p2.y - p0.y;
    double c2 = (a2 * a2 + b2 * b2) / 2;
    double det = a1 * b2 - a2 * b1;

    c.x = p0.x + (c1 * b2 - c2 * b1) / det;
    c.y = p0.y + (a1 * c2 - a2 * c1) / det;
}

void circle_center(point& p0, point& p1, point &c) {
    c.x = (p0.x + p1.x) / 2;
    c.y = (p0.y + p1.y) / 2;
}

point center0, center1, delta, center;
double radius;

bool point_in(const point &p) {
    return cmp((p).dist(center) - radius) < 0;
}

void min_circle_cover(std::vector<point> &p, int n) {
    radius = 0;
    center = p[1];
    if (n == 1) {
        return;
    }
    if (n == 2) {
        circle_center(p[1], p[2], center);
        radius = p[2].dist(center);
        return;
    }
    for (int i = 2; i <= n; i++) {
        if (!point_in(p[i])) {
            center = p[i];
            radius = 0;
            for (int j = 1; j < i; j++) {
                if (!point_in(p[j])) {
                    circle_center(p[i], p[j], center);
                    radius = p[j].dist(center);
                    for (int k = 1; k < j; k++) {
                        if (!point_in(p[k])) {
                            circle_center(p[i], p[j], p[k], center);
                            radius = p[k].dist(center);
                        }
                    }
                }
            }
       }
    }
}

void solve() {
    int n;
    std::cin >> n;

    std::vector<point> p0(n + 1);
    for (int i = 1; i <= n; i++) {
        int x, y;
        std::cin >> x >> y;
        p0[i] = {(double)x, (double)y};
        // std::cin >> p0[i].x >> p0[i].y;
    }
    int m;
    std::cin >> m;

    std::vector<point> p1(m + 1);
    for (int i = 1; i <= m; i++) {
        int x, y;
        std::cin >> x >> y;
        p1[i] = {(double)x, (double)y};
    }
    std::vector<point> p2(1, {0, 0});

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            p2.push_back(p0[i] - p1[j]);
        }
    }

    // shuffle(p2.begin() + 1, p2.end(), std::mt19937(std::chrono::steady_clock::now().time_since_epoch().count()));
    srand(time(0));
    random_shuffle(p2.begin() + 1, p2.end());

    min_circle_cover(p2, n * m);

    std::cout << std::fixed << std::setprecision(10) << sqrt(radius) << ' ' << -center.x << ' ' << -center.y << ' ';

    // for (int i = 1; i <= n; i++) {
    //     p0[i] = p0[i] - center;
    // }

    // double ans = 1e18;

    // for (int i = 1; i <= n; i++) {
    //     for (int j = 1; j <= m; j++) {
    //         ans = std::max(p0[i].dist(p1[j]), ans);
    //     }
    // }

    // std::cout << radius << '\n';
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    // std::cin >> t;

    while (t --) {
        solve();
    }
} 