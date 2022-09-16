#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)
#define rep_(i, k, n) for (int i = k; i < n; ++i)
using ll = long long;
    
string sortString(string s){
    sort(s.begin(), s.end());
    return s;
}
    
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.setf(ios::fixed);
    cout.precision(10);
    
    int t;
    cin >> t;
    string aux = sortString("Timur"), s;
    
    while(t--){
        int n; 
        cin >> n >> s;
        if(aux == sortString(s))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    
    return 0;
}