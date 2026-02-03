#include <iostream>
#include <vector>
 
void solve() {
  long long n, m;
  std::cin >> n; std::cin >> m;
  std::vector<long long> nums(m, 0);
  long long max = 1;
  for (long long i = 0; i < m; ++i) {
    std::cin >> nums[i];
    max = std::max(max, nums[i]);
  }
 
  for (long long i = 0; i < m - 1; ++i) {
    if (nums[i] >= nums[i + 1]) {
      std::cout << 1 << "\n";
      return;
    }
  }
  std::cout << n - max + 1 << "\n";
}
 
int main() {
  std::ios::sync_with_stdio(false);
  long long t; std::cin >> t;
  while (t--)
    solve();
}