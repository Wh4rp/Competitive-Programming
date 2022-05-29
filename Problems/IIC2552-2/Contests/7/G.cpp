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
  
  Dinic din(2);
  din.add_edge(0,1,10);

  int N, M, G;
  while(cin >> N >> M >> G, N != 0 && M != 0 && G != 0){
  	int Pj[N][N], Pts[N];
  	rep(i, N){
  		Pts[i] = 0;
  		rep_(j, i + 1, N){
  			Pj[i][j] = 0;
  		}
  	}
	int a, b;
  	char win;
  	rep(i, G){
  		cin >> a >> win >> b;
  		if(win == '='){
  			Pts[a]++;
  			Pts[b]++;
  		}
  		else{
  			Pts[b] += 2;
  		}

  		Pj[min(a,b)][max(a,b)]++;
  	}

  	rep_(i, 1, N){
  		Pts[0] += 2 * (M - Pj[0][i]);
  		Pj[0][i] = M;
  	}
  	bool solved = false;
	rep_(i, 1, N){
		if(Pts[i] >= Pts[0]){
			cout << "N\n";
			solved = true;
			break;
		}
  	}
  	if(solved)
  		continue;

  	Dinic Sonic(2 + N*(N - 1)/2 + N);
	int s = 0, t = 2 + N*(N - 1)/2 + N - 1;

	rep_(i, 1, N){
		Sonic.add_edge(i, t, Pts[0] - 1 - Pts[i]);
	}
	int pts_acumlado = 0;
	int aux = N + 1;

	rep_(i, 1, N - 1){
  		rep_(j, i + 1, N){
  			int pts = 2 * (M - Pj[i][j]);
  			Sonic.add_edge(s, aux, pts);
  			Sonic.add_edge(aux, i, pts);
  			Sonic.add_edge(aux, j, pts);
  			aux++;
  			pts_acumlado += pts; 
  		}
  	}

  	if(Sonic.max_flow(s, t) == pts_acumlado)
  		cout << "Y\n";
  	else
  		cout << "N\n";
  }

  return 0;
}