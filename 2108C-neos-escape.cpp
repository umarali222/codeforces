#include <iostream>

 long long solve(long long *a, int n) {
    if (n == 1) {
        return 1;
    }
    long long count = 0;
    bool descending, has_strictly_increased, has_strictly_decreased;
    if (a[0] > a[1]) {
        ++count;
        has_strictly_increased = false;
        has_strictly_decreased = true;
    } else if (a[0] < a[1]) {
        has_strictly_increased = true;
        has_strictly_decreased = false;
    } else {
        has_strictly_increased = has_strictly_decreased = false;
    }
    long long i = 1;
    while (1) {
        if (i + 1 == n && a[i] > a[i - 1]) {
            ++count;
            break;
        } else if (i + 1 == n && count == 0) {
            ++count;
            break;
        } else if (i + 1 == n && has_strictly_increased) {
            ++count;
            break;
        } else if (i + 1 == n) {
            break;
        }

        if (a[i] < a[i + 1] && !has_strictly_increased) {
            has_strictly_increased = true;
            has_strictly_decreased = false;
            ++i;
        } else if (a[i] > a[i + 1] && !has_strictly_increased && !has_strictly_decreased) {
            ++count;
            ++i;
            has_strictly_decreased = true;
            has_strictly_increased = false;
        } else if (a[i] > a[i + 1] && has_strictly_increased) {
            ++count;
            ++i;
            has_strictly_increased = false;
            has_strictly_decreased = true;
        } else {
            ++i;
        }
    }
    return count;
}

int main(int argc, char **argv) {
    long long t;
    std::cin >> t;
    long long *ans = new long long[t];
    for (long long i = 0; i < t; ++i) {
        long long n;
        std::cin >> n;
        long long *a = new long long[n];
        for (long long j = 0; j < n; ++j) {
            std::cin >> a[j];
        }
        ans[i] = solve(a, n);
        delete[] a;
    }
    for (long long i = 0; i < t; ++i) {
        std::cout << ans[i] << std::endl;
    }
    delete[] ans;
    return 0;
}