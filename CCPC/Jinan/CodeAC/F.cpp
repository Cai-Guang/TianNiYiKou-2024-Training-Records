#include <bits/stdc++.h>

using namespace std;

#define int long long

using i64 = long long;

void solve() {
    int n, m;
    std::cin >> m >> n;
    for(int i=4;i<=4;++i){
        // cout<<i<<" : "<<endl;
int res=0;
        for(int j=i+1;j<=m;++j){
            for(int k=j+1;k<=m;++k){
                for(int x=k+1;x<=m;++x){
                    if(__gcd(i,__gcd(j,__gcd(k,x)))!=i){
                        res+=4;
                        cout<<i<<" "<<j<<" "<<k<<" "<<x<<endl;
                    }
                    else if(__gcd(j,__gcd(k,x))!=j){
                        res+=3;
                        cout<<j<<" "<<k<<" "<<x<<endl;
                    }
                    else if(__gcd(k,x)!=k){
                        res+=2;
                        cout<<k<<" "<<x<<endl;
                    }

                }
            }
        }
        cout<<res<<"\n";
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

// 391
// 428
// 257
// 149
// 80
// 40
// 16
// 4

// 351
// 332
// 224
// 140
// 80
// 40
// 16
// 4

// 11 4
// 4 3 140
// 8 2 9
// 149