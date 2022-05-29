#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)
#define rep_(i, k, n) for (int i = k; i < n; ++i)
using ll = long long;
struct Drone
{
	ll pos, vel;
	double crush1 = -1, crush2 = -1;
	bool crush = false;
	double inter(Drone d){
		if(d.vel == vel){
			return -1;
		}
		double time = double(pos - d.pos) / double(d.vel - vel);
		if(time > 0){
			return time;
		}else{
			return -1.0;
		}
	}
};
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.setf(ios::fixed);
  cout.precision(10);
  
  int N;
  cin >> N;
  vector<Drone> v(N);
  vector<int> vivos;
  for(auto& x : v) 
  	cin >> x.pos >> x.vel;

  rep(i, N - 1){
  	double time = v[i].inter(v[i + 1]);
  	v[i].crush2 = time;
  	v[i + 1].crush1 = time;
  }

  ll cont = 0;
  rep(i, N){
  	if(v[i].crush1 != -1 && i != 0){
  		if(v[i - 1].crush1 > v[i].crush1 || v[i - 1].crush1 == -1){
  			v[i].crush = true;
  			continue;
  		}
  	}
  	if(v[i].crush2 != -1 && i != N - 1){
  		if(v[i + 1].crush2 > v[i].crush2 || v[i + 1].crush2 == -1){
  			v[i].crush = true;
  			continue;
  		}
  	}
  	cont++;
  }
  cout << cont << '\n';
  rep(i, N){
  	if(!v[i].crush)
  		cout << i + 1 << " \n"[i == N - 1];
  }
  return 0;
}