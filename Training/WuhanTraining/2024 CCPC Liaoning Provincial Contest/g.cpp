#include <bits/stdc++.h>

using namespace std;

#define int long long

 
void solve() {
    int n,k;
    cin>>n>>k;
    vector<int>a(n+2);
    vector<vector<int>>c(n+1);
    for(int i=1;i<=n;++i){
        cin>>a[i];
        c[a[i]].push_back(i);
    }
    vector<int>l(n+2),r(n+2);
    stack<int>st;
    a[0]=a[n+1]=n+1;
    a[0]++;
    st.push(n+1);
    for(int i=n;i;--i){
        while(a[i]>=a[st.top()]){
            st.pop();
        }
        r[i]=st.top();
        st.push(i);
    }
    while(!st.empty()) st.pop();
    st.push(0);
    for(int i=1;i<=n;++i){
        while(a[i]>=a[st.top()]){
            st.pop();
        }
        l[i]=st.top();
        st.push(i);
    }
    int res=0;
    for(int i=n;i;--i){
        int sz=c[i].size();
        if(sz<k) continue;
        for(int j=0;j+k-1<sz;++j){
            int st=c[i][j],ed=c[i][j+k-1];
            if(l[st]==l[ed] && r[st]==r[ed]){    
                int cl=(j==0?max(0ll,l[st]):max(c[i][j-1],l[st]))+1;
                int cr=r[ed]-1;
                res+=(st-cl+1)*(cr-ed+1);
            }
        }
    }
    cout<<res<<"\n";
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