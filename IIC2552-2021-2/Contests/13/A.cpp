#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)
#define rep_(i, k, n) for (int i = k; i < n; ++i)
using ll = long long;

struct Node {
    int mod, sum;
    string num;
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.setf(ios::fixed);
  cout.precision(10);
  bool dp[505][5005];
  rep(i, 500){
    rep(j, 5000)
      dp[i][j] = false;
  }
  int d, s;
  cin >> d >> s;
  queue<Node> Q;

  rep_(i, 1, 10){
    Q.push(Node({i % d, i, to_string(i)}));
  }

  while(!Q.empty()){
  	Node aux = Q.front();
	  Q.pop();

    if(aux.sum == s && aux.mod == 0){
        cout << aux.num << '\n';
        return 0;
    }

  	rep(i, 10){
      int sum1 = aux.sum + i, mod1 = (aux.mod * 10 + i) % d;
  		if(sum1 <= s && !dp[mod1 % d][sum1]){
  			Q.push(Node({mod1, sum1, aux.num + to_string(i)}));
        dp[mod1 % d][sum1] = true;
      }
  	}
  }

  while(!Q.empty()){
    cout << Q.front().num << ' ' << Q.front().sum << '\n';
    Q.pop();
  }

  cout << "-1\n";

  return 0;
}