#include <bits/stdc++.h>

using namespace std;

#define int long long

struct BIT {
    int n;
    vector<int> c;
    BIT(int n):n(n),c(n+1){}
    int lowbit(int x) {
        return x & (-x);
    }
    int query(int x){
        int res=0;
        while(x){
            res+=c[x];
            x-=lowbit(x);
        }
        return res;
    }
    void add(int u,int x){
        while(u<=n){
            c[u]+=x;
            u+=lowbit(u);
        }
    }
};

void solve() {
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;++i) cin>>a[i];
    int x=__builtin_ctzll(n);
    vector<int>s(x+2),ns(x+2);
    auto solve=[&](auto solve,int t,vector<int>a)->void{
        int n=a.size();
        if(n==1) return;
        vector<int>l,r;
        for(int i=0;i<n;++i){
            if((a[i]>>t&1)){
                r.push_back(a[i]);
            }
            else{
                l.push_back(a[i]);
                s[t]+=r.size();
            }
        }
        int c0=0;
        for(int i=0;i<n;++i){
            if((a[i]>>t&1)) c0++;
            else ns[t]+=c0;
        }
        solve(solve,t-1,l),solve(solve,t-1,r);
    };
    int r1=0;
    BIT ft(n+1);
    for(int i=n;i;--i){
        r1+=ft.query(a[i]);
        ft.add(a[i]+1,1);
    }
    // solve(solve,x,a);
    for(int i=0;i<=x;++i) cout<<s[i]<<" "<<ns[i]<<" ! "<<endl;
    cout<<" # "<<r1<<endl;
    int res=1;
    for(int i=0;i<=x;++i) res+=min(s[i],ns[i]);
    res=min(res,r1);cout<<" ? "<<endl;
    cout<<res<<"\n";cout<<" ? "<<endl;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    // std::cin >> t;

    while (t --) {
        solve();
    }
}