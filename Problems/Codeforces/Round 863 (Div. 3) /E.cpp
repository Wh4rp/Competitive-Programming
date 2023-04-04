#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)
#define rep_(i, k, n) for (int i = k; i < n; ++i)
using ll = long long;

vector<int> fun(ll k) {
    vector<int> ans;
    while (k) {
        int val = k % 9;
        switch (val) {
            case 0:
                ans.push_back(0);
                break;
            case 1:
                ans.push_back(1);
                break;
            case 2:
                ans.push_back(2);
                break;
            case 3:
                ans.push_back(3);
                break;
            case 4:

                ans.push_back(5);
                break;
            case 5:

                ans.push_back(6);
                break;
            case 6:

                ans.push_back(7);
                break;
            case 7:

                ans.push_back(8);
                break;
            case 8:

                ans.push_back(9);
                break;
            default:
                break;
        }
        k /= 9;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.setf(ios::fixed);
    cout.precision(10);

    int t;
    cin >> t;
    while (t--) {
        ll k;
        cin >> k;
        vector<int> ans = fun(k);
        reverse(ans.begin(), ans.end());
        rep(i, ans.size()){
            cout << ans[i];
        }
        cout << '\n';
    }
    return 0;
}