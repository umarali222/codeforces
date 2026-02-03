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
 
        vector<long long> a(n);
        bool hasOdd = false, hasEven = false;
 
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (a[i] % 2 == 0) hasEven = true;
            else hasOdd = true;
        }
 
        if (hasOdd && hasEven) {
            sort(a.begin(), a.end());
        }
 
        for (int i = 0; i < n; i++) {
            cout << a[i] << " ";
        }
        cout << '\n';
    }
    return 0;
}