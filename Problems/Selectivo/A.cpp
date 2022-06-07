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
  
  int n, aux, len = 1, ceros = 0;
  cin >> n;
  rep(i, n){
    cin >> aux;
    if(aux >= len){
      len = aux + 1;
      ceros = 0;
    }
    else{
      ceros += (len - aux);
    }
  }

  cout << len << " " << ceros << endl;
  
  return 0;
}