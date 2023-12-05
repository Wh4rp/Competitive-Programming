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

    // Make a dikstra algo with priority queue
    // O(m log n)
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> g(n);
    rep(i, m){
        int a, b, w;
        cin >> a >> b >> w;
        g[a].push_back({b, w});
        g[b].push_back({a, w});
    }
    vector<int> dist(n, 1e9);
    vector<bool> visited(n, false);
    int source = 0;
    dist[source] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, source});
    while(!pq.empty()){
        int u = pq.top().second;
        pq.pop();
        if(visited[u])
            continue;
        visited[u] = true;
        for(auto v: g[u]){
            if(!visited[v.first] || dist[v.first] > dist[u] + v.second){
                dist[v.first] = dist[u] + v.second;
                pq.push({dist[v.first], v.first});
            }
        }
    }

    rep(i, n){
        cout << dist[i] << ' ';
    }
    cout << '\n';

    return 0;
}