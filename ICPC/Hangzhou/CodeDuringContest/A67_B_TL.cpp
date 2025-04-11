#include <bits/stdc++.h>
using namespace std;

#define all(a) a.begin(), a.end()
using ll = long long;

const int N = 1e6 + 5, M = 63;

#define ls (p << 1)
#define rs (p << 1 | 1)
#define mid ((l + r) >> 1)

ll a[N];
int b[N], n;

struct Info {
    int cnt = 0, pos = 0;
};

Info operator + (const Info& a, const Info& b) {
    Info c;
    c.cnt = a.cnt + b.cnt;
    if (a.pos) {
        c.pos = a.pos;
    } else if (b.pos) {
        c.pos = b.pos;
    }
    return c;
}

struct SegTree {
    Info info[N << 2];
    bitset<N << 2> f;
    // int f[N << 2];

    void pull (int p) {
        info[p] = info[ls] + info[rs];
    }

    void apply (int p, int l, int r) {
        info[p].cnt = r - l + 1;
        info[p].pos = l;
        f[p] = 1;
    }

    void push (int p, int l, int r) {
        if (!f[p]) {
            return;
        }
        apply(ls, l, mid);
        apply(rs, mid + 1, r);
        f[p] = 0;
    }

    void build (int p, int l, int r) {
        if (l == r) {
            if (!b[l]) {
                info[p].cnt = 1;
                info[p].pos = l;
            }
            return;
        }
        build(ls, l, mid);
        build(rs, mid + 1, r);
        pull(p);
    }

    void modifyRange (int p, int l, int r, int x, int y) {
        if (r < x || l > y) {
            return;
        }
        if (x <= l && r <= y) {
            apply(p, l, r);
            return;
        }
        push(p, l, r);
        modifyRange(ls, l, mid, x, y);
        modifyRange(rs, mid + 1, r, x, y);
        pull(p);
    }

    void modifyRange (int l, int r) {
        modifyRange(1, 1, n, l, r);
    }

    void modifySingle (int p, int l, int r, int x, int v) {
        if (l == r) {
            if (!v) {
                info[p].cnt = 1;
                info[p].pos = l;
            } else {
                info[p].cnt = 0;
                info[p].pos = 0;
            }
            return;
        }
        push(p, l, r);
        if (x <= mid) {
            modifySingle(ls, l, mid, x, v);
        } else {
            modifySingle(rs, mid + 1, r, x, v);
        }
        pull(p);
    }

    void modifySingle (int x, int v) {
        modifySingle(1, 1, n, x, v);
    }

    Info query (int p, int l, int r, int x, int y) {
        if (r < x || l > y) {
            return Info();
        }
        if (x <= l && r <= y) {
            return info[p];
        }
        push(p, l, r);
        return query(ls, l, mid, x, y) + query(rs, mid + 1, r, x, y);
    }

    Info query (int l, int r) {
        return query(1, 1, n, l, r);
    }
} seg[M];

void solve() {
    int q;
    cin >> n >> q;

    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
    }

    for (int j = 0; j < M; j ++) {
        for (int i = 1; i <= n; i ++) {
            b[i] = a[i] >> j & 1;
        }
        seg[j].build(1, 1, n);
    }

    while (q --) {
        int op;
        cin >> op;

        if (op == 1) {
            int l, r;
            ll x;
            cin >> l >> r >> x;
            for (int j = 0; j < M; j ++) {
                if (x >> j & 1 ^ 1) {
                    seg[j].modifyRange(l, r);
                }
            }
        } else if (op == 2) {
            int s;
            ll x;
            cin >> s >> x;
            for (int j = 0; j < M; j ++) {
                seg[j].modifySingle(s, x >> j & 1);
            }
        } else {
            int l, r;
            cin >> l >> r;

            if (l == r) {
                cout << 0 << '\n';
                continue;
            }

            ll ans = 0;
            for (int j = M - 1; j >= 0; j --) {
                auto g = seg[j].query(l, r);
                // if (q == 0) cout << "! " << j << ' ' << g.cnt << endl;
                if (!g.cnt) {
                    ans |= 1ll << j;
                } else if (g.cnt == 1) {
                    int p = g.pos;
                    ans |= 1ll << j;
                    for (int k = j - 1; k >= 0; k --) {
                        auto h = seg[k].query(l, p - 1) + seg[k].query(p + 1, r);
                        if (!h.cnt) {
                            ans |= 1ll << k;
                        }
                    }
                    break;
                }
            }

            cout << ans << '\n';
        }
    }
}
/*
5 9
7 7 7 6 7
3 1 5
2 1 3
3 1 5
3 1 3
1 1 2 3
3 1 3
2 2 8
3 1 3
3 1 2
*/
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t --) {
        solve();
    }
    return 0;
}