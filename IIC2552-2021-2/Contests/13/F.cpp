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
  
  int n, sol = 0;
  cin >> n;

	vector<int> is_prime(n+1, 0);
	is_prime[0] = is_prime[1] = 0;
	for (int i = 2; i <= n; i++) {
	    if (is_prime[i] == 0) {
	        for (int j = 2 * i; j <= n; j += i)
	            is_prime[j]++;
	    }
	}

	rep(i, n + 1){
		// cout << i << ": " << is_prime[i] << '\n';
		if(is_prime[i] == 2)
			sol++;
	}

	cout << sol << '\n';

  return 0;
}