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

    int r, g, b;
    cin >> r >> g >> b;

    int ans1 = min({r, g, b});
    ans1 += (r - ans1) / 3 + (g - ans1) / 3 + (b - ans1) / 3;

    int ans2;
    ans2 = r / 3 + g / 3 + b / 3;
    ans2 += min({r % 3, g % 3, b % 3});

    int ans3 = 0;
    if(r >= 3) {
        ans3 = (r-3) / 3 + g / 3 + b / 3;
        ans3 += min({(r % 3) + 3, g % 3, b % 3});
    }

    int ans4 = 0;
    if(g >= 3) {
        ans4 = r / 3 + (g-3) / 3 + b / 3;
        ans4 += min({r % 3, (g % 3) + 3, b % 3});
    }

    int ans5 = 0;
    if(b >= 3) {
        ans5 = r / 3 + g / 3 + (b - 3) / 3;
        ans5 += min({r % 3, g % 3, (b % 3) + 3});
    }

    int ans6 = 0;
    if(r >= 3 && g >= 3) {
        ans6 = (r-3) / 3 + (g-3) / 3 + b / 3;
        ans6 += min({(r % 3) + 3, (g % 3) + 3, b % 3});
    }

    int ans7 = 0;
    if(r >= 3 && b >= 3) {
        ans7 = (r-3) / 3 + g / 3 + (b-3) / 3;
        ans7 += min({(r % 3) + 3, g % 3, (b % 3) + 3});
    }

    int ans8 = 0;
    if(g >= 3 && b >= 3) {
        ans8 = r / 3 + (g-3) / 3 + (b-3) / 3;
        ans8 += min({r % 3, (g % 3) + 3, (b % 3) + 3});
    }

    cout << max({ans1, ans2, ans3, ans4, ans5, ans6, ans7, ans8}) << '\n';

    return 0;
}