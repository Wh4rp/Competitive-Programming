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
        if (n <= 11) {
            cout << n << '\n';
            rep(i, n) {
                cout << i + 1 << ' ';
            }
            cout << '\n';
        } else {
            int primes_11[11] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
            map<int, vector<int>> colored_by;
            rep(i, n){
                rep(j, 11){
                    if(a[i] % primes_11[j] == 0){
                        colored_by[primes_11[j]].push_back(i);
                        break;
                    }
                }
            }
            int count = 0;
            for(auto x : colored_by){
                count++;
                for(auto y : x.second){
                    a[y] = count;
                }
            }
            cout << count << '\n';
            rep(i, n){
                cout << a[i] << ' ';
            }
        }
    }

    return 0;
}
