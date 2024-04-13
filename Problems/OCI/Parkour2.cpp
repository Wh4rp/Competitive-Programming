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

    // solucion con Dijkstra

    int n, m;
    cin >> n >> m;
    vector<vector<bool>> safe(n, vector<bool>(m, false));
    rep(i, n){
        int p;
        cin >> p;
        rep(j, p){
            int stage;
            cin >> stage;
            safe[i][stage] = true;
        }
    }

    vector<vector<int>> dist(n, vector<int>(m, 1e9));
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    pair<int, int> source = {0, m-1};
    dist[source.first][source.second] = 0;
    priority_queue<pair<int,  pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int,  pair<int, int>>>> pq;
    pq.push({0, source});
    while(!pq.empty()){
        auto u = pq.top();
        int tower = u.second.first;
        int stage = u.second.second;
        pq.pop();
        if(visited[tower][stage])
            continue;
        visited[tower][stage] = true;
        // ver los vecinos
        if(tower != n - 1){
            rep(next_stage, m){
                if(safe[tower+1][next_stage]){
                    int next_dist;
                    if(next_stage < stage)
                        next_dist = 0;
                    else
                        next_dist = next_stage - stage;
                    if(!visited[tower+1][next_stage] || dist[tower+1][next_stage] > dist[tower][stage] + next_dist){
                        dist[tower+1][next_stage] = dist[tower][stage] + next_dist;
                        pq.push({dist[tower+1][next_stage], {tower+1, next_stage}});
                    }
                }
            }
        }
    }

    int ans = *min_element(dist[n-1].begin(), dist[n-1].end());

    cout << ans << '\n';

    return 0;
}