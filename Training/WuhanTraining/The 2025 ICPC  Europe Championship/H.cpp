#include <bits/stdc++.h>

using namespace std;
#define int long long

void tst() {
    std::cerr << std::endl;
}

template<typename T, typename... Ts>
void tst(T t, Ts... ts) {
    std::cerr << t;
    tst(ts...);
}

#define test tst

void solve() {
    int n;
    cin>>n;
    int a,b;
    cin>>a>>b;
    vector<array<int,2>>d(n-1);
    int ans=0;
    for(int i=0;i<n-1;++i){
        int x;
        cin>>x;
        d[i]={x,i};
        ans+=x;
    }
    sort(d.begin(),d.end());
    int dif=ans-a-b;
    if(dif<0 || (dif&1)){
        cout<<"NO\n";
        return;
    }
    dif/=2;
    vector<int>vx(n-1),vy(n-1);
    int bg=lower_bound(d.begin(),d.end(),(array<int,2>){dif,0})-d.begin();
    auto [t,z]=d[bg];
    int rem=t-dif;
    bool bl=0;
    if(rem<=a){
        bl=1;
        vy[z]=dif;
    }
    else if(rem<=b){
        bl=1;
        vx[z]=dif;
    }
    else{
        int cur=1;
        for(int i=bg-1;i>=0;--i){
            auto [tt,zz]=d[i];
            if(tt>=dif){
                if(cur==1){
                    vx[zz]=dif;
                    dif=0;
                    break;
                }
                else{
                    vy[zz]=dif;
                    dif=0;
                    break;
                }
            }
            else{
                if(cur==1) vx[zz]=tt;
                else vy[zz]=tt;
                dif-=tt;
            }
            cur^=1;
        }
        if(!dif) bl=1;
    }
    if(!bl) cout<<"NO\n";
    else{
        cout<<"YES\n";
        sort(d.begin(),d.end(),[&](array<int,2>x,array<int,2>y){
            return x[1]<y[1];
        });
        int lst=-1;
        for(int i=n-1;i>=0;--i){
            if(vx[i]){
                lst=0;
                break;
            }
            else if(vy[i]){
                lst=1;
                break;
            }
        }
        int cx=0,cy=0;
        cout<<cx<<" "<<cy<<"\n";
        for(int i=0;i<n-1;++i){
            int s=d[i][0];
            if(vx[i]){
                cx-=vx[i];
                s-=vx[i];
            }
            if(vy[i]){
                cy-=vy[i];
                s-=vy[i];
            }
            if(lst==0){
                if(cx+s<=a && !vx[i]) cx+=s;
                else if(!vx[i]){
                    cy+=s-a+cx;
                    cx=a;
                }
                else cy+=s;
                cout<<cx<<" "<<cy<<"\n";                
            }
            else{
                if(cy+s<=b && !vy[i]) cy+=s;
                else if(!vy[i]){
                    cx+=s-b+cy;
                    cy=b;
                }
                else cx+=s;
                cout<<cx<<" "<<cy<<"\n";                  
            }

        }
    }
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