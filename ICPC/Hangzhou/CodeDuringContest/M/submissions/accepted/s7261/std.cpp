#include <bits/stdc++.h>
#define MAXN ((int) 5e4)
#define INF ((int) 2e9)
using namespace std;

int n, K, A[MAXN + 10];
unordered_set<int> ban;

void gao(int l, int r, vector<int> &vec) {
    int g = 0;
    for (int i = l + 1; i <= r; i++) g = gcd(g, abs(A[i] - A[i - 1]));
    if (g == 0) return;

    int mn = INF;
    for (int i = l; i <= r; i++) mn = min(mn, A[i]);
    for (int x : vec) if (g % (mn + x)) ban.insert(x);
    if (ban.size() == vec.size()) return;

    int pos = l;
    for (int i = l; i <= r; i++) if (A[i] == mn) {
        if (pos < i) gao(pos, i - 1, vec);
        pos = i + 1;
    }
    if (pos <= r) gao(pos, r, vec);
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
    ban.clear(); gao(1, n, vec);

    int cnt = 0;
    long long ans = 0;
    for (int x : vec) if (!ban.count(x)) cnt++, ans += x;
    printf("%d %lld\n", cnt, ans);
}

int main() {
    int tcase; scanf("%d", &tcase);
    while (tcase--) solve();
    return 0;
}
