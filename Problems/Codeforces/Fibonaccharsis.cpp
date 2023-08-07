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
        ll n, k, ans = 0;
        cin >> n >> k;
        rep(i, n) {
            ll fib_prev = n, fib_curr = n - i, fib_next;
            rep(j, k - 1){
                fib_next = fib_prev - fib_curr;
                if(fib_next < 0){
                    ans --;
                    break;
                }
                fib_prev = fib_curr;
                fib_curr = fib_next;
            }
            ans++;
        }
        cout << ans << '\n';
    }

    return 0;
}