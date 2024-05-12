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
    while (t--){
        string s;
        cin >> s;
        vector<int> v;
        char val = s[0];
        v.push_back(val - '0');

        rep_(i, 1, s.size()){
            if(s[i] != val){
                val = s[i];
                v.push_back(val - '0');
            }
        }
        int n = v.size();
        if(n == 1){
            cout << n << '\n';
        }
        else if(n == 2){
            if(v[0] == 0 && v[1] == 1){
                cout << 1 << '\n';
            }
            else{
                cout << 2 << '\n';
            }
        }
        else{
            cout << n - 1 << '\n';
        }
    }

    return 0;
}