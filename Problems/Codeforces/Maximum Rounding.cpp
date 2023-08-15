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

    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int n = s.size();
        vector<int> v(n);
        rep(i, n) v[i] = s[n - 1 - i] - '0';
        v.push_back(0);

        int j = 0, cero_pos = 0;
        while (j < v.size()) {
            if (v[j] >= 5) {
                while (j < v.size() - 1 && v[j + 1] == 9) {
                    j++;
                }
                if (j + 1 == v.size() - 1)
                    v.push_back(0);
                v[j + 1]++;
                for (int k = cero_pos; k <= j; k++)
                    v[k] = 0;
                cero_pos = j;
            }
            j++;
        }

        rep_(i, 1, v.size()) cout << v[v.size() - 1 - i];
        cout << '\n';
    }

    return 0;
}