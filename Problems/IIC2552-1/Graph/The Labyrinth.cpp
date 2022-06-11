#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)
#define rep_(i, k, n) for (int i = k; i < n; ++i)
using ll = long long;

ll n, m, cont = 0;
pair<int, int> moves[4] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
string grid[1005];
vector<string> gridsol[1005];
ll gridset[1005][1005];

void dfs(int i, int j){
  gridset[i][j] = cont;
  rep(k, 4){
    int ix = i + moves[k].first, jx = j + moves[k].second;
    if(0 <= ix && ix < n && 0 <= jx && jx < m){
      if(grid[ix][jx] == '.' && gridset[ix][jx] == -1){
        dfs(ix, jx);
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.setf(ios::fixed);
  cout.precision(10);
  
  cin >> n >> m;
  rep(i, n){
    cin >> grid[i];
  }
  memset(gridset, -1, sizeof(gridset));
  rep(i, n){
    rep(j, m){
      if(grid[i][j] == '.' && gridset[i][j] == -1){
        cont++;
        dfs(i, j);
      }
    }
  }
  int v[1000005];
  memset(v, 0, sizeof(v));
  rep(i, n){
    rep(j, m){
      if(gridset[i][j] != -1){
        v[gridset[i][j]]++;
      }
    }
  }
  rep(i, n){
    rep(j, m){
      if(grid[i][j] == '*'){
        set<ll> s;
        rep(k, 4){
          int ix = i + moves[k].first, jx = j + moves[k].second;
          if(0 <= ix && ix < n && 0 <= jx && jx < m){
            if(gridset[ix][jx] != -1){
              s.insert(gridset[ix][jx]);
            }
          }
        }
        ll sol = 1;
        for(int x : s){
          sol += v[x];
        }
        gridsol[i].push_back(to_string(sol%10));
      }
      else{
        gridsol[i].push_back(".");
      }
    }
  }
  rep(i, n){
    for(auto x : gridsol[i])
      cout << x;
    cout << '\n';
  }
  return 0;
}