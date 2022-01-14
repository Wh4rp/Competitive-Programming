#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define REP(i,k,n) for (i = k; i <= n; ++i)
#define REPR(i,k,n) for (i = k; i >= n; --i)
using ll = long long;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.setf(ios::fixed);
  cout.precision(10);
  int n, m,sol=0; cin >> n >> m;
  string hotel[n];

  for(int i=0; i<n; i++)
  {
    cin >> hotel[i];
  }
  int mov1[4] = {1, -1, 0, 0};
  int mov2[4] = {0, 0, 1, -1};
  
  for(int ii=0; ii<n; ii++)
  {
    for(int jj=0; jj<m; jj++)
    {
      if(hotel[ii][jj]!='#')
      {
        sol++;
        queue<pair<int, int>> q;
        q.push({ii, jj});
        while(!q.empty())
        {
          int i = q.front().first, j = q.front().second;
          for(int k =0; k < 4; k++){
            int i1 = i + mov1[k], j1 = j + mov2[k];
            if(0 <= i1 && i1 < n && 0 <= j1 && j1 < m){
              if(hotel[i1][j1] != '#'){
                q.push({i1, j1}); 
                hotel[i1][j1] ='#';
              }
            }
          }
          hotel[i][j]='#';
          q.pop();
        }
      }
    }
  }
  
  cout << sol << '\n';
	
  return 0;
}
