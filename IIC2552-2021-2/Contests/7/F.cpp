#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)
#define rep_(i, k, n) for (int i = k; i < n; ++i)
using ll = long long;

struct Dinic {
    struct Edge { int to, rev; ll f, c; };
    int n, t_; vector<vector<Edge>> G;
    vector<ll> D;
    vector<int> q, W;
    bool bfs(int s, int t) {
        W.assign(n, 0); D.assign(n, -1); D[s] = 0;
        int f = 0, l = 0; q[l++] = s;
        while (f < l) {
            int u = q[f++];
            for (const Edge &e : G[u]) if (D[e.to] == -1 && e.f < e.c)
                D[e.to] = D[u] + 1, q[l++] = e.to;
        }
        return D[t] != -1;
    }
    ll dfs(int u, ll f) {
        if (u == t_) return f;
        for (int &i = W[u]; i < (int)G[u].size(); ++i) {
            Edge &e = G[u][i]; int v = e.to;
            if (e.c <= e.f || D[v] != D[u] + 1) continue;
            ll df = dfs(v, min(f, e.c - e.f));
            if (df > 0) { e.f += df, G[v][e.rev].f -= df; return df; }
        }
        return 0;
    }
    Dinic(int N) : n(N), G(N), D(N), q(N) {}
    void add_edge(int u, int v, ll cap) {
        G[u].push_back({v, (int)G[v].size(), 0, cap});
        G[v].push_back({u, (int)G[u].size() - 1, 0, 0}); // Use cap instead of 0 if bidirectional
    }
    ll max_flow(int s, int t) {
        t_ = t; ll ans = 0;
        while (bfs(s, t)) while (ll dl = dfs(s, LLONG_MAX)) ans += dl;
        return ans;
    }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.setf(ios::fixed);
  cout.precision(10);

  int n;

  while(cin >> n){
    int a, b, s = 0, t = 2 * n + 1;
    vector<pair<int, int>> intenciones(1);
    vector<int> votos(n + 1, 0);

    rep_(i, 1, n + 1){
        cin >> a >> b;
        votos[a]++;
        votos[b]++;
        intenciones.push_back({a, b});
    }

    int ans = 0;

    rep_(i, 1, n + 1){

        Dinic Sonic(2*(n + 1));

        rep_(j, 1, n + 1){
            if(i != j){
                if(intenciones[j].first != i && intenciones[j].second != i){
                    a = intenciones[j].first;
                    b = intenciones[j].second;
                    Sonic.add_edge(s, j, 1);
                    Sonic.add_edge(j, n + a, 1);
                    Sonic.add_edge(j, n + b, 1);
                }
            }
            
        }
        int wvote1 = intenciones[i].first, wvote2 = intenciones[i].second;
        rep_(j, 1, n + 1){
            if(j == wvote1 || j == wvote2){
                Sonic.add_edge(n + j, t, votos[i] - 2);
            }
            else{
                Sonic.add_edge(n + j, t, votos[i] - 1);
            }
        }

        if(Sonic.max_flow(s, t) != n - 1 - votos[i]){
            ans++;
        }
    }
    cout << ans << '\n';
  }
  
  return 0;
}