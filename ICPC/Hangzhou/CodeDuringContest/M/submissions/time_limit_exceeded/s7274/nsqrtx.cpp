#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2")

#include <bits/stdc++.h>
#define MAXN ((int) 5e4)
#define MAXP 16
#define INF ((int) 2e9)
using namespace std;

int n, K, A[MAXN + 10];

int rg[MAXP][MAXN + 10], rm[MAXP][MAXN + 10];

unordered_map<int, int> mp;
int scnt;

int queryG(int l, int r) {
    r--;
    if (l > r) return 0;
    int p = __lg(r - l + 1);
    return gcd(rg[p][l], rg[p][r - (1 << p) + 1]);
}

int queryM(int l, int r) {
    int p = __lg(r - l + 1);
    int x = rm[p][l], y = rm[p][r - (1 << p) + 1];
    return A[x] <= A[y] ? x : y;
}

void gao(int l, int r) {
    int g = queryG(l, r);
    if (g == 0) return;

    int idx = queryM(l, r);
    int mn = A[idx];

    scnt++;
    for (int i = 1; i * i <= g; i++) if (g % i == 0) {
        if (i - mn > 0 && i - mn <= K) mp[i - mn]++;
        int t = g / i;
        if (t != i && t - mn > 0 && t - mn <= K) mp[t - mn]++;
    }

    gao(l, idx - 1);
    gao(idx + 1, r);
}

void solve() {
    scanf("%d%d", &n, &K);
    for (int i = 1; i <= n; i++) scanf("%d", &A[i]);

    for (int i = 1; i < n; i++) rg[0][i] = abs(A[i] - A[i + 1]);
    for (int p = 1, len = 2; p < MAXP; p++, len *= 2) for (int i = 1; i + len - 1 < n; i++)
        rg[p][i] = gcd(rg[p - 1][i], rg[p - 1][i + len / 2]);
    for (int i = 1; i <= n; i++) rm[0][i] = i;
    for (int p = 1, len = 2; p < MAXP; p++, len *= 2) for (int i = 1; i + len - 1 <= n; i++) {
        if (A[rm[p - 1][i]] <= A[rm[p - 1][i + len / 2]]) rm[p][i] = rm[p - 1][i];
        else rm[p][i] = rm[p - 1][i + len / 2];
    }

    mp.clear(); scnt = 0;
    gao(1, n);

    if (scnt == 0) printf("%d %lld\n", K, 1LL * K * (K + 1) / 2);
    else {
        int cnt = 0;
        long long ans = 0;
        for (auto &p : mp) if (p.second == scnt) cnt++, ans += p.first;
        printf("%d %lld\n", cnt, ans);
    }
}

int main() {
    int tcase; scanf("%d", &tcase);
    while (tcase--) solve();
    return 0;
}
