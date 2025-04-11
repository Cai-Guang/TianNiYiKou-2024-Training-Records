#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5 + 5;

int n, k;
int a[maxn], stk[maxn], f[maxn], g[maxn], d[maxn], ok[maxn];

inline void solve(){
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; ++i) scanf("%d", a + i);
    int top = 0;
    vector<pair<int, int> > vec;
    for (int i = 0; i < n; ++i) {
        for (; top && a[stk[top]] >= a[i]; --top);
        if (top) f[i] = stk[top];
        else f[i] = -1;
        stk[++top] = i;
    }
    top = 0;
    for (int i = n - 1; i >= 0; --i) {
        for (; top && a[stk[top]] >= a[i]; --top);
        if (top) g[i] = stk[top];
        else g[i] = -1;
        stk[++top] = i;
        if (f[i] != -1 || g[i] != -1) {
            if (g[i] == -1 || a[f[i]] > a[g[i]]) vec.push_back(make_pair(f[i], i));
            else vec.push_back(make_pair(g[i], i));
        }
    }
    if (vec.size() == 0) {
        printf("%d %lld\n", k, 1ll * k * (k + 1) / 2);
        return;
    }
    // for (int i = 0; i < vec.size(); ++i) printf("(%d %d %d)\n", vec[i].first, vec[i].second, a[vec[i].second] - a[vec[i].first]);
    // puts("ok");
    int len = 0;
    for (int i = 1; 1ll * i * i <= (a[vec[0].second] - a[vec[0].first]); ++i) {
        // printf("i = %d\n", i);
        if ((a[vec[0].second] - a[vec[0].first]) % i == 0) {
            if (i - a[vec[0].first] > 0 && i - a[vec[0].first] <= k) d[len++] = i - a[vec[0].first];
            int j = (a[vec[0].second] - a[vec[0].first]) / i;
            if (j != i) {
                if (j - a[vec[0].first] > 0 && j - a[vec[0].first] <= k) d[len++] = j - a[vec[0].first];
            }
        }
    }
    // printf("len = %d\n", len);
    // for (int i = 0; i < len; ++i) printf("%d ", d[i]); puts("");
    for (int i = 0; i < len; ++i) ok[i] = 1;
    for (int i = 1; i < vec.size(); ++i) {
        for (int j = 0; j < len; ++j) if ((a[vec[i].second] + d[j]) % (a[vec[i].first] + d[j]) != 0) ok[j] = false;
    }

    int ans = 0; long long sum = 0;
    for (int i = 0; i < len; ++i) ans += ok[i], sum += ok[i] * d[i];
    printf("%d %lld\n", ans, sum);
}

int main(){
    int T;
    for (scanf("%d", &T); T--; solve());
    return 0;
}

/*
3
5 4
7 79 1 7 1
2 1000000000
1 2
1 100
1000000000
*/
