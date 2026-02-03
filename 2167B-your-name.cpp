#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int q;
    cin >> q;
    while (q--) {
        int n;
        cin >> n;
 
        string s, t;
        cin >> s >> t;
 
        vector<int> cnt1(26, 0), cnt2(26, 0);
 
        for (char c : s) cnt1[c - 'a']++;
        for (char c : t) cnt2[c - 'a']++;
 
        if (cnt1 == cnt2)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}