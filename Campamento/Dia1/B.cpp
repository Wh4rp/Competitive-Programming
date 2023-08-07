#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)
#define rep_(i, k, n) for (int i = k; i < n; ++i)
using ll = long long;

ll bin_search(ll key, ll i, ll j) {
    while (i < j) {
        ll m = (i + j) / 2;
        if (m * m >= key)
            j = m;
        else
            i = m + 1;
    }
    return i;
}

int main() {
    int n;
    cin >> n;
    ll pos = 250000;
    while (n) {
        cout << pos << ' ' << pos << '\n';
        ll dis, dis2;6
        cin >> dis;
        ll aux = 0;
        bool flag = true;
        while (flag && aux * aux <= dis) {
            ll aux2 = bin_search(dis - aux * aux, 0, 2LL * 10000000LL);
            // cout << "la busqueda " << aux << " nos dio " << aux2 << '\n';
            if (aux * aux + aux2 * aux2 == dis) {
                ll movesx[] = {aux, aux, -aux, -aux, aux2, aux2, -aux2, -aux2};
                ll movesy[] = {aux2, -aux2, aux2, -aux2, aux, -aux, aux, -aux};
                rep(i, 8) {
                    ll posx = pos + movesx[i], posy = pos + movesy[i];
                    if (0 <= posx && posx <= 1000000 && 0 <= posy &&
                        posy <= 1000000) {
                        cout << posx << ' ' << posy << '\n';
                        cin >> dis2;
                        if (dis2 == 0) {
                            flag = false;
                            break;
                        }
                    }
                }
            }
            aux++;
        }
        n--;
    }

    return 0;
}