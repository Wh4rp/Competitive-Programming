#include <bits/stdc++.h>
using namespace std;

void DFS(vector<vector<int>>& grafo, vector<bool>& visitado, int inicio) {
    stack<int> pila;
    pila.push(inicio);

    while (!pila.empty()) {
        int actual = pila.top();
        pila.pop();

        if (!visitado[actual]) {
            // cout << actual << " ";
            visitado[actual] = true;

            for (int vecino : grafo[actual]) {
                if (!visitado[vecino]) {
                    pila.push(vecino);
                }
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grafo(n + 1);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        grafo[u].push_back(v);
        grafo[v].push_back(u);
    }

    vector<bool> visitado(n, false);
    vector<int> representantes;
    for (int i = 1; i <= n; i++) {
        if (!visitado[i]) {
            DFS(grafo, visitado, i);
            representantes.push_back(i);
        }
    }

    cout << representantes.size() - 1 << '\n';

    for (int i = 0; i < representantes.size() - 1; i++) {
        cout << representantes[i] << ' ' << representantes[i + 1] << '\n';
    }

    return 0;
}
