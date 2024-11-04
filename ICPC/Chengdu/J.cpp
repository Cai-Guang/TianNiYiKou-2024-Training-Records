#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
#define int long long

void solve() {
    int n, m, q;
    std::cin >> n >> m >> q;
    std::set<int> st;
    int finish = 0;
    std::vector<int> score(m + 1);

    int nowLevel = -1;
    for (int i = 1; i <= q; i++) {
        int o;
        std::cin >> o;
        if (o == 1) {
            int x;
            std::cin >> x;
            nowLevel = x;
            st.clear();
            finish = 0;
        } else if (o == 2) {
            int id, x;
            std::cin >> id >> x;
            if (st.count(id)) {
                continue;
            }
            if (x != nowLevel) {
                continue;
            }

            st.insert(id);
            finish++;
            score[id] += m - finish + 1;
        } else if (o == 3) {
            int id, x;
            std::cin >> id >> x;
            if (x != nowLevel) continue;
            if (st.count(id)) {
                continue;
            }
            st.insert(id);
        } else {
            assert(0);
        }
    }

    std::vector<std::pair<int, int> > ans;
    for (int i = 1; i <= m; i++) {
        ans.push_back({score[i], -i});
    }
    std::sort(ans.begin(), ans.end(), std::greater());
    for (auto [x, y] : ans) {
        std::cout << -y << " " << x << "\n";
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