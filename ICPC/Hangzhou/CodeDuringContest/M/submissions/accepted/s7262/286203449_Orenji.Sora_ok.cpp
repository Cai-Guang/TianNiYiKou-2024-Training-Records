#include<bits/stdc++.h>

using namespace std;
#define MAXN 200010

int n, k;
int x[MAXN], a[MAXN], f[MAXN];
int fa[MAXN], dv[MAXN];
bool vis[MAXN];

void read() {
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; ++i)
        scanf("%d", x + i);
}

int Gcd(int a, int b) {
    for (int t; b; t = a % b, a = b, b = t);
    return a;
}

int find(int u) {
    return f[u] == u ? u : f[u] = find(f[u]);
}

void work() {
    for (int i = 1; i <= n; ++i) a[i] = f[i] = fa[i] = i, vis[i] = false;
    sort(a + 1, a + 1 + n, [](const int &i, const int &j){return x[i] > x[j];});

    int lcm = 0;
    for (int i = 1; i <= n; ++i) {
        int j = a[i]; vis[j] = true;
        if (j < n) {
            int u = find(j + 1);
            if (vis[u]) {
                lcm = x[u] != x[j] && x[u] - x[j] < x[j] ? 1 : Gcd(lcm, x[u] - x[j]);
                fa[u] = f[u] = j;
            }
        }
        if (j > 1) {
            int u = find(j - 1);
            if (vis[u]) {
                lcm = x[u] != x[j] && x[u] - x[j] < x[j] ? 1 : Gcd(lcm, x[u] - x[j]);
                fa[u] = f[u] = j;
            }
        }
    }
    if (lcm == 0) {
        printf("%d %lld\n", k, 1ll * k * (k + 1) / 2);
        return;
    }
    dv[0] = 0;
    for (int i = 1, mix = x[a[n]]; i <= lcm && 1ll * i * i <= lcm; ++i) {
        if (lcm % i) continue;
        if (i > mix && i - mix <= k) {
            dv[++dv[0]] = i - mix;
        }
        int j = lcm / i;
        if (i != j && j > mix && j - mix <= k) {
            dv[++dv[0]] = j - mix;
        }
    }

    int cnt = 0; long long sum = 0;
    for (int i = 1; i <= dv[0]; ++i) {
        bool flag = true;
        for (int j = 1; j <= n; ++j) {
            if ((x[j] + dv[i]) % (x[fa[j]] + dv[i])) {
                flag = false;
                break;
            }
        }
        if (flag) ++cnt, sum += dv[i];
    }

    printf("%d %lld\n", cnt, sum);
}


int main() {
    int T;
    for (scanf("%d", &T); T; --T) {
        read();
        work();
    }
    return 0;
}
