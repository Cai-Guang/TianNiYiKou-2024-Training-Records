#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2")

#include <bits/stdc++.h>
#define MAXN ((int) 2e5)
#define INF ((int) 2e9)
using namespace std;

int n, K, A[MAXN + 10];

unordered_map<int, int> mp;
int scnt;

void gao(int l, int r) {
    int g = 0;
    for (int i = l + 1; i <= r; i++) g = gcd(g, abs(A[i] - A[i - 1]));
    if (g == 0) return;

    int mn = INF;
    for (int i = l; i <= r; i++) mn = min(mn, A[i]);

    scnt++;
    for (int i = 1; i * i <= g; i++) if (g % i == 0) {
        if (i - mn > 0 && i - mn <= K) mp[i - mn]++;
        int t = g / i;
        if (t != i && t - mn > 0 && t - mn <= K) mp[t - mn]++;
    }

    int pos = l;
    for (int i = l; i <= r; i++) if (A[i] == mn) {
        if (pos < i) gao(pos, i - 1);
        pos = i + 1;
    }
    if (pos <= r) gao(pos, r);
}

void solve() {
    scanf("%d%d", &n, &K);
    for (int i = 1; i <= n; i++) scanf("%d", &A[i]);

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
