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
        int a[n], count[n + 5];

        rep(i, n) {
            count[i + 1] = 0;
            cin >> a[i];
        }
        rep(i, n) {
            count[a[i]]++;
        }

        int ans = count[1], ans1 = 0;
        rep_(i, 1, n+1) {
            if(count[i]){
                ans1++;
            }
            else{
                break;
            }
        }
        cout << min(ans, ans1) << '\n';
    }

    return 0;
}