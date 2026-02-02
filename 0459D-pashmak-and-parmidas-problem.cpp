#include <bits/stdc++.h>
using namespace std;

using ll = long long;

template <typename T>
using v = vector<T>;

template <typename K, typename V>
using m = unordered_map<K, V>;

// segment tree representing array of counts, where the ith element is the number of times we've seen i as count
// query(l, r) is total number of times we've seen l <= ri <= r
v<int> times_seen_count;

// increment, since we've seen count_seen
void update(int i, int count_seen, int l, int r) {
  if (l == r) {
    times_seen_count[i]++;
  } else {
    int mid = (l + r)/2;
    if (count_seen <= mid)
      update(2*i, count_seen, l, mid);
    else
      update(2*i + 1, count_seen, mid+1, r);
    times_seen_count[i] = times_seen_count[2*i] + times_seen_count[2*i + 1];
  }
}

int query(int i, int ql, int qr, int l, int r) {
  if (ql > qr)
    return 0;

  if (ql == l && qr == r)
    return times_seen_count[i];

  int mid = (l + r)/2;
  int lcounts = query(2*i, ql, min(mid, qr), l, mid);
  int rcounts = query(2*i + 1, max(mid+1, ql), qr, mid+1, r);
  return lcounts + rcounts;
}

void solve() {
  int n;
  cin >> n;

  // largest count we could see is n (we could see it one time), that is largest index
  times_seen_count = v<int>(4*(n + 1));

  v<int> a(n);
  m<int, int> count_to_left;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    count_to_left[a[i]]++;
  }

  ll result = 0;
  m<int, int> count_to_right;
  for (int i = n - 1; i >= 0; --i) {
    // how many times have we seen a count to the right strictly smaller than the count of a[i] to the left
    result += query(1, 0, count_to_left[a[i]] - 1, 0, n + 1);
    count_to_right[a[i]]++;
    update(1, count_to_right[a[i]], 0, n + 1);
    count_to_left[a[i]]--;
  }
  cout << result << "\n";
}

int main() {
  solve();
}