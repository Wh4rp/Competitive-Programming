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
        ll n, k, pb, ps, acc_b = 0, acc_s = 0;
        cin >> n >> k >> pb >> ps;
        ll p[n+5], a[n+5];
        rep_(i, 1, n+1) cin >> p[i];
        rep_(i, 1, n+1) cin >> a[i];
        vector<bool> visited_b(n+5, false), visited_s(n+5, false);
        vector<int> steps_b(n+5, -1), steps_s(n+5, -1);
        ll ans_b = -1, ans_s = -1;
        ll i = 0;
        while(!visited_b[pb] && i < k) {
            visited_b[pb] = true;
            acc_b += a[pb];
            ans_b = max(ans_b, acc_b + a[pb] * (k - i - 1));
            pb = p[pb];
            i++;
        }
        i = 0;
        while(!visited_s[ps] && i < k) {
            visited_s[ps] = true;
            acc_s += a[ps];
            ans_s = max(ans_s, acc_s + a[ps] * (k - i - 1));
            ps = p[ps];
            i++;
        }
        if(ans_b == ans_s){
            cout << "Draw\n";
        }
        else if (ans_b > ans_s){
            cout << "Bodya\n";
        }
        else{
            cout << "Sasha\n";
        }
    }

    return 0;
}