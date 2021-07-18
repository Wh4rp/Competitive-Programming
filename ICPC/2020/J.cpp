#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)
#define rep_(i, k, n) for (int i = k; i < n; ++i)
using ll = long long;
struct Comp{
  ll G[8];
  ll id;
};
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.setf(ios::fixed);
  cout.precision(10);

  ll N, K, id = 1;
  vector<Comp> Compus;

  string s;
  ll op;

  cin >> N >> K;
  rep(i, N)
  {
    cin >> s >> op;
    if (s == 'C')
    {
      Comp Compaux;
      rep(i, K)
        Compaux.G[i] = 0;
      rep(i, op){
        ll aux; cin >> aux;
        Compaux.G[aux]++;
      }
      Compaux.id = id++;
      Compus.push_back(Compaux);
    }
    if (s == 'J')
    {
      Comp Compaux;
      rep(i, op){
        ll aux; cin >> aux;
        Compaux.G[aux]++;
      }
      l = 0, r = Compus.length();
      rep(i, K){
        sort(Compus.begin() + l, Compus.begin() + r);
        l = Compus.lower_bound(Compus[i]);
      }
    }
    if (s == 'D')
    {
      vector<ll> delet = computus[op];
    }
  }

  return 0;
}
