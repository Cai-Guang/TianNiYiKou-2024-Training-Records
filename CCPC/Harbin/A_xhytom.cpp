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
#define debug(x) cerr << #x << " = " << (x) << endl;
#define int long long
#define pb push_back
#define eb emplace_back
ll gcd(ll a,ll b){ return b?gcd(b,a%b):a;}
mt19937_64 mrand(chrono::steady_clock().now().time_since_epoch().count());
int rnd(int l,int r){ return mrand() % (r - l + 1) + l;}
void test() {cerr << "\n";}
template<typename T, typename... Args> 
void test(T x, Args... args) {cerr << x << " ";test(args...);}
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
    // freopen("1.in","r",stdin);
#endif
    fastio
    std::cout << std::fixed << std::setprecision(10);
    
    int idx = 0;
    int S = ++idx;
    int T = ++idx;
    
    int L, R;
    std::cin >> L >> R;
    
    std::vector<int> l(100), r(100);
    int x = L;
    int tl = 0, tr = 0;
    while (x) {
        tl++;
        l[tl] = x % 2;
        x /= 2;
    }
    
    x = R;
    while (x) {
        tr++;
        r[tr] = x % 2;
        x /= 2;
    }
    
    std::vector<std::vector<std::pair<int, int>>> adj(105);
    std::vector<int> ind(105), outd(105);
    auto add = [&](int u, int v, int w) {
        adj[u].push_back({v, w});
        outd[u]++;
        ind[v]++;
    };
    
    while (tl == tr && l[tl] == r[tr] && tl > 1) {
        add(S, ++idx, l[tl]);
        S = idx;
        tl--;
        tr--;
    }
    
    std::vector<int> all(100);
    all[0] = T;
    auto get = [&](auto self, int x) -> int {
        if (all[x]) return all[x];
        all[x] = ++idx;
        add(all[x], self(self, x - 1), 0);
        add(all[x], self(self, x - 1), 1);
        return all[x];
    };
    
    // for (int i = 1; i <= 30; i++) {
        // all[i] = ++idx;
        // add(all[i], all[i - 1], 0);
        // add(all[i], all[i - 1], 1);
    // }
    
    std::vector<int> fl(100), fr(100);
    fl[tl] = S;
    fr[tr] = S;
    fl[0] = fr[0] = T;
    
    for (int i = tl - 1; i >= 1; i--) {
        fl[i] = ++idx;
    }
    
    for (int i = tr - 1; i >= 1; i--) {
        fr[i] = ++idx;
    }
    
    for (int i = tl; i >= 1; i--) {
        add(fl[i], fl[i - 1], l[i]);
        if (i != tl && l[i] == 0) {
            add(fl[i], get(get, i - 1), 1);
        }
    }
    for (int i = tr; i >= 1; i--) {
        add(fr[i], fr[i - 1], r[i]);
        if (i != tr && r[i] == 1) {
            add(fr[i], get(get, i - 1), 0);
        }
    }
    
    for (int i = tl; i <= tr - 2; i++) {
        add(S, get(get, i), 1);
    }
    
    std::set<int> st;
    auto dfs = [&](auto self, int x, int val) -> void {
        // debug(x);
        if (x == T) {
            st.insert(val);
            return;
        }
        for (auto [y, w] : adj[x]) {
            self(self, y, 2 * val + w);
        }
    };
    dfs(dfs, 1, 0);
    
    for (int i = 1; i <= 2000000; i++) {
        if (L <= i && i <= R) {
            assert(st.count(i));
        } else {
            assert(!st.count(i));
        }
    }
    
    for (int i = 1; i <= idx; i++) {
    	std::sort(adj[i].begin(), adj[i].end());
    	adj[i].erase(std::unique(adj[i].begin(), adj[i].end()), adj[i].end());
    }
    
    int cntind = 0, cntoutd = 0;
    for (int i = 1; i <= idx; i++) {
        if (ind[i] == 0) cntind++;
        if (outd[i] == 0) cntoutd++;
    }
    
    assert(cntind == 1 && cntoutd == 1);
    
    std::cout << idx << "\n";
    for (int i = 1; i <= idx; i++) {
        std::cout << adj[i].size() << " ";
        for (auto [y, w] : adj[i]) {
            std::cout << y << " " << w << " ";
        }
        std::cout << "\n";
    }
    
    return 0;
}