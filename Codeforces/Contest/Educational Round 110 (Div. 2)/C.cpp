#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)
#define rep_(i, k, n) for (int i = k; i < n; ++i)
using ll = long long;
bool fun(char a, char b, int dis){
	if(a == '?' || b == '?') return true;
	if(dis % 2){
		if(a != b) return true;
		else return false;
	}
	else{
		if(a != b) return false;
		else return true;
	}
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.setf(ios::fixed);
  cout.precision(10);
  
  int t;
  cin >> t;
  while(t--){
  	string s, aux;
  	cin >> s;
  	int n = s.size();
  	int sol = 0, largo = 0;
  	int posant = 0;
  	rep(i, n){
  		cout << "#" << i << ", posant: " << posant << '\n';
  		cout << s[posant] << " " << s[i] << " " << i - posant << '\n';
  		if(!fun(s[posant], s[i], i - posant)){
  			sol += largo;
  			cout << "sol: " << sol << '\n';
  			posant++;
  		}
  		else{
  			largo++;
  			posant = s[i] != '?' && s[posant] =='?' ? i : posant;
  		}
  	}
  	sol += (largo) * (largo)/2;

  	cout << sol << '\n';
  }
  
  return 0;
}