#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)
#define rep_(i, k, n) for (int i = k; i < n; ++i)
using ll = long long;

struct Balls {
  ll val, cont;
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.setf(ios::fixed);
  cout.precision(10);
  
  ll t, type, cont, val;
  deque<Balls> dq;
  cin >> t;
  rep(_, t){
    cin >> type;
    if(type == 1){
      cin >> val >> cont;
      dq.push_back({val, cont});
    }
    else{
      cin >> cont;
      ll sum = 0;
      while(cont != 0){
        if(cont >= dq.front().cont){
          cont -= dq.front().cont;
          sum += dq.front().val * dq.front().cont;
          dq.pop_front();
        }
        else{
          dq.front().cont -= cont;
          sum += cont * dq.front().val;
          cont = 0;
        }
      }
      cout << sum << '\n';
    }
    // cout << dq.back().cont << ' ' << dq.back().val << '\n';
  }
  
  return 0;
}