#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector g(n + 1, vector<int>(m + 1, 0));
    vector<int> a(n * m + 1);
    for (int i = 1; i <= n * m; i ++) {
        cin >> a[i];
    }
    int ans = 1e18;
    int cnt = 0;
    vector<int> row(n + 1);
    int flg = 0;
    for (int i = 1; i <= n * m; i ++) {
        int y = a[i] % m;
        int x = a[i] / m + 1;
        if (y == 0) x --;
        row[x] ++;
        if (flg && i >= m) {
            ans = i;
            break;
        }
        if (row[x] + k >= m) {
            flg = 1;
        }
        if (i >= m && row[x] + k >= m) {
            ans = i;
            break;
        }
    }
    cout << ans << '\n';
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    while (t --) {
        solve();
    }
    return 0;
}