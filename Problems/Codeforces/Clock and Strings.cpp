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
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        if(b < a) swap(a, b);
        if(d < c) swap(c, d);
        if((a < c && c < d && d < b) || (c < a && a < b && b < d) || (c < d && d < a && a < b) || (a < b && b < c && c < d)){
            cout << "NO\n";
        }
        else{
            cout << "YES\n";
        }
    }

    return 0;
}