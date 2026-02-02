#include <iostream>
#include <vector>

void solve() {
  long long n;
  std::cin >> n;
  long long hao = 0;
  while (n - 2 > 0) {
    ++hao;
    n -= 2;
  } // n - 2 / 2 + (n - 2) % 2

  std::cout << hao << "\n";
}

int main() {
  long long t;
  std::cin >> t;
  while (t--)
    solve();
}

/*

  there is recursive structure to this problem, in that the best
  hao can eat for k pizzas is however many he eats today + best[k - #].

  base case: best[

  1 1 6
  1 1 4
  1 1 2

  1 1 7
  1 1 5
  1 1 3
  1 1 1

*/