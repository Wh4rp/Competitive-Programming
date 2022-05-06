#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)
#define rep_(i, k, n) for (int i = k; i < n; ++i)
using ll = long long;

int rest, n, k;
vector<int> V, W;
void merge(int i, int j){
	if(j - i > 1 ){
		int m = (i + j) / 2;
		merge(i, m);
		merge(m, j);
		if(rest != k){
			sort(V.begin() + i, V.begin() + j);
			rest -= 2;
		}
	}
	
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.setf(ios::fixed);
  cout.precision(10);
  
  
  cin >> n >> k;
  if(k%2 == 0 || 2 * n - 1 < k) cout << "-1\n";
  else {
  	rest = 2 * n - 1;
  	rep(i, n){
  		V.push_back(n - i);
  	}
  	merge(0, n);
  	for(int x : V)
  		cout << x << " ";
  	cout << "\n";
  }
  
  return 0;
}