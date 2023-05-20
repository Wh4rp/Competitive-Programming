#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)
#define rep_(i, k, n) for (int i = k; i < n; ++i)
using ll = long long;

int k, cont;
bool win = false;
vector<pair<int, int>> pos;
bool row[8], col[8], diag1[15], diag2[15];

void solve(int x, int y) {
    if(cont == 8)
        win = true;
    if (win)
        return;
    if (!row[x] && !col[y]) {
        pos.push_back({x, y});
        row[x] = true;
        col[y] = true;
        cont++;
        solve(x, y+1);
        solve(x+1, y);
        solve(x+1, y+1);
        pos.pop_back();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.setf(ios::fixed);
    cout.precision(10);

    cin >> k;
    cont = k;
    rep(i, k) {
        int x, y;
        cin >> x >> y;
        pos.push_back({x, y});
        row[x] = true;
        col[y] = true;
    }

    solve(0, 0);

    return 0;
}