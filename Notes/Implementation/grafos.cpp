#include <bits/stdc++.h>
using namespace std;

void DFS(vector<vector<int>>& grafo, vector<bool>& visitado, int inicio) {
    stack<int> pila;
    pila.push(inicio);

    while (!pila.empty()) {
        int actual = pila.top();
        pila.pop();

        if (!visitado[actual]) {
            cout << actual << " ";
            visitado[actual] = true;

            for (int vecino : grafo[actual]) {
                if (!visitado[vecino]) {
                    pila.push(vecino);
                }
            }
        }
    }
}

void BFS(vector<vector<int>>& grafo, vector<bool>& visitado, int inicio) {
    queue<int> cola;
    cola.push(inicio);
    visitado[inicio] = true;

    while (!cola.empty()) {
        int actual = cola.front();
        cola.pop();

        cout << actual << " ";

        for (int vecino : grafo[actual]) {
            if (!visitado[vecino]) {
                visitado[vecino] = true;
                cola.push(vecino);
            }
        }
    }
}

int main() {
    int V = 6;  // Número de vértices
    vector<vector<int>> grafo(V);

    // Agregar aristas al grafo
    grafo[0].push_back(1);
    grafo[1].push_back(0);

    grafo[0].push_back(2);
    grafo[2].push_back(0);

    grafo[1].push_back(3);
    grafo[3].push_back(1);

    grafo[1].push_back(4);
    grafo[4].push_back(1);

    grafo[2].push_back(5);
    grafo[5].push_back(2);

    for (int i = 0; i < V; i++) {
        // Estoy viendo grafo[i]
        cout << "El nodo " << i << " tiene de vecinos: ";
        for (int j = 0; j < grafo[i].size(); j++){
            cout << grafo[i][j] << ' ';
        }
        cout << '\n';
    }

    vector<bool> visitado(V, false);

    cout << "DFS desde el vértice 0: ";
    DFS(grafo, visitado, 0);
    cout << endl;

    // // Reiniciar el vector de visitados
    // fill(visitado.begin(), visitado.end(), false);

    // cout << "BFS desde el vértice 0: ";
    // BFS(grafo, visitado, 0);
    // cout << endl;

    return 0;
}
