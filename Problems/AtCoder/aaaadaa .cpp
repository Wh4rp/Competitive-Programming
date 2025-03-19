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
    char c1, c2;
    string s;

    cin >> n >> c1 >> c2;
    cin >> s;
    rep(i, n){
        if(s[i] == c1) cout << c1;
        else cout << c2;
    }
    cout << '\n';

    return 0;
}