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
 
 ll n, cont = 0, sol = 0;
 cin >> n;
 string s;
  cin >> s;
  ll entero, entero1, entero2, deci1, deci2, decimal, numero;
  if(s[2] == '.'){
    entero = s[1] - 48, deci1 = s[3] - 48, deci2 = s[4] - 48;
    decimal = deci1 * 10 + deci2;
    numero = entero * 100 + decimal;
  }
  else{
    entero1 = s[1] - 48, entero2 = s[2] - 48, deci1 = s[4] - 48, deci2 = s[5] - 48;
    entero = entero1 * 10 + entero2;
    decimal = deci1 * 10 + deci2;
    numero = entero * 100 + decimal;
  }
  cont = numero;
 rep(i, n){
  cin >> s;
  if(s[2] == '.'){
    entero = s[1] - 48, deci1 = s[3] - 48, deci2 = s[4] - 48;
    decimal = deci1 * 10 + deci2;
    numero = entero * 100 + decimal;
  }
  else{
    entero1 = s[1] - 48, entero2 = s[2] - 48, deci1 = s[4] - 48, deci2 = s[5] - 48;
    entero = entero1 * 10 + entero2;
    decimal = deci1 * 10 + deci2;
    numero = entero * 100 + decimal;
  }
  cont += numero;
  if(cont % 100 != 0)
    sol++;
  //cout << numero << '\n';
 }
 cout << sol << '\n';
 return 0;
}
