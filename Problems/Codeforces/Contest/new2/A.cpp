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
        int n;
        cin >> n;
        vector<int> a(n);
        rep(i, n) cin >> a[i];
        sort(a.begin(), a.end(), greater<int>());
        int ac = 0;
        bool flag = true;
        int i = 0, j = 0;
        while (i < n) {
            if (ac == a[i]){
                if (j == n) break;
                swap(a[i], a[j]);
                j++;
            }
            else{
                i++;
                ac += a[i];
            }
        }
        if (i != n) {
            cout << "NO\n";
        }
        else {
            cout << "YES\n";
            rep(i, n) cout << a[i] << " \n"[i == n - 1];
        }
    }

    return 0;
}