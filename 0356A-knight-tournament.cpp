
#include <bits/stdc++.h>
using std::cout, std::cin, std::max, std::min;

template <typename T>
using v = std::vector<T>;

template <typename K, typename V>
using m = std::map<K, V>;

v<int> in_tree;
m<int, int> conquered; // m[a] == b -> b conquered a

// set all in knights in [ql, qr] to out, and map each lost knight to small_winner
void update(int i, int small_winner, int ql, int qr, int l, int r) {
  if (ql > qr)
    return;

  if (in_tree[i] == 0) {
    // all knights in [l, r] are conquered
    return;
  }

  if (l == r) {
    if (small_winner - 1 != l) {
      // this knight is out
      conquered[l] = small_winner;
      in_tree[i] = 0;
    }
    return;
  }

  int mid = (l + r)/2;
  update(2*i, small_winner, ql, min(mid, qr), l, mid);
  update(2*i + 1, small_winner, max(mid+1, ql), qr, mid+1, r);
  if (in_tree[2*i] == 0 && in_tree[2*i + 1] == 0) // all knights lost in this interval
    in_tree[i] = 0;
}

void solve() {
  int n, m;
  cin >> n >> m;

  // all knights are in
  in_tree = v<int>(4*n, 1);

  int winner;
  for (int i = 0; i < m; ++i) {
    int l, r, x;
    cin >> l >> r >> x;
    winner = x;
    update(1, x, l-1, r-1, 0, n-1);
  }
  conquered[winner - 1] = 0;

  for (auto &[knight, conquered_by] : conquered)
    cout << conquered_by << " ";
  cout << "\n";
}

int main() {
  solve();
}
