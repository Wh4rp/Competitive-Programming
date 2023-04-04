#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)
#define rep_(i, k, n) for (int i = k; i < n; ++i)
using ll = long long;

ll memo[50];

ll fibonacci(int n) {
    if(n == -1)
        return 0;
    if (n == 0 || n == 1) {
        return n;
    }
    if (memo[n] != -1) {
        return memo[n];
    }
    return memo[n] = fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.setf(ios::fixed);
    cout.precision(10);

    rep(i, 50){
        memo[i] = -1;
    }

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        ll f_n = fibonacci(n);
        ll f_n_1 = fibonacci(n + 1);
        int x, y;
        cin >> x >> y;
        bool findx = false;
        bool findy = false;

        rep_(i, -1, n){
            ll f_i = fibonacci(i);
            if(f_i == x){
                findx = true;
            }
        }
        rep_(i, -1, n){
            ll f_i = fibonacci(i);
            if(f_i == f_n - x){
                findx = true;
            }
        }
        rep_(i, -1, n){
            ll f_i = fibonacci(i);
            if(f_i == y){
                findy = true;
            }
        }
        rep_(i, -1, n){
            ll f_i = fibonacci(i);
            if(f_i == f_n_1 - y){
                findy = true;
            }
        }
        if(findx && findy){
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }
    }
    

    return 0;
}