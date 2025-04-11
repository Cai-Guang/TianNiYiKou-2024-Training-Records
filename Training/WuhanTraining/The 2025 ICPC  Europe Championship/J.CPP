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
   int ans=0;
   string s;
   cin>>s;
   for(int i=0;i<n;++i){
      ans+=(s[i]=='W');
   }
   if(ans&1) cout<<"NO\n";
   else{
     int s3=0;
     for(int i=2*n-1;i>=0;--i){
        if(s[i]=='W') break;
        else s3++;
     }
    int s2=0;
     for(int i=0;i<n;++i){
        if(s[i]=='W') s2++;
        else break;
     }
     if(s2<ans/2){
        cout<<"NO\n";
        return;
     }
     if(n-ans/2+s3>=n) cout<<"YES\n";
     else cout<<"NO\n";
   }
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    std::cin >> t;

    while (t --) {
        solve();
    }
}