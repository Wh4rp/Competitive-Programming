#include <bits/stdc++.h>
using namespace std;
 
#define endl "\n"
#define repf(i,k,n) for(int i=k; i<n; i++)
#define rep(i,n) for(int i=0; i<n; i++)
typedef long long ll;

ll my_sqrt(double x) {
    ll l = 0, r = x + 10;
    while(l != r) {
        ll mid = (l + r) / 2;
        if(mid * mid <= x)
            l = mid + 1;
        else
            r = mid;
    }
    return l - 1;
}
 
ll contarPuntos(double r) {
    ll ans = 0;
    for(ll i = 1; i <= r; i++) {
        double i2 = i * i;
        double r2 = r * r;
        double r2_i2 = r2 - i2;
        ans += my_sqrt(r2_i2);
    }
    
    return 4LL * ans;
}

// el primero que es verdadero
double bs(ll x) {
    double l = 0, r = 1e6;
    int cont = 100;
    while(l != r && cont != 0) {
        double mid = (l + r) * 0.5;
        if(contarPuntos(mid) > x)
            r = mid;
        else
            l = mid;
        cont--;
    }

    return l;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.setf(ios::fixed);
    cout.precision(10);

    ll x;
    cin >> x;
    
    cout << bs(x) << '\n';
    
    // cout << my_sqrt(25) << '\n';

    return 0;
}