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

    int R, C, n, k;
    cin >> R >> C >> n >> k;
    int a[R][C];
    rep(i, R) rep(j, C) a[i][j] = 0;

    rep(i, n) {
        int aux1, aux2;
        cin >> aux1 >> aux2;
        aux1--, aux2--;
        a[aux1][aux2] = 1;
    }

    int psa[R][C];
    psa[0][0] = a[0][0];

    for (int i = 1; i < C; i++)
        psa[0][i] = psa[0][i - 1] + a[0][i];
    for (int i = 1; i < R; i++)
        psa[i][0] = psa[i - 1][0] + a[i][0];

    for (int i = 1; i < R; i++) {
        for (int j = 1; j < C; j++)
            psa[i][j] =
                psa[i - 1][j] + psa[i][j - 1] - psa[i - 1][j - 1] + a[i][j];
    }

    int ans = 0;

    rep(i, R) {
        rep(j, C) {
            rep_(i2, i, R) {
                rep_(j2, j, C) {
                    int aux3 = 0;
                    aux3 += psa[i2][j2];
                    if (i != 0) {
                        aux3 -= psa[i - 1][j2];
                    }
                    if (j != 0) {
                        aux3 -= psa[i2][j - 1];
                    }
                    if (i != 0 && j != 0) {
                        aux3 += psa[i - 1][j - 1];
                    }
                    if (aux3 >= k) {
                        ans++;
                    }
                }
            }
        }
    }

    cout << ans << '\n';

    return 0;
}