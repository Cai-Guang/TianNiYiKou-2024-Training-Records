#include <bits/stdc++.h>
#define sz(x) ((int)(x).size())
#define all(x) begin(x), end(x)
#ifdef memset0
#define log(...) fprintf(stderr, __VA_ARGS__)
#else
#define endl '\n'
#define log(...) (void(0))
#endif
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using ull = unsigned long long;
const int N = 2e5 + 10;
#define pi pair<int, int>
#define v first
#define g second
#define clr(vec) vector<pi>().swap(vec)
int T, n, K, a[N], lc[N], rc[N], ar[N], sz, lst;
int g[N], ag;
vector<pi> a1, a2;
void Calc(int l, int r, int x) {
  if (l > r)
    return;
  if (l == r)
    return (void)(g[x] = 0);
  Calc(l, x - 1, lc[x]), Calc(x + 1, r, rc[x]);
  g[x] = gcd(g[lc[x]], g[rc[x]]);
  if (lc[x])
    g[x] = gcd(a[x - 1] - a[x], g[x]);
  if (rc[x])
    g[x] = gcd(a[x + 1] - a[x], g[x]);
  if (g[x])
    a1.push_back((pi){a[x], g[x]});
}
int ans;
ll sum;
void Check(int x) {
  if (x <= 0)
    return;
  if (x > K)
    return;
  for (pi i : a2) {
    if (i.g % (x + i.v))
      return;
  }
  ++ans;
  sum += x;
}
int mnv;
int main() {
#ifdef memset0
  freopen("M.in", "r", stdin);
#endif
  cin.tie(0)->sync_with_stdio(0);
  cin >> T;
  while (T--) {
    cin >> n >> K;
    sz = 0;
    clr(a1), clr(a2);
    for (int i = 1; i <= n; ++i)
      lc[i] = rc[i] = 0;
    for (int i = 1; i <= n; ++i)
      cin >> a[i];
    for (int i = 1; i <= n; ++i) {
      lst = 0;
      while (sz && a[ar[sz]] >= a[i]) {
        if (lst)
          rc[ar[sz]] = lst;
        lst = ar[sz--];
      }
      lc[i] = lst;
      ar[++sz] = i;
    }
    for (int i = 1; i < sz; ++i)
      rc[ar[i]] = ar[i + 1];
    ag = 0;
    mnv = a[ar[1]];
    Calc(1, n, ar[1]);
    ag = g[ar[1]];
    if (!ag) {
      cout << K << " " << (1ll * K * (K + 1) >> 1) << "\n";
      continue;
    }
    sort(all(a1));
    for (int i = 0, j; i < a1.size(); i = j) {
      j = i;
      int tg = 0;
      while (j < a1.size() && a1[j].v == a1[i].v) {
        tg = gcd(tg, a1[j].g);
        ++j;
      }
      a2.push_back((pi){a1[i].v, tg});
    }
    ans = sum = 0;
    for (int i = mnv + 1; 1ll * i * i <= ag; ++i)
      if (ag % i == 0) {
        Check(i - mnv);
        if (ag / i != i)
          Check(ag / i - mnv);
      }
    cout << ans << " " << sum << "\n";
  }
}
