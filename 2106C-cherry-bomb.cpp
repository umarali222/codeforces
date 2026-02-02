#include <iostream>

// Misconception: complement can exceed k, b[i] cannot

void run_testcase(int *results, int test_num, int n, int k) {
  int *a = new int[n];
  int *b = new int[n];
  int skip = 0;
  int complement = -1;
  int max_of_a = -1;
  int min_of_a = INT_MAX;
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
    if (skip)
      continue;
    if (a[i] > k) {
      skip = 1;
      continue;
    }
    if (a[i] > max_of_a)
      max_of_a = a[i];
    if (a[i] < min_of_a)
      min_of_a = a[i];
  }
  for (int i = 0; i < n; i++) {
    std::cin >> b[i];
    if (skip)
      continue;
    if (b[i] > k) {
      skip = 1;
      continue;
    }
    if (b[i] != -1 && complement == -1) {
      complement = a[i] + b[i];
    } else if (b[i] != -1 && complement != -1) {
      if (complement != a[i] + b[i]) { // no possible ways
	skip = 1;
      }
    }
  }
  if (skip) { // found inconsistency
    results[test_num] = 0;
    delete[] a;
    delete[] b;
    return;
  }

  // Found complement -> check that for each b[i] == -1, 0 <= complement - a[i] <= k (check non-negative because a[i] could be bigger than complement
  // All b[i] == -1 -> complement := max(a[i])
  if (complement != -1) {
    for (int i = 0; i < n; i++) {
      if (complement - a[i] > k || a[i] > complement) {
	results[test_num] = 0;
	return;
      }
    }
    results[test_num] = 1;
  } else {
    int first_value = max_of_a - min_of_a;
    if (first_value > k) {
      results[test_num] = 0;
    } else {
      results[test_num] = k - first_value + 1;
    }
  }
  delete[] a;
  delete[] b;

  // Convince yourself of this algorithm


}

int main(int argc, char **argv) {
  int t;
  std::cin >> t;
  int *results = new int[t];
  for (int i = 0; i < t; i++) {
    int n, k;
    std::cin >> n;
    std::cin >> k;
    run_testcase(results, i, n, k);
  }
  for (int i = 0; i < t; i++) {
    std::cout << results[i] << std::endl;
  }
  return 0;
}