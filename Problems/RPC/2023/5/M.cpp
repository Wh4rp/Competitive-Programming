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

    int n, ans = -1;
    cin >> n;
    vector<int> v(n);
    rep(i, n) {
        cin >> v[i];
    }

    int i = 0;
    int j = 0;
    bool crescent = false;

    while (i < n - 1) {
        if (v[i] < v[i + 1] && !crescent) {
            crescent = true;
            j = i;
        }
        if (crescent && v[i] > v[i + 1]) {
            int k = 1;
            int ans1 = 0;
            while (i - k >= j && i + k < n && v[i + k - 1] > v[i + k] &&
                   v[i - k] == v[i + k]) {
                ans1++;
                k++;
            }
            i = j + k - 1;
            crescent = false;
            if (ans1 != 0)
                ans = max(ans1 * 2 + 1, ans);
        }
        i++;
    }

    cout << ans << '\n';

    return 0;
}