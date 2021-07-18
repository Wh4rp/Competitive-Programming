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

  string s;
  int n, radmin = 10000, ladomin = 10000, aux;

  priority_queue<int> cube, cylinder;
  vector<pair<string, int>> sol;

  cin >> n;
  rep(i, n){
  	cin >> s;
  	cin >> aux;
  	if(s == "cube")
  		cube.push(aux);
  	else
  		cylinder.push(aux);
  }
  while(!cube.empty() && !cylinder.empty()){
  	int Lcubo = cube.top();
  	int Rcilindro = cylinder.top();
  	bool cancb = true, cancyl = true;

  	if(ladomin < Lcubo){
  		cancb = false;
  	}
  	if(radmin < Rcilindro){
  		cancyl = false;
  	}
  	if(!cancb && !cancyl){
  		cout << "impossible\n";
  		return 0;
  	}

  	if(!cancyl || Lcubo > 2 * Rcilindro){
  		sol.push_back({"cube", Lcubo});
  		cube.pop();
  		radmin = Lcubo / 2;
  		ladomin = Lcubo;
  		continue;
  	}

  	else {
  		sol.push_back({"cylinder", Rcilindro});
  		cylinder.pop();
  		radmin = Rcilindro;
  		ladomin = Rcilindro * sqrt(2);
  		continue;
  	}
  	
  }


  for(int i = n - 1; i >=0; i--){
  	cout << sol[i].first << " " << sol[i].second << '\n';
  }
  return 0;
}