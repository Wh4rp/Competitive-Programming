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

    int n, d;
    string s;
    cin >> n >> d >> s;

    for(int i = n - 1; i >= 0; i--) {
        if(d && s[i] == '@') {
            s[i] = '.';
            d--;
        }
    }

    cout << s << '\n';

    return 0;
}