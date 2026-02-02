
#include<iostream>

void run_testcase(int n, unsigned long long *out) {
    // Array
    unsigned long long *a = new unsigned long long[n];
    // Memo tables
    unsigned long long *sum_to_end = new unsigned long long[n];  // construct after reading on pass #2 (last pass)
    int *max_till_here = new int[n];  // construct while reading -- gives index of max
    std::cin >> a[0];  // n >= 1
    max_till_here[0] = 0;
    for (int i = 1; i < n; ++i) {
        unsigned long long next;
        std::cin >> next;
        a[i] = next;
        max_till_here[i] = (a[max_till_here[i - 1]] > next) ? max_till_here[i - 1] : i;
    }
    sum_to_end[n - 1] = a[n - 1];  // n >= 1
    for (int i = n - 2; i >= 0; --i) {
        sum_to_end[i] = a[i] + sum_to_end[i + 1];
    }
    for (int i = n - 1; i >= 0; --i) {
        if (a[max_till_here[i]] > a[i]) {
            out[n - i - 1] = sum_to_end[i] - a[i] + a[max_till_here[i]];
        } else {
            out[n - i - 1] = sum_to_end[i];
        }
    }
    delete[] a;
    delete[] max_till_here;
    delete[] sum_to_end;
}

int main() {
    int t;
    std::cin >> t;
    unsigned long long **out = new unsigned long long *[t];
    int *ns = new int[t];
    for (int i = 0; i < t; ++i) {
        int n;
        std::cin >> n;
        ns[i] = n;
        out[i] = new unsigned long long[n];
        run_testcase(n, out[i]);
    }
    for (int i = 0; i < t; ++i) {
        unsigned long long *o = out[i];
        for (int j = 0; j < ns[i] - 1; ++j) {
            std::cout << o[j] << " ";
        }
        std::cout << o[ns[i] - 1] << std::endl;
        delete[] out[i];
    }
    delete[] out;
    return 0;
}