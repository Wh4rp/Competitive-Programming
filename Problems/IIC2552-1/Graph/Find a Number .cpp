#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (ll i = 0; i < n; ++i)
#define rep_(i, k, n) for (ll i = k; i < n; ++i)
using ll = long long;

struct Node {
  int r, s;
  string num;
  Node(int r, int s, string num) : r(r), s(s), num(num) {}
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.setf(ios::fixed);
  cout.precision(10);
  
  bool visited[505][5005];
  rep(i, 505) rep(j, 5005) {
    visited[i][j] = false;
  }

  ll d, s, x, y, x1, y1;
  string z;
  cin >> d >> s;

  queue<Node> q; // remaining and sum
  rep_(i, 1, 10){
    q.push(Node(i%d, i, to_string(i)));
    visited[i%d][i] = true;
  }

  while(!q.empty()){
    Node n = q.front();
    x = n.r;
    y = n.s;
    z = n.num;
    q.pop();
    if(x == 0 && y == s){
      cout << z << '\n';
      return 0;
    }
    rep(i, 10){
      x1 = (x*10 + i) % d;
      y1 = y + i;
      if(y1 <= s && !visited[x1][y1]){
        visited[x1][y1] = true;
        q.push(Node(x1, y1, z + to_string(i)));
      }
    }
  }

  cout << "-1\n";

  return 0;
}