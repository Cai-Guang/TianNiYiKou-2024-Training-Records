#include<bits/stdc++.h>
#define FR(i,n) for(int i=0;i<n;++i)
#define eb emplace_back
#define st first
#define nd second
using namespace std;
// namespace R=ranges;
using ll=long long;
using ld=long double;
void sol(){
    int n,k;cin>>n>>k;
    vector<int>stack;
    unordered_map<int,int>restrictions; // TODO: use vector
    restrictions.reserve(n);
    auto upd=[&](int x,int y){if(x<y)restrictions[x]=gcd(restrictions[x],y-x);};
    FR(i,n){
        int x;cin>>x;
        while(!stack.empty()&&x<=stack.back()){
            upd(x,stack.back());
            stack.pop_back();
        }
        if(!stack.empty()){
            upd(stack.back(),x);
        }
        stack.push_back(x);
    }
    // assert(!restrictions.empty());
    auto check=[&](int x){
        if(x<1||k<x)return 0;
        for(auto[shift,value]:restrictions)if(value%(x+shift)!=0)return 0;
        return 1;
    };
    ll ans0=0,ans1=0;
    if(restrictions.empty())
    {
        ans0=k,ans1=(ll)k*(k+1)/2;
    }else{
        int m=restrictions[stack[0]];
        // cerr<<m<<endl;
        for(int i=1;i*i<=m;++i)if(m%i==0){
            if(check(i-stack[0]))++ans0,ans1+=i-stack[0];
            if(i*i<m&&check(m/i-stack[0]))++ans0,ans1+=m/i-stack[0];
        }
    }

    cout<<ans0<<" "<<ans1<<"\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    for(cin>>T;T--;)
        sol();
    return 0;
}
/*
1
4
1 3 1 5
*/
