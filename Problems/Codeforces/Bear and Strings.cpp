#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)
#define rep_(i, k, n) for (int i = k; i < n; ++i)
using ll = long long;

vector<int> failure_function(string pattern) {
    int n = pattern.size();
    vector<int> f(n + 1);
    f[0] = f[1] = 0;
    for (int i = 2; i <= n; i++) {
        int j = f[i - 1];

        while (j > 0 && pattern[j] != pattern[i - 1]) {
            j = f[j];
        }

        if (pattern[j] == pattern[i - 1]) {
            j++;
        }

        f[i] = j;
    }
    return f;
}

vector<ll> kmp(string text, string pattern) {
    vector<int> f = failure_function(pattern);
    vector<ll> matches;
    int n = text.size();
    int m = pattern.size();
    int i = 0, j = 0;
    while (i < n) {
        if (text[i] == pattern[j]) {
            i++;
            j++;
            if (j == m) {
                matches.push_back(i - m);
                j = f[j];
            }
        } else if (j > 0) {
            j = f[j];
        } else {
            i++;
        }
    }
    return matches;
}

ll count(ll l, ll r, ll pos){
    return (pos - l + 1) * (r - (pos + 3) + 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.setf(ios::fixed);
    cout.precision(10);

    string s;
    cin >> s;

    auto v = kmp(s, "bear");

    ll n = s.length(), l = 0, ans = 0;

    for(ll pos : v){
        ans += count(l, n-1, pos);
        l = pos+1;
    }

    cout << ans << '\n';

    return 0;
}