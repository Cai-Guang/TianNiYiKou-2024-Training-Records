#include <bits/stdc++.h>

using namespace std;
#define int long long

// void tst() {
//     std::cerr << std::endl;
// }

// template<typename T, typename... Ts>
// void tst(T t, Ts... ts) {
//     std::cerr << t;
//     tst(ts);
// }

// #define test tst

void solve() {
    int n, k;
    std::cin >> n >> k;

    std::vector<int> a(n + 1);
    std::multiset<int> st;
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i];
        st.insert(a[i]);
    }

    int ans = 0, cnt = 0;

    while (st.size()) {
        int sum = 0;
        int mi = *st.begin();
        st.extract(mi);

        sum += mi;

        if (!st.size()) {
            break;
        }

        if (sum >= k) {
            ans ++;
            continue;
        }

        auto mid_pos = st.lower_bound(k - mi);

        if (mid_pos != st.begin()) {        
            mid_pos --;
            sum += *mid_pos;
            st.extract(*mid_pos);
        }


        if (!st.size()) {
            break;
        }
        
        if (sum >= k) {
            ans ++;
            continue;
        }

        int ma = *std::prev(st.end());
        st.extract(ma);

        if (!st.size()) {
            break;
        }

        ans ++;
    }
   
    std::cout << ans << "\n";
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