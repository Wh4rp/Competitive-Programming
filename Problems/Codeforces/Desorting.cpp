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
        int n;
        cin >> n;
        int a[n];
        rep(i, n) cin >> a[i];
        bool sorted = true;
        rep(i, n - 1) {
            if (a[i] > a[i + 1]) {
                sorted = false;
                break;
            }
        }
        if(!sorted)
            cout << "0\n";
        else{
            int min_dif = 1e9 + 5;
            rep(i, n - 1){
                min_dif = min(min_dif, a[i + 1] - a[i]);
            }
            cout << (min_dif + 2) / 2 << '\n';
        }
    }

    return 0;
}