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

    ll n, v;
    cin >> n >> v;
    vector<int> powers(n);
    rep(i, n){
        cin >> powers[i];
    }

    rep(i, n){
        vector<int> ans;
        int v1 = v,  j = i, j1 = i - 1, j2 = i + 1, count = 0;
        while(count < n && v1 >= powers[j]){
            // cout << j << '\n';
            ans.push_back(j + 1);
            count++;
            v1++;
            if(j1 < 0){
                j = j2;
                j2++;
            }
            else if(j2 >= n){
                j = j1;
                j1--;
            }
            else{
                if(powers[j1] >= powers[j2]){
                    j = j2;
                    j2++;
                }
                else {
                    j = j1;
                    j1--;
                }
            }
        }
        // cout << '\n';
        if(count == n){
            rep(k, n){
                cout << ans[k] << " \n"[k == n-1]; 
            }
            return 0;
        }
    }

    cout << "FALLIDA\n";

    return 0;
}