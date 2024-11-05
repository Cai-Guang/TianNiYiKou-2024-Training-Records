#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve() {
    int A, B, C, X, Y, D;
    std::cin >> A >> B >> C >> X >> Y >> D;

    int ans = 0;

    if (D < X)
        ans = A;
    else if (D < X + Y)
        ans = A + B * (D - X);
    else
        ans = A + B * Y + (D - X - Y) * C;


    // # AAAAAAAAAA

    int cntA = (D + X - 1) / X;
    ans = min(ans, cntA * A);

    // # #ABABABABABABABCCC

    int cntAB = D / (X + Y);
    int restAB = D - cntAB * (X + Y);
    if (cntAB >= 1)
        ans = min(ans, cntAB * (A + Y * B) + restAB * C);

    // # AAAAAAAA use B, C to fill the rest

    cntA = D / X;
    int restA = D - cntA * X;
    if (restA <= Y * cntA)
        ans = min(ans, cntA * A + restA * B);

    // # # #AAAAAAABCCCCCC

    if (restA > Y)
        ans = min(ans, cntA * X + B * Y + (restA - Y) * C);


    // #ABABABAb
    if (X < restAB)
        ans = min(ans, cntAB * (A + B * Y) + (restAB - X) * B + A);
    else
        ans = min(ans, cntAB * (A + B * Y) + A);

    std::cout << ans << '\n';
}



signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int t = 1;
    std::cin >> t;
    while (t--) {
        solve();
    }
}