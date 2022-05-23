#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define REP(i,k,n) for (i = k; i <= n; ++i) 
#define REPR(i,k,n) for (i = k; i >= n; --i) 

using ll = long long;
int a, b, cont;
bool visited[100][100];
string row[100];

int move_row[] = {0, 0, 1, -1};
int move_col[] = {1, -1, 0, 0};

void dfs(int i, int j){
  visited[i][j] = true;
  rep(k, 4){
    int r = i + move_row[k];
    int c = j + move_col[k];
    if(!visited[r][c] && r >= 0 && r < a && c >= 0 && c < b){
      dfs(r, c);
    }
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.setf(ios::fixed);
  cout.precision(10);
  int x = 1;
  while(cin >> a >> b){
    rep(i, a){
      cin >> row[i];
    }
    rep(i, a){
      rep(j, b){
        if(row[i][j] == '#')
          visited[i][j] = true;
        else
          visited[i][j] = false;
      }
    }
    cont = 0;
    rep(i, a){
      rep(j, b){
        if(!visited[i][j]){
          dfs(i, j);
          cont++;
        }
      }
    }
    cout << "Case " << x << ": " << cont << '\n';
    x++;
  }
	return 0;
}