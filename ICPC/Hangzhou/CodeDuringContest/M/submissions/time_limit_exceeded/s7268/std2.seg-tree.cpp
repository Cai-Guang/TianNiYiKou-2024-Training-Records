#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2")

#include <bits/stdc++.h>
#define MAXN ((int) 5e4)
#define MAXP 16
#define INF ((int) 2e9)
using namespace std;

int n, K, A[MAXN + 10];

int treeG[MAXN * 4 + 10], treeM[MAXN * 4 + 10];

void build(int id, int l, int r) {
    if (l == r) {
        treeG[id] = abs(A[l] - A[l + 1]);
        treeM[id] = l;
    } else {
        int nxt = id << 1, mid = (l + r) >> 1;
        build(nxt, l, mid); build(nxt | 1, mid + 1, r);
        treeG[id] = gcd(treeG[nxt], treeG[nxt | 1]);
        treeM[id] = (A[treeM[nxt]] <= A[treeM[nxt | 1]] ? treeM[nxt] : treeM[nxt | 1]);
    }
}

int queryG(int id, int l, int r, int ql, int qr) {
    if (ql <= l && r <= qr) return treeG[id];
    int nxt = id << 1, mid = (l + r) >> 1;
    return gcd(
        ql <= mid ? queryG(nxt, l, mid, ql, qr) : 0,
        qr > mid ? queryG(nxt | 1, mid + 1, r, ql, qr) : 0
    );
}

int queryM(int id, int l, int r, int ql, int qr) {
    if (ql <= l && r <= qr) return treeM[id];
    int nxt = id << 1, mid = (l + r) >> 1;
    int idxL = -1, mnL = 2e9;
    if (ql <= mid) idxL = queryM(nxt, l, mid, ql, qr), mnL = A[idxL];
    int idxR = -1, mnR = 2e9;
    if (qr > mid) idxR = queryM(nxt | 1, mid + 1, r, ql, qr), mnR = A[idxR];
    return mnL <= mnR ? idxL : idxR;
}

bool gao(int l, int r, int det) {
    int g = 0;
    if (l < r) g = queryG(1, 1, n, l, r - 1);
    if (g == 0) return true;

    int idx = queryM(1, 1, n, l, r);
    int mn = A[idx];
    if (g % (mn + det)) return false;

    return gao(l, idx - 1, det) && gao(idx + 1, r, det);
}

void solve() {
    scanf("%d%d", &n, &K);
    for (int i = 1; i <= n; i++) scanf("%d", &A[i]);

    int g = 0;
    for (int i = 2; i <= n; i++) g = gcd(g, abs(A[i] - A[i - 1]));
    if (g == 0) {
        printf("%d %lld\n", K, 1LL * K * (K + 1) / 2);
        return;
    }

    build(1, 1, n);
    int mn = INF;
    for (int i = 1; i <= n; i++) mn = min(mn, A[i]);
    vector<int> vec;
    auto add = [&](int x) {
        if (x - mn > 0 && x - mn <= K) vec.push_back(x - mn);
    };
    for (int i = 1; i * i <= g; i++) if (g % i == 0) {
        add(i);
        if (i * i != g) add(g / i);
    }

    int cnt = 0;
    long long ans = 0;
    for (int x : vec) if (gao(1, n, x)) cnt++, ans += x;
    printf("%d %lld\n", cnt, ans);
}

int main() {
    int tcase; scanf("%d", &tcase);
    while (tcase--) solve();
    return 0;
}
