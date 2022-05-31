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
  
  ll n, sum, sum_aux = 0, aux;
  cin >> n;
  sum = n * (n + 1) / 2;
  rep(i, n - 1){
    cin >> aux;
    sum_aux += aux;
  }
  cout << sum - sum_aux << '\n';
  
  return 0;
}