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
        int l, r;
        cin >> l >> r;
        if(r <= 3){
            cout << -1 << '\n';
        }
        else if(r - l >= 1){
            if(r % 2 == 0){
                cout << r / 2 << ' ' << r / 2 << '\n';
            }
            else{
                cout << (r - 1) / 2 << ' ' << (r - 1) / 2 << '\n';
            }
        }
        else {
            int is_prime = true, k;
            for(int i = 2; i * i <= r; ++i){
                if(r % i == 0){
                    is_prime = false;
                    k = i;
                    break;
                }
            }
            if(is_prime){
                cout << -1 << '\n';
            }
            else{
                cout << r - k << ' ' << k << '\n';
            }
        }
    }

    return 0;
}