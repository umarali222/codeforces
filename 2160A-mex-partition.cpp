
#include <iostream>
#include <limits>
#include <algorithm>
#include <vector>

long long mex(std::vector<long long> &A) {
  long long i = 0, j = 1;
  while (j < A.size()) {
    if (A[j] - A[i] > 1) {
      return A[i] + 1;
    }
    ++i; ++j;
  }
  return A[i] + 1;
}

void solve() {
  long long n;
  std::cin >> n;
  std::vector<long long> A(n, 0);
  long long min = std::numeric_limits<long long>::max();
  for (long long i = 0; i < n; ++i) {
    std::cin >> A[i];
    min = std::min(min, A[i]);
  }
  if (min != 0) {
    std::cout << 0 << "\n";
    return;
  }
  std::sort(A.begin(), A.end());
  std::cout << mex(A) << "\n";
}

int main() {
  std::ios::sync_with_stdio(false);
  long long t;
  std::cin >> t;
  while (t--)
    solve();
}
