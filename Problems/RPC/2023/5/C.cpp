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

    int n;
    cin >> n;
    string s;
    vector<int> v(n, 0);
    cin >> s;
    rep(i, n) {
        if (s[i] == '1') {
            v[i] = 1;
            if (i < n - 1) {
                v[i + 1] = 1;
            }
            if (i < n - 2) {
                v[i + 2] = 1;
            }
        }
    }

    int cont = 0;
    rep(i, n){
        if(v[i] == 1){
            cont++;
        }
    }

    cout << cont << '\n';

    return 0;
}