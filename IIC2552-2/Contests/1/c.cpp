#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (ll i = 0; i < n; ++i)
#define rep_(i, k, n) for (ll i = k; i < n; ++i)
using ll = long long;
 
struct block {
  ll s, event, x;
  block(ll ss, ll eventt, ll xx)
    {
      s = ss, event = eventt, x = xx;
    }
    bool operator<(const block& a) const
    {
        return s == a.s? event < a.event: s < a.s;
    }
};
 
void print(block b){
  cout << b.s << ' ' << b.event << ' ' << b.x << '\n';
}
 
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.setf(ios::fixed);
  cout.precision(10);
 
  vector<block> V;
  ll n, q, N = 0;
  cin >> n >> q;
  rep(i, n){
    ll s, t, x;
    cin >> s >> t >> x;
    if(t >= x){
      V.push_back(block(max(0LL, s - x), 1, x));
      V.push_back(block(t - x, 0, x));
      N+=2;
    }
  }
  sort(V.begin(), V.end());
  /*
  for(auto x : V){
    print(x);
  }
*/
  set<ll> buenas;
 
  ll index = 0;
 
  rep(i, q){
    ll d;
    cin >> d;
    //cout << "case d = " << d << '\n';
 
    // cout << 2*(V[index].s - d) << '\n';
 
    while(index < N && 2 * (V[index].s - d) < 1){ // d > V[index].s - 0.5
      if(V[index].event == 1){
        //cout << "se añade a "; 
        buenas.insert(V[index].x);
      }
      else{
        //cout << "se saca a "; 
        buenas.erase(V[index].x);
      }
      //cout << V[index].x << '\n';
      index++;
 
    }
    /*
    for(auto x : buenas){
      cout << x << ' ';
    }
    cout << '\n';*/
    if(!buenas.empty())
      cout << *buenas.begin() << '\n';
    else
      cout << "-1\n";
  }
  return 0;
 
}