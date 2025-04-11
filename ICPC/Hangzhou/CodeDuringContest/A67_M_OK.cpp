#include <bits/stdc++.h>
using namespace std;

#define all(a) a.begin(), a.end()
using ll = long long;

void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> b(n);
    for (int i = 0; i < n; i ++) {
        cin >> b[i];
    }

    int g = 0;
    for (int i = 0; i + 1 < n; i ++) {
        g = gcd(g, abs(b[i] - b[i + 1]));
    }

    if (!g) {
        cout << k << ' ' << 1ll * k * (k + 1) / 2 << '\n';
        return;
    }

    ll cnt = 0, sum = 0;
    int mn = *min_element(all(b));

    auto calc = [&](int x) {
        if (x <= mn || x > mn + k) {
            return;
        }
        int d = x - mn;
        for (int i = 0; i + 1 < n; i ++) {
            int p = b[i] + d;
            int q = b[i + 1] + d;
            if (p > q) {
                swap(p, q);
            }
            if (q % p) {
                return;
            }
        }
        cnt ++;
        sum += x - mn;
    };

    for (int i = 1; i * i <= g; i ++) {
        if (g % i == 0) {
            calc(i);
            if (i * i != g) {
                calc(g / i);
            }
        }
    }

    cout << cnt << ' ' << sum << '\n';
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