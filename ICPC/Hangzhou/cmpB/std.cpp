/*
 
_/      _/    _/      _/    _/      _/   _/_/_/_/_/     _/_/       _/      _/ 
 _/    _/     _/      _/     _/    _/        _/       _/    _/     _/      _/            
  _/  _/      _/      _/      _/  _/         _/      _/      _/    _/_/  _/_/         
   _/_/       _/_/_/_/_/        _/           _/      _/      _/    _/  _/  _/          
  _/  _/      _/      _/        _/           _/      _/      _/    _/      _/          
 _/    _/     _/      _/        _/           _/       _/    _/     _/      _/          
_/      _/    _/      _/        _/           _/         _/_/       _/      _/       
 
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
using i64 = long long;
#define rep(i,a,n) for(int i=a;i<n;i++)
#define per(i,a,n) for(int i=n-1;i>=a;i--)
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define multi int _;cin>>_;while(_--)
#define int long long
#define pb push_back
#define eb emplace_back
ll gcd(ll a,ll b){ return b?gcd(b,a%b):a;}
mt19937_64 mrand(chrono::steady_clock().now().time_since_epoch().count());
int rnd(int l,int r){ return mrand() % (r - l + 1) + l;}
#ifdef localfreopen
#define debug(x) cerr << #x << " = " << (x) << endl;
#else
#define debug //
#define test //
#endif
const ll MOD = 998244353;
// const ll MOD = 1e9+7;
ll ksm(ll x,ll y){ll ans=1;x%=MOD;while(y){if(y&1)ans=ans*x%MOD;x=x*x%MOD,y/=2;}return ans;}

const int P1 = 972152273, base1 = 809;
const int P2 = 905563261, base2 = 919;
const ll N = 200005;
//head



signed main()
{  
#ifdef localfreopen
    // freopen("1.in","w",stdout);
#endif
    fastio
    std::cout << std::fixed << std::setprecision(10);

    int n, q;
    std::cin >> n >> q;
    std::vector<i64> a(n + 1);
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i];
    }

    while (q--) {
        int o;
        std::cin >> o;
        if (o == 1) {
            int l, r, v;
            std::cin >> l >> r >> v;
            for (int i = l; i <= r; i++) {
                a[i] &= v;
            }
        } else if (o == 2) {
            int p, x;
            std::cin >> p >> x;
            a[p] = x;
        } else if (o == 3) {
            int l, r;
            std::cin >> l >> r;
            int ans = 0;
            for (int i = l; i <= r; i++) {
                int res = -1;
                for (int j = l; j <= r; j++) {
                    if (i != j) {
                        res &= a[j];
                    }
                }
                ans = std::max(ans, res);
            }
            std::cout << ans << "\n";
        } else {
            assert(0);
        }
    }
    return 0;
}