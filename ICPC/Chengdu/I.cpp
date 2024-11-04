#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
const int N=2e5+8;
int s[N<<2];

int p[N], cnt, d[N], g[N];
bool st[N];

void modify(int u, int L, int R,int k,int x) {
    if(L==R){
        s[u]=x;
        return;
    }
    int mid=L+R>>1;
    if(k<=mid) modify(u<<1,L,mid,k,x);
    else modify(u<<1|1,mid+1,R,k,x);
    s[u]=__gcd(s[u<<1],s[u<<1|1]);
}

void solve() {
    int n, q;
    std::cin >> n >> q;
    std::vector<int> a(n + 1);

    for (int i = 1; i <= n; i++) {
        std::cin >> a[i];
    }

    auto add = [&](int x) {
        modify(1, 1, n, x, x);
    };

    auto remove = [&](int x) {
        modify(1, 1, n, x, 0);
    };

    for (int i = 1; i <= n; i++) {
        modify(1, 1, n, i, 0);
    }
    for (int i = 1; i < n; i++) {
        if (a[i + 1] < a[i]) {
            add(i);
        }
    }
    d[0] = n;
    std::cout << d[s[1]] << "\n";
    while (q--) {
        int p, x;
        std::cin >> p >> x;
        if (p > 1 && a[p - 1] > a[p]) {
            remove(p - 1);
        }
        if (p < n && a[p] > a[p + 1]) {
            remove(p);
        }
        a[p] = x;
        if (p > 1 && a[p - 1] > a[p]) {
            add(p - 1);
        }
        if (p < n && a[p] > a[p + 1]) {
            add(p);
        }
        std::cout << d[s[1]] << "\n";
    }
}



void init() {
    d[1] = 1;
    for (int i = 2; i < N; i++) {
        if (!st[i]) p[cnt++] = i, d[i] = 2, g[i] = 1;
        for (int j = 0; j < cnt && i * p[j] < N; j++) {
            st[i * p[j]] = 1;
            if (i % p[j]) {
                g[i * p[j]] = 1;
                d[i * p[j]] = d[i] * d[g[i * p[j]] + 1];
            } else {
                g[i * p[j]] = g[i] + 1;
                d[i * p[j]] = d[i] / (g[i] + 1) * (g[i * p[j]] + 1);
                break;
            }
        }
    }
    
    // for (int i = 1; i <= 50; i++) {
    //     std::cerr << i << " " << d[i] << "\n";
    // }
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    init();
    int t = 1;
    std::cin >> t;
    while (t --) {
        solve();
    }
}