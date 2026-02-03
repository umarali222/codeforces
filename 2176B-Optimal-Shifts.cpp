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
        string s;
        cin >> s;
 
        vector<int> ones;
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') ones.push_back(i);
        }
 
        // If already all ones
        if ((int)ones.size() == n) {
            cout << 0 << '\n';
            continue;
        }
 
        int maxGap = 0;
        int k = ones.size();
 
        for (int i = 0; i < k; i++) {
            int next = ones[(i + 1) % k];
            int cur = ones[i];
            int gap;
            if (i + 1 < k)
                gap = next - cur - 1;
            else
                gap = (n - cur - 1) + ones[0];
 
            maxGap = max(maxGap, gap);
        }
 
        cout << maxGap << '\n';
    }
    return 0;
}