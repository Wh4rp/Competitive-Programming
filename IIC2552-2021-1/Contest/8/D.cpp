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
  
  int n, k, cont = 0;
  cin >> n >> k;
  int a[n];
  cin >> a[0];
  rep_(i, 1, n){
    cin >> a[i];
    cont += max(0, k - (a[i - 1] + a[i]));
    a[i] += max(0, k - (a[i - 1] + a[i]));
  }
  cout << cont << '\n';
  rep(i, n) cout << a[i] << " \n"[i == n - 1];
  
  return 0;
}