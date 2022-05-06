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
  
  ll n, k, sol = 0, auxsol;
  cin >> n >> k;

  vector<ll> joshas(n);
  for(ll& x : joshas)
    cin >> x;

  rep(i, min(k + 1, n + 1)){
  	rep_(j, 0, min(k - i + 1, n - i + 1)){
      vector<ll> auxv;
      for(ll i1 = 0; i1 < i; i1++){
        auxv.push_back(joshas[i1]);
      }
      for(ll i2 = n - 1; i2 > n - j - 1; i2--){
        //cout << joshas[i2] << ' ';
        auxv.push_back(joshas[i2]);
      }
      ll dev = min(i + j, k - (i + j));

      sort(auxv.begin(), auxv.end());

      auxsol = 0;
      for(ll i3 = 0; i3 < i + j; i3++){
        auxsol += auxv[i3];
      }

      for(ll i3 = 0; i3 < dev; i3++){
        if(auxv[i3] >= 0)
          break;
        auxsol -= auxv[i3];
      }
      sol = max(sol, auxsol);
  	}
  }
  cout << sol << '\n';
  return 0;
}