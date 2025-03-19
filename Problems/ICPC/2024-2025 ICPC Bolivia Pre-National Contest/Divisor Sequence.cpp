#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)
#define rep_(i, k, n) for (int i = k; i < n; ++i)
using ll = long long;

ll sum_divisors(ll n) {
    ll sum = 1;
    for (ll i = 2; i * i <= n; i++) {
        if (n % i == 0){
            sum += i;
            if(i * i != n)
                sum += n / i;
            // cout << i << '\n';
            // cout << n / i << '\n';
        }
    }

    return sum;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.setf(ios::fixed);
    cout.precision(10);

    ll t;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        if(n == 1) {
            cout << "1 complicado\n";
            continue;
        }
        cout << n << ' ';
        ll m = sum_divisors(n);
        // cout << m << '\n';
        if(n == m) {
            cout << "perfecto\n";
        } else {
            ll l = sum_divisors(m);
            if(!(l == n || n < m)){
                cout << "complicado\n";
            }
            else {
                if(l == n)
                    cout << "romantico ";
                if(n < m)
                    cout << "abundante ";
                cout << '\n';
            }

        }
    }

    return 0;
}