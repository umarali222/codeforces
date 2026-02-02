
#include <iostream>

void simulate(long long query, std::string &s) {
    long long minutes = 0;
    while (query) {
        switch (s[minutes % s.size()]) {
          case 'A':
            --query;
            break;
          case 'B':
            query /= 2;
            break;
        }
 
        ++minutes;
    }
 
    std::cout << minutes << "\n";
}
 
void solve() {
  long long n, q;
  std::string s;
  std::cin >> n >> q >> s;
  bool has_log = false;
  for (auto &machine : s)
    if (machine == 'B')
      has_log = true;
 
  for (long long i = 0; i < q; ++i) {
    long long query;
    std::cin >> query;

    // if has_log, we can simulate, otherwise do constant evaluation
    if (has_log)
      simulate(query, s);
    else {
      std::cout << query << "\n";
    }
  }
}
 
int main() {
  long long t;
  std::cin >> t;
  while (t--)
    solve();
}
