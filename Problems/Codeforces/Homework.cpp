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

    string s;
    int k, count = 0;
    cin >> s >> k;
    int a[26] = {0};
    bool b[26] = {false};
    for (char c : s) {
        a[c - 'a']++;
    }
    vector<pair<int, char>> v;
    rep(i, 26) {
        if (a[i] != 0) {
            count++;
            v.push_back({a[i], 'a' + i});
        }
    }
    sort(v.begin(), v.end());
    int j = 0;
    for (auto x : v) {
        if (x.first <= k) {
            b[x.second - 'a'] = true;
            k -= x.first;
            j++;
        }
    }

    cout << count - j << '\n';
    if (j != v.size()) {
        for (auto c : s) {
            if (!b[c - 'a']) {
                cout << c;
            }
        }
        cout << '\n';
    }
    return 0;
}