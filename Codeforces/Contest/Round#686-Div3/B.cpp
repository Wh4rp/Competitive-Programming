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
  while(t--){
  	int n, aux;
  	cin >> n;
  	vector <int> v(n, 0);
  	vector <int> w(n, 0);
  	rep(i, n){
  		cin >> aux;
  		v[aux-1]++;
  		w[aux-1] = i + 1;
  	}
  	bool sol = true;
  	int i = 0;
  	for(int x : v){
  		if(x == 1){
  			cout << w[i] << '\n';
  			sol = false;
  			break;
  		}
  		i++;
  	}
  	if(sol){
  		cout << "-1\n";
  	}

  }
  
  return 0;
}