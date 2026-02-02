#include <iostream>

void finish_up(long long s, long long n, long long k) {
  long long candy = (s+2)*(s+1) / 2;
  if (candy - (n - (s+1)) == k) {
    std::cout << n - (s+1) << "\n";
  } else {
    std::cout << n - s << "\n";
  }
}

void solve() {
  long long n, k;
  std::cin >> n;
  std::cin >> k;
  // Let lo and hi represent bounds for # of times
  // she added candy to the box.
  long long lo = 1, hi = n;
  while (lo < hi) {
    if (lo + 1 == hi) {
      finish_up(lo, n, k);
      return;
    }

    long long mid = (lo + hi) / 2;
    long long candy = (mid + 1)*mid / 2;
    if (candy - (n - mid) == k) {
      std::cout << n - mid << "\n";
      return;
    } else if (candy - (n - mid) < k) {
      // she added candy more times.
      lo = mid + 1;
    } else {
      // she added candy less times.
      hi = mid - 1;
    }
  }
  if (lo == hi) {
    std::cout << n - lo << "\n";
  } else {
    // n == 1
    std::cout << 0 << "\n";
  }

  // O(n) is accepted.
/*  long long curr_candy = 0;
  for (long long i = 1; i <= n; ++i) {
    curr_candy += i;
    if (curr_candy - (n - i) == k) {
      std::cout << n - i << "\n";
      return;
    }
  }
*/

}

int main() {
  std::ios::sync_with_stdio(false);
  solve();
}

/*
  let a_i be the candy displacement for move i
  k = 1 + a2 + a3 + ... + an
  then for the subsequence of positive ai, i.e.,
  ai1 > 0, ai2 > 0, ..., we have
  ai1 + 1 == ai2, ai2 + 1 == ai3, ai3 + 1 == ai4, ...
  every other element not in the sequence is -1.

  essentially, the moves can be partitioned into k moves which were adding candy,
  and n - k moves which were eating one candy.

  can you binary search the k?

  or, better?, would be to calculate max possible candy in n moves, then decrease curr_candy 
  one by one until curr_candy == k. Number of decrements is what she actually ate.

  can you do log N? max she could eat is smaller than N, so N is a valid upper bound.
  the min she could eat is 0.

  to verify if she ate N / 2, means she added N - N/2 times, which is a value in could_have.
  so check that could_have[N - N/2] == k.

  alternative approach is to just iterate through could_have until could_have[i] == k. then answer
  is N - i + 1 or N - i.

*/