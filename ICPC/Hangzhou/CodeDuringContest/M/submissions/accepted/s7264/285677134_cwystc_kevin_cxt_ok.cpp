#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int n, m, a[N];
int c[N][2];
int req;
unordered_map<int, int> mp;
inline void Count(int a, int b) {
    // (b - a) % (a + x) = 0
    b -= a;
    for (int i = 1; i * i <= b; ++i) if (b % i == 0) {
        // i - a; b / i - a
        int u = i - a, v = b / i - a;
        if (u >= 1 && u <= m) ++mp[u];
        if (v >= 1 && v <= m && v != u) ++mp[v];
    }
}
inline void Solve(int x) {
    for (int d = 0; d < 2; ++d) if (c[x][d]) {
        Solve(c[x][d]);
        if (a[x] != a[c[x][d]]) {
            ++req;
            Count(a[x], a[c[x][d]]);
        }
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int Case;
    cin >> Case;
    while (Case--) {
        cin >> n >> m;
        stack<int> stk;
        stk.push(0);
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
            while (a[stk.top()] >= a[i]) {
                c[i][0] = stk.top();
                stk.pop();
            }
            c[stk.top()][1] = i;
            stk.push(i);
        }
        req = 0;
        mp.clear();
        Solve(c[0][1]);
        if (req == 0) { cout << m << ' ' << 1ll * m * (m + 1) / 2 << '\n'; }
        else {
            int cnt = 0;
            long long ans = 0;
            for (auto [x, y] : mp) if (y == req) {
                ++cnt;
                ans += x;
            } 
            cout << cnt << ' ' << ans << '\n';
        }
        for (int i = 0; i <= n; ++i) c[i][0] = c[i][1] = 0;
    }
    return 0;
}
