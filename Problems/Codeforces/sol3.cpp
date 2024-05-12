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

    int n, m;
    cin >> n >> m;
    vector<vector<int>> cilindros(m, vector<int>());
    // color -> par de posiciones donde estan cada copia del color
    // vector<pair<pair<int, int>, pair<int, int>>> mapa(200001, make_pair(make_pair(-1, -1), make_pair(-1, -1));
    vector<pair<pair<int, int>, pair<int, int>>> mapa(n + 5, {{-1, -1}, {-1, -1}});
    // cola de eliminacion de bolas
    queue<pair<pair<int, int>, pair<int, int>>> cola;
    // estado de bolas 0 -> cilindro, 1 -> en cola y 2 -> eliminada
    vector<int> estado(n + 5, 0);
    vector<int> cabeza_actual(m, 0);
    rep(i, m){
        int k;
        cin >> k;
        cabeza_actual[i] = k - 1;
        rep(j, k){
            int color;
            cin >> color;
            cilindros[i].push_back(color);
            if(mapa[color].first.first == -1){
                mapa[color].first.first = i;
                mapa[color].first.second = j;
            }
            else{
                mapa[color].second.first = i;
                mapa[color].second.second = j;
            }
        }
    }
    // for por cada cabeza de cada cilindro
    rep(i, m){
        int k = cilindros[i].size();
        int color = cilindros[i][k - 1];
        if(estado[color] == 0){
            // obtengo las posiciones de ambas copias del color
            pair<int, int> pos1 = mapa[color].first;
            pair<int, int> pos2 = mapa[color].second;
            // si ambas copias estan en la cabeza de sus respectivos cilindros
            // los metemos a la cola de eliminacion
            int k1 = cabeza_actual[pos1.first];
            int k2 = cabeza_actual[pos2.first];
            if(k1 == pos1.second && k2 == pos2.second){
                estado[color] = 1;
                cola.push({pos1, pos2});
            }
        }
    }

    int bolas_eliminadas = 0;

    while(!cola.empty()){
        // obtenemos las bolas a eliminar
        pair<int, int> posx1 = cola.front().first;
        pair<int, int> posx2 = cola.front().second;
        // eliminamos
        cola.pop();
        bolas_eliminadas++;
        cabeza_actual[posx1.first]--;
        cabeza_actual[posx2.first]--;
        // vemos si la bola 1 hace que otra bola se meta a eliminacion
        int i = posx1.first;
        int j = posx1.second - 1;
        int color;
        if(j > -1) {
            color = cilindros[i][j];
            if(estado[color] == 0){
                // obtengo las posiciones de ambas copias del color
                pair<int, int> posy1 = mapa[color].first;
                pair<int, int> posy2 = mapa[color].second;
                // cout << "Queremos meter a la cola a la bola " << cilindros[posy1.first][posy1.second] << " y a la bola " << cilindros[posy2.first][posy2.second] << "\n";
                // si ambas copias estan en la cabeza de sus respectivos cilindros
                // los metemos a la cola de eliminacion
                int ky1 = cabeza_actual[posy1.first];
                int ky2 = cabeza_actual[posy2.first];
                if(ky1 >= 0 && ky1 >= 0 && ky1 == posy1.second && ky2 == posy2.second){
                    estado[color] = 1;
                    cola.push({posy1, posy2});
                }
            }
        }
        // vemos si la bola 1 hace que otra bola se meta a eliminacion
        i = posx2.first;
        j = posx2.second - 1;
        if(j > -1) {
            color = cilindros[i][j];
            if(estado[color] == 0){
                // obtengo las posiciones de ambas copias del color
                pair<int, int> posz1 = mapa[color].first;
                pair<int, int> posz2 = mapa[color].second;
                // si ambas copias estan en la cabeza de sus respectivos cilindros
                // los metemos a la cola de eliminacion
                int kz1 = cabeza_actual[posz1.first];
                int kz2 = cabeza_actual[posz2.first];
                if(kz1 >= 0 && kz1 >= 0 && kz1 == posz1.second && kz2 == posz2.second){
                    estado[color] = 1;
                    cola.push({posz1, posz2});
                }
            }
        }
    }

    if(bolas_eliminadas == n){
        cout << "Yes\n";
    }
    else{
        cout << "No\n";
    }
    

    return 0;
}