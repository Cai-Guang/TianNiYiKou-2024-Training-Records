#include <bits/stdc++.h>
using namespace std;
const int N=1e6+8;
int n,q;
long long a[N],res[N],x[N];
int o[N],l[N],r[N],use[N],s[N],tag[N],mi[N];
int ss[N];

void adaad() {std::cerr << std::endl;}\
template <typename T, typename... Args>
void adaad(T x, Args... args) {
    std::cerr << x << ' ';
    adaad(args...);
}

// #define test adaad

void pushdown(int u,int cl,int cr){
    if(!tag[u]) return;
    int mid=cl+cr>>1;
    s[u<<1]=s[u<<1|1]=0;
    mi[u<<1]=cl;
    mi[u<<1|1]=mid+1;
    tag[u]=0;
    tag[u<<1]=tag[u<<1|1]=1;
}

void build(int u,int cl,int cr,int k){tag[u]=0;
    if(cl==cr){
        s[u]=a[cl]>>k&1;
        // test("BUILD", u,cl,cr,k,s[u],a[cl]);
        if(!s[u]) mi[u]=cl;
        else mi[u]=n+1;
        
        return;
    }
    int mid=cl+cr>>1;
    build(u<<1,cl,mid,k);
    build(u<<1|1,mid+1,cr,k);
    s[u]=s[u<<1]+s[u<<1|1];
    mi[u]=min(mi[u<<1],mi[u<<1|1]);
    // test("BUILD", u,cl,cr,k,s[u],a[cl]);

}

void modify(int u,int cl,int cr,int l,int r){
    if(l<=cl && cr<=r){
        s[u]=0;
        mi[u]=cl;
        tag[u]=1;
        return;
    }
    pushdown(u,cl,cr);
    int mid=cl+cr>>1;
    if(l<=mid) modify(u<<1,cl,mid,l,r);
    if(mid<r) modify(u<<1|1,mid+1,cr,l,r);
    s[u]=s[u<<1]+s[u<<1|1];
    mi[u]=min(mi[u<<1],mi[u<<1|1]);
}

void change(int u,int cl,int cr,int k,int x){
    if(cl==cr){
        s[u]=x;
        if(!s[u]) mi[u]=cl;
        else mi[u]=n+1;
        return;
    }
    pushdown(u,cl,cr);
    int mid=cl+cr>>1;
    if(k<=mid) change(u<<1,cl,mid,k,x);
    else change(u<<1|1,mid+1,cr,k,x);
    s[u]=s[u<<1]+s[u<<1|1];
    mi[u]=min(mi[u<<1],mi[u<<1|1]);
}

array<int,2> ask(int u,int cl,int cr,int l,int r){
    if(l<=cl && cr<=r){
        // test("ASK", cl, cr, s[u], mi[u]);
        return array<int,2>{s[u],mi[u]};
    }
    pushdown(u,cl,cr);
    int mid=cl+cr>>1,ans=0,a2=n+1;
    if(l<=mid){
        auto [x,y]=ask(u<<1,cl,mid,l,r);
        ans+=x;
        a2=min(a2,y);
    }
    if(mid<r){
        auto [x,y]=ask(u<<1|1,mid+1,cr,l,r);
        ans+=x;
        a2=min(a2,y);
    }

    // test("ASK", cl, cr, ans, a2);
    return {ans,a2};
}

// void dfs(int u,int cl,int cr){
//     // cout<<u<<" : "<<cl<<" "<<cr<<" "<<s[u]<<endl;
//     if(cl==cr) return;
//     int mid=cl+cr>>1;

//     dfs(u<<1,cl,mid);
//     dfs(u<<1|1,mid+1,cr);
// }

void solve() {
    cin>>n>>q;
    for(int i=1;i<=n;++i) cin>>a[i];
    for(int i=1;i<=q;++i){
        cin>>o[i];
        if(o[i]==1) cin>>l[i]>>r[i]>>x[i];
        else if(o[i]==2) cin>>ss[i]>>x[i];
        else cin>>l[i]>>r[i];
    }
    for(int t=63;t>=0;--t){
        build(1,1,n,t);
        for(int i=1;i<=q;++i){
            // test("!!!!", t, i);
            if(o[i]==1){
                if(x[i]>>t&1) continue;
                modify(1,1,n,l[i],r[i]);
            }
            else if(o[i]==2){
                change(1,1,n,ss[i],x[i]>>t&1);
            }
            else{
                auto [ans,mi]=ask(1,1,n,l[i],r[i]);
                // test("QUERY", l[i], r[i], ans, mi);
                if(use[i]){
                    if(r[i]-l[i]+1==ans){
                        res[i]|=1ll<<t;
                    }
                    else if(r[i]-l[i]+1==ans+1){
                        // test("WWW");
                        if(mi==use[i]) res[i]|=1ll<<t;
                    }
                    else{

                    }
                }
                else{
                    if(r[i]-l[i]+1==ans){
                        res[i]|=1ll<<t;
                    }
                    else if(r[i]-l[i]+1==ans+1){
                        use[i]=mi;
                        res[i]|=1ll<<t;
                    }
                    else{

                    }
                }

            }
            // dfs(1,1,n);
        }
        
    }
    for(int i=1;i<=q;++i){
        if(o[i]==3){
            if(l[i]==r[i]) cout<<"0\n";
            else cout<<res[i]<<"\n";
        }
    }
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int t = 1;
    // std::cin >> t;
    while (t--) {
        solve();
    }
}