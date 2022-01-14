#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)
#define rep_(i, k, n) for (int i = k; i < n; ++i)
using ll = long long;

struct Node {
    int mod;
    string num;
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.setf(ios::fixed);
  cout.precision(10);
  
  int d, m, caso = 1;

  while(cin >> d >> m){
  	bool mods[d + 5];
  	rep(i, d){
  		mods[i] = true;
  	}
  	string sol = "-1";
  	bool numsfake[10];
  	rep(i, 10)
  		numsfake[i] = true;
  	vector<int> nums;
  	rep(i, m){
  		int aux; 
  		cin >> aux;
  		numsfake[aux] = false;
  	}

  	queue<Node> Q;

  	if(numsfake[0]){
  		nums.push_back(0);
  	}
  	
  	rep_(i, 1, 10){
  		if(numsfake[i]){
  			nums.push_back(i);
  			Q.push(Node({i%d, to_string(i)}));
  			mods[i%d] = false;
  		}
  	}
  	while(!Q.empty()){
  		Node aux = Q.front();
	  	Q.pop();
	  	if(aux.mod == 0){
	  		sol = aux.num;
	  		break;
	  	}
  		for(int i : nums){
  			int mod = (aux.mod * 10 + i) % d;
  			if(mods[mod]){
  				Q.push(Node({mod, aux.num + to_string(i)}));
  				mods[mod] = false;
  			}
  		}
  	}

  	cout << "Case " << caso++ << ": " << sol << "\n";
  }
  
  return 0;
}