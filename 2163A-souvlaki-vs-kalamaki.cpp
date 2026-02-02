/*
    ~umarali22

    we can simulate, but it is left to decide how Souvlaki should order before
    obs: kalamaki will always try to invert sorted elements. kalamaki wins if he inverts once?
    yes, so only way kalamaki can lose is if he gets duplicate numbers each turn
    so sort a, then go for each even index, check if ai == ai+1
    sps at some even index in sorted(a), ai != ai+1, can souvlaki fix it? if he moves a prev
    equal elem, whatever fills that gap is unfixable.

    1 5 1 5 1 -> 1 1 1 5 5
*/

#include <bits/stdc++.h>
using namespace std;

template <typename T>
using v = vector<T>;

void solve() {
  int n;
  cin >>n;
  v<int> a(n);
  for (int i =0; i<n; ++i) cin >>a[i];
  sort(a.begin(), a.end());
  for (int i =0; i+1<n; ++i) {
    if ((i+1) % 2 == 0 && a[i] != a[i+1]) {
      cout << "NO\n";
      return;
    }
  }
  cout << "YES\n";
}

int main() {
  int t;
  cin >>t;
  while (t--)
    solve();
}