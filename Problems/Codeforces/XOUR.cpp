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
        int n;
        cin >> n;
        vector<int> v(n);
        rep(i, n) cin >> v[i];
        map<int, vector<int>> m;
        map<int, int> cnt;
        rep(i, n){
            m[v[i]>>2].push_back(v[i]);
            cnt[v[i]>>2] = 0;
        }
        for(auto &x : m){
            sort(x.second.begin(), x.second.end());
        }
        rep(i, n){
            cout << m[v[i]>>2][cnt[v[i]>>2]] << ' ';
            cnt[v[i]>>2]++;
        }
        cout << '\n';
    }

    return 0;
}