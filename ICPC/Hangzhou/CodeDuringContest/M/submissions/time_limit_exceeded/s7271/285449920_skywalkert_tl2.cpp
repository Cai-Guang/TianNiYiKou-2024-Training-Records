#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2")

// should TLE
#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

const int maxn = (int)2e5 + 9;

void solve() {
    int n, m;
    static int a[maxn];
    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; ++i)
        scanf("%d", a + i);
    if(*min_element(a, a + n) == *max_element(a, a + n)) {
        printf("%d %lld\n", m, m * (m + 1LL) / 2);
        return;
    }
    m = min(m, *max_element(a, a + n));
    int cnt = 0;
    LL sum = 0;
    for(int i = 1; i <= m; ++i) {
        bool bad = 0;
        for(int L = 0; !bad && L < n; ++L) {
            int low = a[L] + i, com = low;
            for(int R = L; !bad && R < n; ++R) {
                int val = a[R] + i;
                low = min(low, val);
                com = gcd(com, val);
                bad |= com % low != 0;
            }
        }
        if(!bad) {
            ++cnt;
            sum += i;
        }
    }
    printf("%d %lld\n", cnt, sum);
}

int main() {
    int T = 1;
    scanf("%d", &T);
    for(int Case = 1; Case <= T; ++Case) {
        // printf("Case #%d: ", Case);
        solve();
    }
    return 0;
}
