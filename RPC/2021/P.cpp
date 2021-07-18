#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)
#define rep_(i, k, n) for (int i = k; i <= n; ++i)
using ll = long long;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.setf(ios::fixed);
  cout.precision(10);
  
  int t;
  bool validall = true;
  string line;
  cin >> t;
  getline(cin, line);
  set<string> s;
  rep_(i, 1, t) {
  	string aux;
  	getline(cin, line);
  	if(validall){
  		stringstream ss;
	  	ss << line;
	  	ss >> aux;
	  	if(aux == "->"){
	  		while(ss >> aux){
	  			s.insert(aux);
	  		}
	  	}
	  	else{
	  		while(aux != "->"){
	  			if(s.count(aux) != 1){
	  				cout << i << '\n';
	  				validall = false;
	  				break;
	  			}
	  			ss >> aux;
	  		}
	  		while(ss >> aux){
	  			s.insert(aux);
	  		}
	  	}
  	}
  	
  }
  if(validall)
  	cout << "correct\n";
  return 0;
}