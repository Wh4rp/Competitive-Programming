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
    while(t--){
        int n, x1, y1, x2, y2;
        cin >> n >> x1 >> y1 >> x2 >> y2;
        int dis1 = min({abs(x1 - 1), abs(x1 - n), abs(y1 - 1), abs(y1 - n)});
        int dis2 = min({abs(x2 - 1), abs(x2 - n), abs(y2 - 1), abs(y2 - n)});
        cout << abs(dis1 - dis2) << '\n';
    }

    return 0;
}