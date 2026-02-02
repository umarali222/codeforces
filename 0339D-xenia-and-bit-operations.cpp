/*

	how to perform query using the segment tree?
	leaves store the original sequence
	for other levels, map node to OR vs XOR alternating up from children

	how to perform updates? just use regular assignment with segment tree

*/
#include <iostream>
#include <vector>
#include <unordered_set>
using std::cout, std::cin;

using ll = long long;

template <typename T>
using v = std::vector<T>;

template <typename T>
using s = std::unordered_set<T>;

v<ll> or_table;
s<ll> xors;

bool build(v<ll> &a, ll i, ll l, ll r) {
  if (l == r) {
    or_table[i] = a[l];
    return true;
  }

  ll mid = (l + r)/2;
  bool lres = build(a, 2*i, l, mid);
  bool rres = build(a, 2*i + 1, mid+1, r);
  if (lres) {
    // we use bitwise OR
    or_table[i] = or_table[2*i] | or_table[2*i + 1];
    return false;
  }

  // we use bitwise XOR
  or_table[i] = or_table[2*i] ^ or_table[2*i + 1];
  xors.insert(i);
  return true;
}

// query for v (it should only ever be the full range)
ll query() {
  return or_table[1];
}

// query b, p
void update(ll i, ll idx, ll val, ll l, ll r) {
  if (l == r) {
    or_table[i] = val;
    return;
  }

  ll mid = (l + r)/2;
  if (idx <= mid)
    update(2*i, idx, val, l, mid);
  else
    update(2*i + 1, idx, val, mid+1, r);

  // update by OR or XOR
  if (xors.contains(i)) {
    or_table[i] = or_table[2*i] ^ or_table[2*i + 1];
  } else {
    or_table[i] = or_table[2*i] | or_table[2*i + 1];
  }
}

void solve() {
  ll n, m;
  cin >> n >> m;

  v<ll> a(1 << n);
  or_table = v<ll>(4*a.size());

  for (ll i = 0; i < a.size(); ++i) {
    cin >> a[i];
  }

  build(a, 1, 0, a.size() - 1);

  // run queries and updates
  for (ll i = 0; i < m; ++i) {
    ll p, b;
    cin >> p >> b;
    update(1, p - 1, b, 0, a.size() - 1);
    cout << query() << "\n";
  }
}

int main() {
  solve();
}