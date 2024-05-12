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
        string s1, s2;
        cin >> s1 >> s2;
        int fase = 0, n = s1.size();
        rep(i, n) {
            int dig1 = s1[i] - '0';
            int dig2 = s2[i] - '0';
            if (fase == 0) {
                if(dig1 != dig2) {
                    if(dig1 < dig2){
                        swap(s1[i], s2[i]);
                    }
                    fase = 1;
                }
            }
            else if (fase == 1){
                    if(dig1 > dig2){
                        swap(s1[i], s2[i]);
                    }
            }
        }
        cout << s1 << '\n';
        cout << s2 << '\n';
    }
    

    return 0;
}