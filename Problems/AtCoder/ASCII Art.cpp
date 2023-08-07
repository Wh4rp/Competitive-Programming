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

    int r, c;
    cin >> r >> c;
    char grid[r][c];
    rep(i, r) rep(j, c) {
        int aux;
        cin >> aux;
        if (aux == 0)
            grid[i][j] = '.';
        else
            grid[i][j] = 'A' + aux - 1;
    }
    rep(i, r) {
        rep(j, c) cout << grid[i][j];
        cout << '\n';
    }

    return 0;
}