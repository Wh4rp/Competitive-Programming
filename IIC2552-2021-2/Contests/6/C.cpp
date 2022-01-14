// buena parte del tarjan lo saque de
// https://gist.github.com/APwhitehat/e2ae94b811defc7407bc320f98fd268b
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#include <cstdlib>
using namespace std;
#define rep(i, n) for (ll i = 0; i < n; ++i)
#define rep_(i, k, n) for (ll i = k; i < n; ++i)
#define MAX 1000005
using ll = long long;

ll fun[MAX], Newfun[MAX], ids[MAX], low[MAX], id=0, NewIds[MAX], NewId = 0, e;
vector<ll> dp;
stack<ll> S;
set<pair<ll, ll>> edges;
bool onStack[MAX];

vector<vector<ll>> G, scc, NewG;

void dfs(ll p){
  S.push(p);
  onStack[p] = true;
  ids[p] = low[p] = id++;

  for(ll q : G[p]){
    if(ids[q] == -1){
      dfs(q);
      low[p] = min(low[p], low[q]);
    }
    else if(onStack[q])
      low[p]=min(low[p], ids[q]);
  }
  if(ids[p]==low[p]){
    while(true){
      ll v = S.top();
      S.pop();
      onStack[v] = false;
      NewIds[v] = NewId;
      Newfun[NewId] += fun[v];
      if(p == v)
        break;
    }
    NewId++;
  }
}

ll max_fun(ll p){
  if(dp[p] != -1){
    return dp[p];
  }

  if(p == NewIds[e]){
    return Newfun[p];
  }

  ll ans = Newfun[p], ans_1 = 0;
  for(int q : NewG[p]){
    ans_1 = max(ans_1, max_fun(q));
  }
  ans += ans_1;
  return dp[p] = ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.setf(ios::fixed);
  cout.precision(10);
  
  ll n, m, s, aux;
  cin >> n >> m >> s >> e;
  s--, e--;
  G.assign(n, vector<ll>());

  rep(i, n){
  	cin >> aux;
    fun[i] = aux;
    Newfun[i] = 0;
    onStack[i] = false;
    ids[i] = -1;
    low[i] = -1;
  }

  rep(i, m){
  	ll a, b;
  	cin >> a >> b;
  	G[--a].push_back(--b);
  }



  rep(i,n){
    if(ids[i] == -1)
      dfs(i);
  }

  NewG.assign(NewId, vector<ll>());

  rep(i, n){
    for(auto j : G[i]){
      if(NewIds[i] != NewIds[j]){
        edges.insert({NewIds[i], NewIds[j]});
      }
    }
  }

  NewG.assign(NewId, vector<ll>());

  for(auto edge : edges){
    NewG[edge.first].push_back(edge.second);
  }

  dp.assign(NewId, -1);

  cout << max_fun(NewIds[s]);
  return 0;
}