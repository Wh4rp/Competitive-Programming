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
        ll ans = 0;
        string s[10];
        int values[10][10];

        // i = 0
        values[0][0] = 1;
        values[0][1] = 1;
        values[0][2] = 1;
        values[0][3] = 1;
        values[0][4] = 1;
        values[0][5] = 1;
        values[0][6] = 1;
        values[0][7] = 1;
        values[0][8] = 1;
        values[0][9] = 1;

        // i = 1

        values[1][0] = 1;
        values[1][1] = 2;
        values[1][2] = 2;
        values[1][3] = 2;
        values[1][4] = 2;
        values[1][5] = 2;
        values[1][6] = 2;
        values[1][7] = 2;
        values[1][8] = 2;
        values[1][9] = 1;

        // i = 2

        values[2][0] = 1;
        values[2][1] = 2;
        values[2][2] = 3;
        values[2][3] = 3;
        values[2][4] = 3;
        values[2][5] = 3;
        values[2][6] = 3;
        values[2][7] = 3;
        values[2][8] = 2;
        values[2][9] = 1;

        // i = 3

        values[3][0] = 1;
        values[3][1] = 2;
        values[3][2] = 3;
        values[3][3] = 4;
        values[3][4] = 4;
        values[3][5] = 4;
        values[3][6] = 4;
        values[3][7] = 3;
        values[3][8] = 2;
        values[3][9] = 1;

        // i = 4

        values[4][0] = 1;
        values[4][1] = 2;
        values[4][2] = 3;
        values[4][3] = 4;
        values[4][4] = 5;
        values[4][5] = 5;
        values[4][6] = 4;
        values[4][7] = 3;
        values[4][8] = 2;
        values[4][9] = 1;

        rep(i, 10) cin >> s[i];
        rep(i, 10){
            rep(j, 10){
                if(s[i][j] == 'X')
                    // ans += values[min(i, 9 - i)][j];
                    ans += 1 + min(min(i, 9 - i), min(j, 9 - j));
            }
        }

        cout << ans << '\n';
    }

    return 0;
}