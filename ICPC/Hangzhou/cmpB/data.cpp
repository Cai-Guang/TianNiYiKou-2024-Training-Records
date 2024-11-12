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
//head

const int N = 1000;
const int M = 1000;

signed main()
{  
	int n = rnd(1, N);
	int q = rnd(1, N);
	
	std::cout << n << ' ' << q << '\n';
	
	for (int i = 1; i <= n; i++) {
		std::cout << rnd(1, M) << " \n"[i == n];
	}
	
	for (int i = 1; i <= q; i++) {
		int op = rnd(1, 3);
		if (i == q) {
			op = 3;
		}
		if (op == 1) {
			int l = rnd(1, n), r = rnd(l, n), x = rnd(1, M);
			std::cout << op << ' ' << l << ' ' << r << ' ' << x << '\n'; 
		} else if (op == 2) {
			int l = rnd(1, n), x = rnd(1, M);
			std::cout << op << ' ' << l << ' ' << x << '\n'; 
		} else {
			int l = rnd(1, n), r = rnd(l, n);
			std::cout << op << ' ' << l << ' ' << r << '\n'; 
		}
	}
	
}