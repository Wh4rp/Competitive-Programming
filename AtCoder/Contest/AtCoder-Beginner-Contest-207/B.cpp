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
  
  ll a, b, c, d;
  cin >> a >> b >> c >> d;

  if(d*c - b <= 0)
    cout << "-1\n";
  else{
    ll t = 0;
    while(a > t*(d*c - b)){
      t++;
    }
    cout << t <<"\n";
  }
  return 0;
}