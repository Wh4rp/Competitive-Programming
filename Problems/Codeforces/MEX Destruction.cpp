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

        bool all_zeros = true;
        rep(i, n) all_zeros = all_zeros && (a[i] == 0);
        if(all_zeros)
            cout << "0\n";
        else {
            int num_sequences = 0;
            bool in_zero_zone = true;
            rep(i, n) {
                if(a[i] == 0) {
                    in_zero_zone = true;
                } else {
                    if(in_zero_zone) {
                        num_sequences++;
                        in_zero_zone = false;
                    }
                }
            }
            if(num_sequences == 1) {
                cout << "1\n";
            } else{
                cout << "2\n";
            }
        }
    }

    return 0;
}