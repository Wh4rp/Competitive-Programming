#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)
#define rep_(i, k, n) for (int i = k; i < n; ++i)
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.setf(ios::fixed);
    cout.precision(10);

    int t; 
    cin >> t;
    while (t--) {
        vector<int> v(26);
        int count = 0, ans = 0;
        string s;
        cin >> s;
        int n = s.length();
        rep(i, n){
            count++;
            v[s[i]-97]++;
            if(v[s[i]-97] == 2){
                ans += count - 2;
                count = 0;
                v.clear();
                v.resize(26, 0);
            }
        }
        ans += count;
        cout << ans << '\n';
    }

    return 0;
}