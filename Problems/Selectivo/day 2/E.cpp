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
  
  int n;
  cin >> n;
  string Tiling[n];
  int count[n];
  memset(count, 0, sizeof(count));
  rep(i, n){
    cin >> Tiling[i];
    rep(j, n){
      if(Tiling[i][j] == '.'){
        count[i]++;
      }
    }
  }
  rep(i, n - 2){
    rep_(j, 1, n - 1){
      if(Tiling[i][j] == '.'){
        if(Tiling[i+1][j-1] == '.' && Tiling[i+1][j] == '.' && Tiling[i+1][j+1] == '.' && Tiling[i+2][j] == '.'){
          Tiling[i][j] = '#';
          count[i]--;
          Tiling[i+1][j-1] = '#';
          Tiling[i+1][j] = '#';
          Tiling[i+1][j+1] = '#';
          count[i+1]-=3;
          Tiling[i+2][j] = '#';
          count[i+2]--;
        }
        else{
          cout << "NO\n";
          return 0;
        }
      }
    }
    if(count[i] != 0){
      cout << "NO\n";
      return 0;
    }
  }
  if(count[n-2] != 0 || count[n-1] != 0){
    cout << "NO\n";
  }
  else{
    cout << "YES\n";
  }
  
  return 0;
}