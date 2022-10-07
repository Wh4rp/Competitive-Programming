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

    int n, e, time;
    cin >> n >> e;
    vector<int> v(e), d(e);
    rep(i, e) cin >> v[i] >> d[i];
    map<int, int> m;
    rep(i, e){
        rep(j, e){
            if(i == j) continue;
            int a, b;
            set<int> s;
            if(v[i] < v[j]){
                if(d[i] == 1)
                    time = v[j] - v[i];
                else
                    time = v[i] - v[j] + n;
            }
            else{
                if(d[i] == 1)
                    time = v[i] - v[j] + n;
                else
                    time = v[j] - v[i];
            }
            s.insert(time);
            if(s.find(time) != s.end())
                m[time]++;
        }
    }
    m[n] = e;
    for(auto i : m){
        if(i.second == e){
            cout << i.first << '\n';
            break;
        }
    }
    return 0;
}