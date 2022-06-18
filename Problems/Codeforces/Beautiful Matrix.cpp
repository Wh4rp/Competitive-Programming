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
  
  int a, b, aux;
  rep(i, 5){
		rep(j, 5){
			cin >> aux;
			if(aux == 1){
				a = i, b = j;
			}
		}
  }
  
  cout << abs(a - 2) + abs(b - 2) << '\n';
  return 0;
}