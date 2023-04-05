#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)
#define rep_(i, k, n) for (int i = k; i < n; ++i)
using ll = long long;

int N;
string s;
vector<ll> weights0, weights1;

int lowerbound(vector<ll>& a, int key, int i, int j) {
    while (i < j) {
        int m = (i + j) / 2;
        if (a[m] >= key)
            j = m;
        else
            i = m + 1;
    }
    return i;
}

ll f(ll x) {
    ll ans = 0;
    // "first element >= key"
    ll a = lowerbound(weights0, x, 0, weights0.size());
    ll b = weights1.size() - lowerbound(weights1, x, 0, weights1.size());
    ans += a + b;
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.setf(ios::fixed);
    cout.precision(10);

    cin >> N >> s;

    rep(i, N) {
        ll aux;
        cin >> aux;
        if (s[i] == '0')
            weights0.push_back(aux);
        else
            weights1.push_back(aux);
    }

    sort(weights0.begin(), weights0.end());
    sort(weights1.begin(), weights1.end());

    ll ans = 0;
    rep(i, weights0.size()) {
        ans = max(ans, f(weights0[i] - 1));
        ans = max(ans, f(weights0[i] + 1));
        ans = max(ans, f(weights0[i]));
    }
    rep(i, weights1.size()) {
        ans = max(ans, f(weights1[i] - 1));
        ans = max(ans, f(weights1[i] + 1));
        ans = max(ans, f(weights1[i]));
    }
    cout << ans << '\n';

    return 0;
}