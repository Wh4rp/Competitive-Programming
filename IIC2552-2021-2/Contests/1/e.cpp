#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (ll i = 0; i < n; ++i)
#define rep_(i, k, n) for (ll i = k; i < n; ++i)
using ll = long long;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.setf(ios::fixed);
  cout.precision(10);
  
  ll t, a, b, c, n, sol, fk;
  cin >> t;
  while(t--){
    sol = 1LL;
    cin >> a >> b >> c >> n;
    priority_queue<ll> L;
    L.push(1LL);
    priority_queue<ll, vector<ll>, greater<ll> > R;

    rep_(i, 2, n + 1){

      fk = (a * L.top() + b * i + c) % 1000000007;
      sol += fk;

      if(i % 2 == 0)
        R.push(fk);
      else
        L.push(fk);
      if(L.top() > R.top()){
        ll auxL = L.top(), auxR = R.top();
        L.pop();
        R.pop();
        L.push(auxR);
        R.push(auxL);
      }
    }
    cout << sol << '\n';
  }
  return 0;
}