#pragma comment(linker, "/STACK:1024000000,1024000000")
/*
    Author: elfness@UESTC
*/
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
#define PB push_back
#define fi first
#define se second
#define MP make_pair
const int oo = 1000000000;
const int P = 1000000007;
const int V = 200100;
int _, n, k, a[V];

int main() {
	scanf("%d", &_);
	while (_--) {
		scanf("%d%d", &n, &k);
		for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
		int mi = oo;
		for (int i = 0; i < n; ++i) mi = min(mi, a[i]);
		int gd = 0;
		for (int i = 1; i < n; ++i) gd = __gcd(gd, abs(a[i] - a[i - 1]));
		if (gd == 0) {
			printf("%d %lld\n", k, (LL) k * (k + 1) / 2);
			continue;
		}
		vector<int> fac;
		for (int i = 1; i * i <= gd; ++i) {
			if (gd % i == 0) {
				fac.PB(i);
				if (i * i != gd) fac.PB(gd / i);
			}
		}
		vector<int> delta, ok;
		for (auto f : fac) if (f > mi && f - mi <= k) delta.PB(f - mi), ok.PB(1);
		for (int i = 1; i < n; ++i) {
            for (int j = 0; j < delta.size(); ++j) {
                int u = a[i] + delta[j];
                int v = a[i - 1] + delta[j];
                if (u % v != 0 && v % u != 0) ok[j] = 0;
            }
		}
		int cnt = 0;
		LL sum = 0;
		for (int i = 0; i < delta.size(); ++i) if (ok[i]) ++cnt, sum += delta[i];
		printf("%d %lld\n", cnt, sum);
	}
    return 0;
}

/*
4
5 4
7 79 1 7 1
2 1000000000
1 2
1 100
1000000000
3 10
1 3 5
*/
