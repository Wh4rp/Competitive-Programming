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

    int n, ans = 0, inicio = 0, fin = 0, aux;
    // valor posicion
    map<int, int> playlist;
    cin >> n;
    while (fin < n) {
        cin >> aux;
        if(playlist.count(aux) == 0){
            playlist[aux] = fin;
        }
        else if (playlist[aux] < inicio) {
            playlist[aux] = fin;
        } else {
            // Hemos encontrado una musica repetida
            inicio = playlist[aux] + 1;
            playlist[aux] = fin;
        }
        fin++;
        ans = max(ans, fin - inicio);
    }
    cout << ans << '\n';

    return 0;
}