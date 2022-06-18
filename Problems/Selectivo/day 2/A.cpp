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

  int n, stop = -1;
  double po = 0.5;
  double ans = 0;
  double cost = 1 / sqrt(sqrt(2));
  double r = 0.5;
  cin >> n;
  n--;
  vector<int> v(n);
  rep(i, n){
    cin >> v[i];
  }

  double sum = 0;

  rep(i, n){
    sum += v[i] * po;
    if(sum >= 1.0){
      stop = i;
      break;
    }
    po *= 0.5;
  }
  for(int i = stop; i >= 0; i--){
    ans += v[i] * cost;
    cost *= r;
  }

  cout << "impossible\n";
  
  return 0;
}