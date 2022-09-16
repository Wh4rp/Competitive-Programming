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
    
    int t, n;
    string s1, s2;
    cin >> t;
    while(t--){
        cin >> n >> s1 >> s2;
        rep(i, n){
            if(s1[i] == 'G')
                s1[i] = 'B';
            if(s2[i] == 'G')
                s2[i] = 'B';
        }
        if(s1 == s2)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    
    return 0;
}