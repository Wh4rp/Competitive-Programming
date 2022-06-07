#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)
#define rep_(i, k, n) for (int i = k; i < n; ++i)
using ll = long long;

// a sobre 2

ll f(ll a){
  return (a) * (a - 1) / 2;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.setf(ios::fixed);
  cout.precision(10);

  // pos, min, max
  vector<pair<ll,pair<ll,ll>>> event;
  ll n, aux, sol = 0;
  cin >> n;
  ll v[n + 5];
  rep(i, n){
    cin >> v[i];
  }

  ll mini = 10000000, maxi = -1, len = 0;
  rep(i, n){
    if(mini > v[i] || maxi < v[i]){
      mini = min(mini, v[i]);
      maxi = max(maxi, v[i]);
      event.push_back({i, {mini, maxi}});
      len++;
    }
  }
  rep(i, len){
    sol += event[i].second.second - event[i].second.first;
  }
  for(auto x : event){
    cout << x.first << ": " << x.second.first << ' ' << x.second.second << '\n';
  }
  return 0;
}