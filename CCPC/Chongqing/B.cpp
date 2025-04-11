#include <bits/stdc++.h>

using namespace std;

#define int long long
#ifndef Cai_Guang
#define debug //
#define test //
#endif

// 解决问题的函数
void solve() {
    // 最大PP值
    int ppmax;
    std::cin >> ppmax;
    
    // 输入参数，分别代表不同的权重和数量
    int a, b, c, d, e, f;
    std::cin >> a >> b >> c >> d >> e >> f;
    
    // 计算准确率，基于输入的权重和数量
    int acc = std::round(10000. * 1. * (300 * a + 300 * b + 200 * c + 100 * d + 50 * e) / (300 * (a + b + c + d + e + f)));
    std::cout << acc / 100. << "% ";
    
    // 计算PP值，基于准确率和最大PP值
    long double pp = std::max(0., 1. * (320 * a + 300 * b + 200 * c + 100 * d + 50 * e) / (320 * (a + b + c + d + e + f)) - 0.8);
    
    pp *= 5 * ppmax;
    std::cout << (int)std::round(pp + 1e-8) << '\n';
}

// 主函数
signed main() {
  // 同步C++的输入输出与C的输入输出，提高输入输出效率
  std::ios::sync_with_stdio(false);
  // 解除cin与stdin的绑定，进一步提高输入效率
  std::cin.tie(nullptr);
  // 解除cout与stdout的绑定，进一步提高输出效率
  std::cout.tie(nullptr);

#ifdef Cai_Guang
  // 在本地测试时，使用本地文件作为输入
  //freopen("1.in", "r", stdin);
  localTest = true;
#endif
  // 设置浮点数输出格式，保留两位小数
  std::cout << std::fixed << std::setprecision(2);
  
  // 初始化测试用例数量
  int t = 1;
  // 读取测试用例数量
  std::cin >> t;
  // 循环处理每个测试用例
  while(t--) {
      // 调用solve函数处理当前测试用例
      solve();
  }
}