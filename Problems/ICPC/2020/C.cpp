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
   
   ll n, sol1 = 0, sol2 = 0, reserva = 0, equiv = 0, x;
   cin >> n;
   vector<ll> v1(n), v2(n);
   rep(i, n){
    cin >> x;
    v1[i] = x;
    v2[i] = x;
    equiv += x;
   }
   equiv /= n;
   // cout << equiv << '\n';
    ll cont = 0, i = 0;
    while(cont < 2 * n){
      if(v1[i] < equiv){
        ll quitar = min(reserva, (equiv - v1[i]));
        reserva -= quitar;
        v1[i] += quitar;
      }
      else{
        if(v1[i] > equiv){
          ll dar = v1[i] - equiv;
          reserva += dar;
          v1[i] -= dar;
        }
      }
      // cout << v1[i] << '\n';
      // cout << reserva << '\n';
      sol1 += reserva;
      i = (i + 1) % n;
      cont++;
    }
    cont = 0, i = 0, reserva = 0;
    while(cont < 2 * n){
      if(v2[i] < equiv){
        ll quitar = min(reserva, (equiv - v2[i]));
        reserva -= quitar;
        v2[i] += quitar;
      }
      else{
        if(v2[i] > equiv){
          ll dar = v2[i] - equiv;
          reserva += dar;
          v2[i] -= dar;
        }
      }
      // cout << v1[i] << '\n';
      // cout << reserva << '\n';
      sol2 += reserva;
      i = (n + i - 1) % n;
      cont++;
    }
    cout << min(sol2, sol1) << '\n';


   return 0;
} 
