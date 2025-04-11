#include <bits/stdc++.h>

using namespace std;

#define int long long

struct CutEdges {
    int n;
    int idx = 0;
    vector<int> low, dfn, fa, instk;
    vector<int> head, nxt, to, sz;
    vector<int> b;
    int iddx = 1;
    vector<pair<int,int>> bridge;
    std::vector<std::vector<int>> scc;
    std::stack<int> stk;
    CutEdges(int n, int m) : low(n + 1), dfn(n + 1), fa(n + 1),
    head(n + 1), to(2 * m + 4), nxt(2 * m + 4), b(2 * m + 4) {
        this->n = n;
        sz.assign(n + 1, 1);
    }
    void addEdge(int x, int y) {
        nxt[++iddx] = head[x];
        head[x] = iddx;
        to[iddx] = y;
    }
    std::pair<std::vector<std::vector<int>>, vector<pair<int, int>>> work() {
        for (int i = 1; i <= n; i++) {
            if (!dfn[i]) tarjan(i, 0);
        }
        return {scc, bridge};
    }
    void tarjan(int x, int e_in) {
        dfn[x] = low[x] = ++idx;
        instk[x] = 1;
        stk.push(x);
        for(int i = head[x]; i; i = nxt[i]) {
            int y = to[i];
            if(!dfn[y]) {
                tarjan(y, i);
                low[x] = min(low[x], low[y]);
            } else if (instk[y]) {
                low[x] = min(low[x], dfn[y]);
            }
        }
        if (dfn[x] == low[x]) {
            std::vector<int> ans;
            while (stk.top() != x) {
                instk[stk.top()] = 0;
                ans.push_back(stk.top());
                stk.pop();
            }
            instk[stk.top()] = 0;
            ans.push_back(stk.top());
            stk.pop();
            scc.push_back(ans);
        }
    }
  
};

void solve() {
    int n;
    std::cin >> n;

    int N = 50;
    int M = N * N;

    std::vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i];
    }

    std::vector<int> have(N + 10, (1ll << (N + 10)) - 1);
    for (int i = 0; i <= N; i++) {
        for (int j = 1; j <= n; j++) {
            if (a[j] >> i & 1) {
                have[i] &= a[j];
            }
        }
    }

    std::vector<std::vector<int>> G(N + 10, std::vector<int>());
    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= N; j++) {
            if (i == j) {
                continue;
            }
            if (have[i] >> j & 1) {
                G[i].push_back(j);
            }
        }
    }

    std::vector<int> low(N + 1), dfn(N + 1), instack(N + 1);
    int idx = 0;
    std::vector<std::vector<int>> scc;
    std::stack<int> stk;
    auto dfs = [&](auto &&self, int x) -> void {
        dfn[x] = low[x] = ++idx;
        stk.push(x);
        instack[x] = 1;
        for (auto y : G[x]) {
            if (!dfn[y]) {
                self(self, y);
                low[x] = std::min(low[x], low[y]);
            } else if (instack[y]) {
                low[x] = std::min(low[x], dfn[y]);
            }
        }
        if (low[x] == dfn[x]) {
            std::vector<int> ans;
            while (stk.top() != x) {
                ans.push_back(stk.top());
                instack[stk.top()] = 0;
                stk.pop();
            }
            ans.push_back(x);
            stk.pop();
            instack[x] = 0;
            scc.push_back(ans);
        }
    };

    for (int i = 0; i <= N; i++) {
        if (!dfn[i]) dfs(dfs, i);
    }

    for (auto x : scc) {
        for (auto y : x) {
            std::cout << y << ' ';
        } std::cout << '\n';
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