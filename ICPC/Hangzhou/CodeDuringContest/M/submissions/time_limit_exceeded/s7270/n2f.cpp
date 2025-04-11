#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2")

#include <bits/stdc++.h>
#define MAXN ((int) 5e4)
#define MAXP 16
#define INF ((int) 2e9)
using namespace std;

int n, K, A[MAXN + 10];

bool check(int x) {
    for (int l = 1; l <= n; l++) {
        int mn = A[l] + x;
        for (int r = l; r <= n; r++) {
            if (A[r] + x < mn) {
                if (mn % (A[r] + x)) return false;
                mn = A[r] + x;
            } else {
                if ((A[r] + x) % mn) return false;
            }
        }
    }
    return true;
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
    for (int x : vec) if (check(x)) cnt++, ans += x;
    printf("%d %lld\n", cnt, ans);
}

int main() {
    int tcase; scanf("%d", &tcase);
    while (tcase--) solve();
    return 0;
}
