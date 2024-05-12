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
        int n, k, q;
        cin >> n >> k >> q;
        // a_i puntos del camino
        // b_i tiempo en que llega a cada punto
        vector<int> a(k+1), b(k+1);
        // vector <punto, tiempo>
        vector<pair<int, int>> v;

        a.push_back(0);
        b.push_back(0);
        rep_(i, 1, k + 1) cin >> a[i];
        rep_(i, 1, k + 1) cin >> b[i];
        a.push_back(n);
        rep(i, k+1){
            v.push_back({a[i], b[i]});
        }

        rep(i, q){
            // punto d
            int d;
            cin >> d;
            auto it = lower_bound(v.begin(), v.end(), make_pair(d, 0));
            int j = it - v.begin();
            if(v[j].first == d){
                cout << v[j].second << ' ';
            }
            else{
                ll time_dif = v[j].second - v[j-1].second;
                ll A = v[j-1].first;
                ll B = v[j].first;
                ll time_prev = v[j-1].second;
                cout << time_prev + (d - A) * time_dif / (B - A) << ' ';
            }
        }
        cout << '\n';
    }

    return 0;
}