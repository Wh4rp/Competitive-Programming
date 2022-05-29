#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)
#define rep_(i, k, n) for (int i = k; i < n; ++i)
using ll = long long;

int cols, rows, N = 0, memo[2050][20];
int moves_row[4] = {0, 0, 1, -1}, moves_col[4] = {1, -1, 0, 0};
string grid[20];
int dis[20][20], dis_temp[20][20];
vector<pair<int, int>> dirties;

void search_trashdies_and_init(){
  rep(i, rows){
    rep(j, cols){
      if(grid[i][j] == '*'){
        dirties.push_back({i, j});
        N++;
      }
      if(grid[i][j] == 'o'){
        dirties.insert(dirties.begin(), {i, j});
        N++;
      }
    }
  }
}

void bfs(int row_init, int col_init){
  memset(dis_temp, -1, sizeof(dis_temp));
  queue<pair<int, int>> s;
  s.push({row_init, col_init});
  dis_temp[row_init][col_init] = 0;
  while (!s.empty())
  {
    auto now = s.front();
    int row = now.first, col = now.second;
    s.pop();
    rep(i, 4){
      int col_next = col + moves_col[i];
      int row_next = row + moves_row[i];
      if(0 <= col_next && col_next < cols && 0 <= row_next && row_next < rows){
        if(grid[row_next][col_next] != 'x' && dis_temp[row_next][col_next] == -1){
          s.push({row_next, col_next});
          dis_temp[row_next][col_next] = dis_temp[row][col] + 1;
        }
      }
    }
  }
}

void computing_distances(){
  rep(i, N){
    bfs(dirties[i].first, dirties[i].second);
    rep_(j, i + 1, N){
      dis[i][j] = dis_temp[dirties[j].first][dirties[j].second];
      dis[j][i] = dis[i][j];
    }
  }
}

bool verify_distances(){
  rep(i, N){
    rep_(j, i + 1, N){
      // cout << i << " " << j << ": " << dis[i][j] << '\n';
      if(dis[i][j] == -1)
        return false;
    }
  }
  return true;
}

int DP(int mask, int i){
  if(mask == 0)
    return 0;
  if(memo[mask][i] != -1)
		return memo[mask][i];
  int ans = 20000;
  rep_(j, 1, N){
    if(mask & (1 << j)){
      ans = min(ans, dis[i][j] + DP(mask^(1 << j), j));
    }
  }
  return memo[mask][i] = ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.setf(ios::fixed);
  cout.precision(10);
  
  while(cin >> cols >> rows, cols + rows != 0){
    rep(i, rows)
      cin >> grid[i];
    
    search_trashdies_and_init();
    computing_distances();
    if(!verify_distances()){
      cout << "-1\n";
    }
    else{
      memset(memo, -1, sizeof(memo));
      cout << DP((1<<N) - 2, 0) << '\n';
    }
    dirties.clear();
    N = 0;
  }

  return 0;
}