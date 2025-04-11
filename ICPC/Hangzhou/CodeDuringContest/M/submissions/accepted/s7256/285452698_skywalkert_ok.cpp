#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

const int maxn = (int)2e5 + 9, maxm = (int)3.2e4 + 9, maxe = 9;

int tot, d[maxm], pr[maxm];

void prepare() {
    for(int i = 2; i < maxm; ++i) {
        if(!d[i])
            pr[tot++] = d[i] = i;
        for(int j = 0, k; (k = i * pr[j]) < maxm; ++j) {
            d[k] = pr[j];
            if(d[i] == pr[j])
                break;
        }
    }
    pr[tot] = maxm;
    assert(maxm * maxm > (int)1e9);
}

void solve() {
    int n, m;
    static int a[maxn], b[maxn], ord[maxn], rnk[maxn], pL[maxn], pR[maxn];
    scanf("%d%d", &n, &m);
    int com = 0;
    for(int i = 0; i < n; ++i) {
        scanf("%d", a + i);
        b[i] = 0;
        ord[i] = pL[i] = pR[i] = i;
        if(i > 0)
            com = gcd(com, abs(a[i] - a[i - 1]));
    }
    // printf("com: %d\n", com);
    if(!com) {
        printf("%d %lld\n", m, m * (m + 1LL) / 2);
        return;
    }
    sort(ord, ord + n, [&](int const &u, int const &v) {
        return a[u] > a[v];
    });
    for(int i = 0; i < n; ++i)
        rnk[ord[i]] = i;
    int low = a[ord[n - 1]];
    map<int, int> lim;
    // printf("low: %d\n", low);
    for(int i = 0; i < n; ++i) {
        int u = ord[i], L = u, R = u;
        if(a[u] == low)
            break;
        if(u > 0 && rnk[u - 1] < rnk[u]) {
            int nL = pL[u - 1];
            b[nL] = gcd(b[nL], gcd(abs(a[u - 1] - a[u]), b[L]));
            L = nL;
        }
        if(u + 1 < n && rnk[u + 1] < rnk[u]) {
            int nR = pR[u + 1];
            b[L] = gcd(b[L], gcd(abs(a[u] - a[u + 1]), b[R + 1]));
            R = nR;
        }
        pL[R] = L;
        pR[L] = R;
        if(!b[L])
            continue;
        int k1 = (a[u] - low) / com;
        int k2 = b[L] / com;
        int &val = lim[k1];
        val = gcd(val, k2);
    }
    vector<pair<int, int> > cand(lim.begin(), lim.end());
    reverse(cand.begin(), cand.end());
    // for(auto &[k1, k2]: cand)
    //     printf("%d %d\n", k1, k2);
    int sz = 0, old = com;
    static int p[maxe], e[maxe];
    for(int i = 0; pr[i] * pr[i] <= com; ++i) {
        if(com % pr[i] > 0)
            continue;
        for(p[sz] = pr[i], e[sz] = 0; com % p[sz] == 0; ++e[sz], com /= p[sz]);
        // printf("(%d, %d) ", p[sz], e[sz]);
        ++sz;
    }
    if(com > 1) {
        // printf("(%d, %d) ", com, 1);
        p[sz] = com;
        e[sz++] = 1;
    }
    // puts("");
    int cnt = 0;
    LL sum = 0;
    function<void(int,int)> dfs = [&](int dep, int val) {
        if(dep == sz) {
            int res = old / val - low;
            // printf("chk %d %d\n", val, res);
            if(res <= 0 || res > m)
                return;
            for(auto &[k1, k2]: lim)
                if((LL)k2 * val % ((LL)k1 * val + 1) != 0)
                    return;
            ++cnt;
            sum += res;
            return;
        }
        for(int i = 0; i <= e[dep]; ++i, val *= p[dep])
            dfs(dep + 1, val);
    };
    dfs(0, 1);
    printf("%d %lld\n", cnt, sum);
}

int main() {
    prepare();
    int T = 1;
    scanf("%d", &T);
    for(int Case = 1; Case <= T; ++Case) {
        // printf("Case #%d: ", Case);
        solve();
    }
    return 0;
}
