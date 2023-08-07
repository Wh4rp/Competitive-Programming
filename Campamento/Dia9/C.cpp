#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)
#define rep_(i, k, n) for (int i = k; i < n; ++i)
using ll = long long;

template <class T>
vector<int> prefix(T& S) {
    vector<int> P(S.size());
    P[0] = 0;
    for (int i = 1; i < S.size(); ++i) {
        P[i] = P[i - 1];
        while (P[i] > 0 && S[P[i]] != S[i])
            P[i] = P[P[i] - 1];
        if (S[P[i]] == S[i])
            ++P[i];
    }
    return P;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.setf(ios::fixed);
    cout.precision(10);

    int n;
    string s1, s2, s3;
    cin >> n >> s1 >> s2;

    s3 = s1 + "#" + s2 + s2;

    vector<int> v = prefix<string>(s3);
    int ans = -1;

    for (int i = 0, j = v.size() - 1; j >= 0; j--, i++) {
        if (v[j] == n)
            ans = n - i;
    }

    cout << ans << '\n';

    return 0;
}