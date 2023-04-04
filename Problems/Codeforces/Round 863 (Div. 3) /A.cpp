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
    while (t--) {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        int pos = -1;
        rep(i, n){
            int val = s[i] - '0';
            if(k > val){
                pos = i;
                break;
            }
        }
        if(pos != -1){
            rep(i, pos){
                cout << s[i];
            }
            cout << k;
            rep_(i, pos, n){
                cout << s[i];
            }
        }
        else{
            cout << s << k;
        }
        cout << '\n';
    }

    return 0;
}