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
        map<int, int> NS, WE, SW_NE, SE_NW;
        int n;
        cin >> n;
        pair<int, int> points[n];
        rep(i, n) {
            cin >> points[i].first >> points[i].second;
            // North to South intersection with X axis
            NS[points[i].first]++;
            // West to East intersection with Y axis
            WE[points[i].second]++;
            // SouthWest to NorthEast intersection with Y
            SW_NE[-points[i].first + points[i].second]++;
            // SouthEast to NorthWest intersection with Y
            SE_NW[points[i].first + points[i].second]++;
        }
        ll ans = 0;
        rep(i, n) {
            ans += NS[points[i].first] - 1;
            ans += WE[points[i].second] - 1;
            ans += SW_NE[-points[i].first + points[i].second] - 1;
            ans += SE_NW[points[i].first + points[i].second] - 1;
        }

        cout << ans << '\n';
    }

    return 0;
}