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

    int n, g;

    while (cin >> n >> g) {
        int ans = 0;
        vector<int> matches;
        rep(i, n) {
            int x, y;
            cin >> x >> y;
            if (x > y)
                ans += 3;
            else
                matches.push_back(y - x);
        }
        sort(matches.begin(), matches.end());
        for(auto dif : matches){
            if(g == 0) {
                if (dif == 0)
                    ans += 1;
            }
            else if(g > dif) {
                g -= dif + 1;
                ans += 3;
            }
            else if(g == dif) {
                ans += 1;
                g -= dif;
            }
        }
        cout << ans << '\n';
    }

    return 0;
}