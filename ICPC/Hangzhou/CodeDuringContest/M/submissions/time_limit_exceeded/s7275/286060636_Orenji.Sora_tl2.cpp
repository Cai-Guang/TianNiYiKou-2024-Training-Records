#include<bits/stdc++.h>

using namespace std;
#define MAXN 200020

int n, k;
int a[MAXN];

void read() {
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; ++i)
        scanf("%d", a + i);
}

int Gcd(int a, int b) {
    for (int t; b; t = a % b, a = b, b = t);
    return a;
}

void work() {
    sort(a + 1,a + 1 + n);
    int lcm = 0;
    for (int i = 1; i < n; ++i) {
        lcm = Gcd(lcm, a[i + 1] - a[i]);
    }
    if (lcm == 0) {
        printf("%d %lld\n", k, 1ll * k * (k + 1) / 2);
        return;
    }
    int cnt = 0; long long sum = 0;
    for (int i = a[1] + 1; i <= lcm && i - a[1] <= k; ++i) {
        if (lcm % i) continue;
        ++cnt; sum += i - a[1];
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
