#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)
#define rep_(i, k, n) for (int i = k; i < n; ++i)
using ll = long long;

ll cantidad_hijos[300005];
ll memo[300005];

ll calcular_hijos(int nodo, vector<vector<int>> &arbol) {
    if(cantidad_hijos[nodo] != -1) return cantidad_hijos[nodo];
    cantidad_hijos[nodo] = 0;
    for(auto hijo : arbol[nodo]) {
        cantidad_hijos[nodo] += calcular_hijos(hijo, arbol) + 1;
    }
    return cantidad_hijos[nodo];
}

ll dp(int nodo, vector<vector<int>> &arbol) {
    if(memo[nodo] != -1) return memo[nodo];
    if(cantidad_hijos[nodo] == 0)
        return memo[nodo] = 0;
    if(arbol[nodo].size() == 1) {
        int hijo = arbol[nodo][0];
        return memo[nodo] = cantidad_hijos[hijo];
    }
    if(arbol[nodo].size() == 2){
        int hijo1 = arbol[nodo][0];
        int hijo2 = arbol[nodo][1];
        return memo[nodo] = max(dp(hijo1, arbol) + cantidad_hijos[hijo2], dp(hijo2, arbol) + cantidad_hijos[hijo1]);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.setf(ios::fixed);
    cout.precision(10);

    int t;
    cin >> t;
    while(t--){
        rep(i, 300005) {
            cantidad_hijos[i] = -1;
            memo[i] = -1;
        }
        int n;
        cin >> n;
        vector<vector<int>> grafo(n+5), arbol(n+5);
        rep(i, n-1) {
            int a, b;
            cin >> a >> b;
            grafo[a].push_back(b);
            grafo[b].push_back(a);
        }
        // bfs para crear el arbol
        queue<int> q;
        q.push(1);
        vector<bool> visited(n+5, false);
        visited[1] = true;
        while(!q.empty()) {
            int nodo = q.front();
            q.pop();
            for(auto vecino : grafo[nodo]) {
                if(!visited[vecino]) {
                    visited[vecino] = true;
                    arbol[nodo].push_back(vecino);
                    q.push(vecino);
                }
            }
        }
        calcular_hijos(1, arbol);
        cout << dp(1, arbol) << '\n';
    }

    return 0;
}