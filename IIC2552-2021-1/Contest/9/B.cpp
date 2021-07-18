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
  
  int ts, tf, t, n, aux, time = 0;
  ll sol = LLONG_MAX, solt = 0;

  queue<int> q;

  cin >> ts >> tf >> t >> n;
  rep(i, n){
  	cin >> aux;
  	q.push(aux);
  }
  while(!q.empty() && q.front() < tf){
  	sol = min(time)

  	int ant = q.front(), times = 1;
  	cout << "---MINUTO " << ant << "---\n";
  	q.pop();
  	while(!q.empty() && q.front() == ant){
  		times++;
  		q.pop();
  	}
  	time = max(0, time - (ant - ts));
  	time += t * times;

  	ts = ant;
  	cout << "Me desocupo en " << time << " minutos\n";
  	cout << "A las " << ts + time << " después de la media noche\n\n";
  	
  }

  
  return 0;
}