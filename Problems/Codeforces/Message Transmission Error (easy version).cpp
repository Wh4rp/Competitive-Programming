#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)
#define rep_(i, k, n) for (int i = k; i < n; ++i)
using ll = long long;

const ll MAXN = 1e5 + 5;

struct RollingHashing {
    const ll A = 1777771, B[2] = {999727999, 1070777777};
    ll h[2][MAXN], p[2][MAXN];
    string S;

    RollingHashing(string s) : S(s) { preprocess(s); }

    ll pol_hash(string s) {
        ll h0 = 0, h1 = 0;
        ll n = s.size();
        for (int i = n - 1; i >= 0; i--) {
            h0 = (h0 * A + s[i]) % B[0];
            h1 = (h1 * A + s[i]) % B[1];
        }
        return (h0 << 32) | h1;
    }

    void preprocess(string s) {
        this->S = s;
        ll n = s.size();
        p[0][0] = 1, p[1][0] = 1;
        for (int i = 1; i <= n; i++) {
            p[0][i] = (p[0][i - 1] * A) % B[0];
            p[1][i] = (p[1][i - 1] * A) % B[1];
        }
        h[0][n] = 0, h[1][n] = 0;
        for (int i = n - 1; i >= 0; i--) {
            h[0][i] = (h[0][i + 1] * A + s[i]) % B[0];
            h[1][i] = (h[1][i + 1] * A + s[i]) % B[1];
        }
    }

    ll get_hash(int i, int j) {
        ll h0 = (h[0][i] - h[0][j] * p[0][j - i] + B[0] * B[0]) % B[0];
        ll h1 = (h[1][i] - h[1][j] * p[1][j - i] + B[1] * B[1]) % B[1];
        return (h0 << 32) | h1;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.setf(ios::fixed);
    cout.precision(10);

    string s;
    cin >> s;
    RollingHashing rh(s);
    
    ll i = 1;
    ll n = s.size();
    while (n-i + n - 1 - i + 1 > n) {
        ll h = rh.get_hash(0, n-i-1);
        ll h2 = rh.get_hash(i, n-1);
        if (h == h2) {
            // check if the substrings are equal
            if (s.substr(0, n-i) == s.substr(i, n-i)) {
                cout << "YES\n";
                cout << s.substr(0, n-i) << '\n';
                return 0;
            }
        }
        i++;
    }

    cout << "NO\n";

    return 0;
}