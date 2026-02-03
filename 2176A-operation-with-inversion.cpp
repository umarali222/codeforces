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
 
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
 
        int operations = 0;
 
        // We greedily remove elements that are part of an inversion
        while (true) {
            bool removed = false;
            for (int i = 0; i + 1 < (int)a.size(); i++) {
                if (a[i] > a[i + 1]) {
                    a.erase(a.begin() + i + 1);
                    operations++;
                    removed = true;
                    break;
                }
            }
            if (!removed) break;
        }
 
        cout << operations << '\n';
    }
    return 0;
}