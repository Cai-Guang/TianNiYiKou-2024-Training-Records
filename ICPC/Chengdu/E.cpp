#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
#define int long long
const int mod=998244353;

struct node{
    int x,y;
    node() {}
    node(int _x,int _y){
        x=_x,y=_y;
    }
};
const node one(0,1);
int qpow(int a,int b){
    int ans=1;
    for(;b;b>>=1){
        if(b&1) ans=ans*a%mod;
        a=a*a%mod;
    }
    return ans;
}
node operator+(const node&a,const node &b){
    node c(0,0);
    if(!a.x) c.y+=a.y;
    if(!b.x) c.y+=b.y;
    if(c.y%mod==0){
        c.x=1;
        c.y=c.y/mod;
    }
    else{
        c.y%=mod;
    }
    return c;
}
node operator*(const node&a,const node &b){
    node c(0,0);
    c.x=a.x+b.x;
    c.y=a.y*b.y%mod;
    return c;
}
node operator/(const node&a,const node &b){
    node c(0,0);
    c.x=a.x-b.x;
    c.y=a.y*qpow(b.y,mod-2)%mod;
    return c;
}

int get(node x){
    if(x.x) return 0;
    else return x.y; 
}


void solve(){
    int n,q;
    cin>>n>>q;
    vector<int>p(n+1);
    vector<vector<int>>e(n+1);
    for(int i=2;i<=n;++i){
        cin>>p[i];
        e[p[i]].push_back(i);
    }
    vector<node>f(n+1);
    vector<int>dep(n+1);
    vector fa(n+1,vector(40,0ll));
    auto g=fa;
    auto dfs1=[&](auto dfs1,int u)->void{
        f[u]=one;
        for(auto v:e[u]){
            dfs1(dfs1,v);
            f[u]=f[u]*(one+f[v]);
        }
    };
    auto dfs2=[&](auto dfs2,int u,int pa)->void{
        fa[u][0]=pa;
        g[u][0]=get(f[u]);
        dep[u]=dep[pa]+1;
        for(int i=1;i<=__lg(dep[u]);++i){
            fa[u][i]=fa[fa[u][i-1]][i-1];
            g[u][i]=g[u][i-1]+g[fa[u][i-1]][i-1];
            if(g[u][i]>=mod) g[u][i]-=mod;
        }
        for(auto v:e[u]){
            dfs2(dfs2,v,u);
        }
    };
    dfs1(dfs1,1);
    dfs2(dfs2,1,0);
    vector<int>res(q),lca(q);
    auto LCA=[&](int x,int y,int &ans)->int{
        if(dep[x]>dep[y]) swap(x,y);
        while(dep[x]<dep[y]){
            ans+=g[y][__lg(dep[y]-dep[x])];
            y=fa[y][__lg(dep[y]-dep[x])];
        }
        if(x==y) return x;
        for(int i=__lg(dep[x]);i>=0;--i){
            if(fa[x][i]!=fa[y][i]){
                ans+=g[x][i];
                ans+=g[y][i];
                x=fa[x][i];
                y=fa[y][i];
            }
        }
        ans+=g[x][0]+g[y][0];
        return fa[x][0];
    };
    for(int i=0;i<q;++i){
        int u,v;
        cin>>u>>v;
        lca[i]=LCA(u,v,res[i]);
    }
    auto dfs=[&](auto dfs,int u)->void{
        for(auto v:e[u]){
            node x=f[u]/(f[v]+one)+one;
            f[v]=f[v]*x;
            dfs(dfs,v);
        }
    };
    dfs(dfs,1);
    for(int i=0;i<q;++i){
        // cerr<<" ! "<<res[i]<<" "<<get(f[lca[i]])<<endl;
        cout<<(res[i]+get(f[lca[i]]))%mod<<"\n";
    }
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int t = 1;
    std::cin >> t;
    while (t --) {
        solve();
    }
}