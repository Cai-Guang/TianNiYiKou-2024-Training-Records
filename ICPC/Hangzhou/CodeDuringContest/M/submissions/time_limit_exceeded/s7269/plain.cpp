#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2")

#include <bits/stdc++.h>
#define MAXN ((int) 5e4)
#define MAXP 16
#define INF ((int) 2e9)
using namespace std;

int n, K, A[MAXN + 10];

bool gao(int l, int r, int det) {
    if (l >= r) return true;
    int mn = A[l], idx = l;
    for (int i = l; i <= r; i++) if (A[i] < mn) mn = A[i], idx = i;
    for (int i = l; i <= r; i++) if (A[i] % (mn + det)) return false;
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

    int cnt = 0;
    long long ans = 0;
    for (int x = 1; x <= K; x++) if (gao(1, n, x)) cnt++, ans += x;
    printf("%d %lld\n", cnt, ans);
}

int main() {
    int tcase; scanf("%d", &tcase);
    while (tcase--) solve();
    return 0;
}
