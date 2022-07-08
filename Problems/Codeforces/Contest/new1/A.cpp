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
  
  int t;
  cin >> t;
  while (t--) {
    ll n, l, aux;
    cin >> n >> l;
    vector<int> a(l, 0), b(l, 0);
    rep(i, n){
      cin >> aux;
      rep(j, l){
        if(1<<j & aux) a[j]++;
        else b[j]++;
      }
    }
    ll ans = 0;
    rep(i, l){
      if(a[i] > b[i]) ans |= 1<<i;
    }
    cout << ans << '\n';
  }
  
  return 0;
}
