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
    while(t--){
        int n;
        ll ans = 0;
        string s;
        cin >> n >> s;
        vector<ll> a;
        for(int i = 0, j = n - 1; i < j; ++i, --j){
            if(s[i] == 'R'){
                ans += n - 1 - i;
            }
            else{
                ans += i;
                a.push_back(n - 1 - 2*i);
            }
            if(s[j] == 'L'){
                ans += n - 1 - i;
            }
            else{
                ans += i;
                a.push_back(n - 1 - 2*i);
            }
        }
        if(n % 2 == 1){
            ans += n / 2;
        }
        int k1 = a.size();
        rep(i, n){
            if(i < k1){
                ans += a[i];
            }
            cout << ans << ' ';
        }
        cout << '\n';
    }
    
    return 0;
}