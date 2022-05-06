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
  
  ll n, m, k;
  cin >> n >> m >> k;
  ll sol[n];
  rep(i, n){
  	cin >> sol[i];
  }

  ll array[m][3];

  rep(i, m){
  	ll l, r, d;
  	cin >> l >> r >> d;
  	array[i][0] = l - 1;
  	array[i][1] = r - 1;
  	array[i][2] = d;
  }

  vector<ll> U(m + 1, 0);

  rep(i, k){
  	ll l, r;
  	cin >> l >> r;
  	U[l - 1]++;
  	U[r]--;
  }
  ll sum = 0;
  rep(i, m + 1){
  	sum += U[i];
  	U[i] = sum;
  }
  vector<ll> U2(n + 1, 0);

  rep(i, m){
  	U2[array[i][0]] += U[i] * array[i][2];
  	U2[array[i][1] + 1] -= U[i] * array[i][2];
  }

  ll sum2 = 0;
  rep(i, n + 1){
  	sum2 += U2[i];
  	sol[i] += sum2;
  }

  rep(i, n){
  	cout << sol[i] << " \n"[i == n-1];
  }

  return 0;
}