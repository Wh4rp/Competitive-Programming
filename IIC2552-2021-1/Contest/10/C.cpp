#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)
#define rep_(i, k, n) for (int i = k; i < n; ++i)
using ll = long long;

vector<ll> v;
ll n, aux;

ll sol(int l, int r, int base){

	if(l == r) return 1;

	ll new_base = *min_element(v.begin() + l, v.begin() + r + 1);

	int i = l, l1, sum = new_base - base;

	while(i <= r){
		if(v[i] > new_base){
			l1 = i;
			while(v[i] > new_base && i <= r){
				i++;
			}
			sum += sol(l1, i - 1, new_base);
		}
		i++;
	}
	
	return min(sum, r - l + 1);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.setf(ios::fixed);
  cout.precision(10);
  
  cin >> n;
  rep(i, n) {
  	cin >> aux;
  	v.push_back(aux);
  }
  cout << sol(0, n - 1, 0) << '\n';
  
  return 0;
}