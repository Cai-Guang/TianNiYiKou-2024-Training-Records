#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2")

#include <bits/stdc++.h>
#define MAXN ((int) 2e5)
#define INF ((int) 2e9)
using namespace std;

int n, K, A[MAXN + 10];

bool gao(int l, int r, int det) {
    int g = 0;
    for (int i = l + 1; i <= r; i++) g = gcd(g, abs(A[i] - A[i - 1]));
    if (g == 0) return true;

    int mn = INF;
    for (int i = l; i <= r; i++) mn = min(mn, A[i]);
    if (g % (mn + det)) return false;

    for (int i = l; i <= r; i++) if (A[i] == mn) {
        return gao(l, i - 1, det) && gao(i + 1, r, det);
    }
    assert(false);
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

    int mn = INF;
    for (int i = 1; i <= n; i++) mn = min(mn, A[i]);
    
    int cnt = 0;
    long long ans = 0;
    auto check = [&](int x) {
        if (x - mn > 0 && x - mn <= K && gao(1, n, x - mn)) cnt++, ans += x - mn;
    };
    for (int i = 1; i * i <= g; i++) if (g % i == 0) {
        check(i);
        if (i * i != g) check(g / i);
    }
    printf("%d %lld\n", cnt, ans);
}

int main() {
    int tcase; scanf("%d", &tcase);
    while (tcase--) solve();
    return 0;
}
