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
        string s;
        cin >> s;
        int n = s.size();
        int a = 0, b = -1;
        rep(i, n){
            if(s[i] != s[a]){
                b = i;
                break;
            }
        }

        if(b == -1){
            cout << "NO\n";
        }
        else{
            cout << "YES\n";
            rep(i, n){
                if(i == a){
                    cout << s[b];
                }
                else if(i == b){
                    cout << s[a];
                }
                else{
                    cout << s[i];
                }
            }
            cout << '\n';
        }
    }

    return 0;
}