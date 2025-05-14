#include <bits/stdc++.h>
using namespace std;
 
#define endl "\n"
#define repf(i,k,n) for(int i=k; i<n; i++)
#define rep(i,n) for(int i=0; i<n; i++)
typedef long long ll;
 
ll contarPuntos(long double r) {
    ll ans = 0;

    for(ll i = 1; i <= r; i++) {
        ans += floor(sqrt(r * r - i * i));
    }
    
    return 4LL * ans;
}
 
// el primero que es verdadero
long double bs(ll x) {
    long double l = 0, r = 1e6;
    int cont = 100;
    while(l != r && cont != 0) {
        long double mid = (l + r) / 2;
        if(contarPuntos(mid) >= x)
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
    
    // cout << contarPuntos(1.5) << '\n';

    return 0;
}