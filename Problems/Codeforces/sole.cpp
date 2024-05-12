#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)
#define rep_(i, k, n) for (int i = k; i < n; ++i)
using ll = long long;

ll costo_a_puntos[1005];
ll costo_a_gato[1005];

int n, m, x, y;
ll ans = -1;

ll backtracking(int col, ll acumulado, int racha){
    // cout << "Col: " << col << " Acumulado: " << acumulado << " Racha: " << racha << '\n';
    if(col == m){
        // cout << "acumulado: " << acumulado << '\n';
        if(racha != 0 && racha < x)
            return -1;
        if(ans == -1)
            return ans = acumulado;
        else
            return ans = min(ans, acumulado);
    }
    if(ans != -1 && acumulado > ans)
        return -1;
    //cout << "Pase...\n";
    ll ans1 = -1, ans2 = -1;
    if(racha == 0 || racha >= x)
        ans1 = backtracking(col + 1, acumulado + costo_a_puntos[col], 0);
    if(racha + 1 <= y)
        ans2 = backtracking(col + 1, acumulado + costo_a_gato[col], racha + 1);
    if(ans1 == -1)
        return ans2;
    if(ans2 == -1)
        return ans1;
    return min(ans1, ans2);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.setf(ios::fixed);
    cout.precision(10);

    cin >> n >> m >> x >> y;
    string grid[n];
    rep(i, n) {
        cin >> grid[i];
    }
    // calculamos los costos estos xd
    rep(j, m){
        costo_a_gato[j] = 0;
        costo_a_puntos[j] = 0;
        rep(i, n){
            if(grid[i][j] == '.'){
                costo_a_gato[j]++;
            }
            else{
                costo_a_puntos[j]++;
            }
        }
        // ans += costo_a_gato[j];
    }
    
    backtracking(0, 0, 0);

    cout << ans << '\n';

    return 0;
}