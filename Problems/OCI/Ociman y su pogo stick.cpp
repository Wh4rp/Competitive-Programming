#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> ciudad;
int d;
int n;
int x, y;


int bfs(int u, int v){
	vector<vector<int>> dist(n+1, vector<int>(n+1, -1));
	queue<pair<int, int>> q;
	dist[u][v] = 0;
	q.push({u, v});

	while(!q.empty()){
		// ver cuales son sus vecinos
		int i = q.front().first;
		int j = q.front().second;
		if(i == x && j == y) {
			return dist[i][j];
		}
		q.pop();

		for(int ii = i - d; ii <= i + d; ii++){
			for(int jj = j - d; jj <= j + d; jj++){
				if(ii > 0 && ii <= n && jj > 0 && jj <= n){
					if(dist[ii][jj] == -1 && ciudad[ii][jj] == 1){
						dist[ii][jj] = dist[i][j] + 1;
						q.push({ii, jj});
					}
				}
			}
		}
	}
	// Imprimer las distancias
	// for(int j = 1; j <= n; j++){
	// 	for(int i = 1; i <= n ; i++){
	// 		if(dist[i][j] == -1) cout << "x ";
	// 		else if(i == x && j == y) cout << "|" << dist[i][j] << "| ";
	// 		else cout << dist[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }

	return dist[x][y];
}

int main(){
	cin >> n >> d;
	ciudad.resize(n+1, vector<int>(n+1));
	int u, v;
	cin >> u >> v;
	cin >> x >> y;
	// El i-ésimo entero en la línea j-ésima contendrá un 1 si Ociman puede saltar sobre el edificio en las coordenadas (i, j) o 0 en caso contrario. 
	for(int j = 1; j <= n; j++){
		for(int i = 1; i <= n ; i++){
			cin >> ciudad[i][j];
		}
	}
	cout << bfs(u, v) << endl;
	return 0;
}