#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
 
        int ways = 0;
        // cows = x, chickens = y
        // 4x + 2y = n  => y = (n - 4x) / 2 >= 0
        for (int cows = 0; 4 * cows <= n; cows++) {
            int rem = n - 4 * cows;
            if (rem % 2 == 0) {
                ways++;
            }
        }
 
        cout << ways << '\n';
    }
    return 0;
}