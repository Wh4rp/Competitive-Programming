#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)
#define rep_(i, k, n) for (int i = k; i < n; ++i)
using ll = long long;

struct Num {
    int resto, suma;
    string s;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.setf(ios::fixed);
    cout.precision(10);

    ll d, s;
    cin >> d >> s;

    bool visited[505][5005];
    rep(i, 505) rep(j, 5005) visited[i][j] = false;

    queue<pair<pair<int, int>, string>> q;

    q.push({{0, 0}, ""});
    visited[0][0] = true;
    string ans = "-1";

    while (!q.empty()) {
        pair < pair<int, int>, string> aux = q.front();
        int resto = aux.first.first;
        int suma = aux.first.second;
        string val = aux.second;
        q.pop();
        if (resto == 0 && suma == s) {
            ans = val;
            break;
        } else {
            rep(i, 10) {
                if (val == "" && i == 0)
                    continue;
                int new_suma = suma + i;
                int new_resto = (resto * 10 + i) % d;
                if (new_suma <= s && !visited[new_resto][new_suma]) {
                    string new_val = val + (char)('0' + i);
                    q.push({{new_resto, new_suma}, new_val});
                    visited[new_resto][new_suma] = true;
                }
            }
        }
    }

    cout << ans << '\n';

    return 0;
}