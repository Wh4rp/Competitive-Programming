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
    int cookies = 0;

    rep(i, n) cookies += (s[i] == '@');

    cout << min(n, (n - cookies + d)) << '\n';

    return 0;
}