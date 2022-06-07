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
  int t[n + 5], cont[5005], aux_cont[n + 1], maxi;
  memset(cont, 0, sizeof(cont));
  rep(i, n){
    cin >> t[i];
  }
  rep(i, n){
    memset(aux_cont, 0, sizeof(aux_cont));
    aux_cont[t[i]]++;
    maxi = t[i];
    cont[maxi]++;
    rep_(j, i + 1, n){
      aux_cont[t[j]]++;
      if(aux_cont[maxi] == aux_cont[t[j]]){
        maxi = min(maxi, t[j]);
      }
      if(aux_cont[maxi] < aux_cont[t[j]]){
        maxi = t[j];
      }
      cont[maxi]++;
    }
  }
  rep_(i, 1, n + 1){
    cout << cont[i] << ' ';
  }
  cout << '\n';
  
  return 0;
}