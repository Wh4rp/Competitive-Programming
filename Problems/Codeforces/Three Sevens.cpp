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
        int m;
        map<int, int> last_game;
        cin >> m;
        int winners[m];
        rep(i, m) {
            int n;
            cin >> n;
            rep(j, n){
                int x;
                cin >> x;
                last_game[x] = i;
            }
            winners[i] = -1;
        }
        for(auto x: last_game){
            if (winners[x.second] == -1){
                winners[x.second] = x.first;
            }
        }
        bool ok = true;
        rep(i, m){
            if (winners[i] == -1){
                ok = false;
                break;
            }
        }
        if (ok){
            rep(i, m){
                cout << winners[i] << " ";
            }
            cout << '\n';
        } else {
            cout << "-1\n";
        }
    }

    return 0;
}