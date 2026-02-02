#include <bits/stdc++.h>
using namespace std;

using ll = long long;

template <typename T>
using v = vector<T>;

void solve() {
  ll n;
  cin >>n;
  ll upper = numeric_limits<ll>::min();
  ll lower = numeric_limits<ll>::max();
  for (ll i = 0; i < n; ++i) {
    ll next;
    cin >>next;
    lower = min(next, lower);
    upper = max(next, upper);
  }
  ll x;
  cin >>x;
  if (lower <= x && x <= upper)
    cout << "YES\n";
  else
    cout << "NO\n";
}

int main() {
  ll T;
  cin >>T;
  while (T--)
    solve();
}