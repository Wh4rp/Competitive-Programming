#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (ll i = 0; i < n; ++i)
#define rep_(i, k, n) for (ll i = k; i < n; ++i)
using ll = long long;


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.setf(ios::fixed);
  cout.precision(10);
  
  ll n, k;
  cin >> n >> k;

  vector<ll> ele(n, -1), erre(n, -1), v;

  priority_queue<ll> students;
  map<ll, ll> pos;
  vector<char> sol(n, '0');

  rep(j, n){
  	ll aux;
  	cin >> aux;
    v.push_back(aux - 1);
    students.push(aux - 1);
    pos[aux - 1] = j;
  }

  rep(i, n){
    if(i > 0)
      ele[v[i]] = v[i - 1];
    if(i < n - 1)
      erre[v[i]] = v[i + 1];
  } /*
  rep(i, n){
    cout << i << ": " << ele[i] << " - ";
    cout << erre[i] << '\n';
  }*/
  map<ll, char> carry;
  carry.insert({-1LL, '2'});
  carry.insert({1LL, '1'});
  ll team = 1LL;

  rep(i, n){
    // cout << '\n';
    ll student_M = students.top(), student_aux1, student_aux2;

    if(sol[pos[student_M]] == '0'){
      // cout << "Maxi = " << student_M << '\n';
      // cout << "con posicion = " << pos[student_M] << '\n';
      sol[pos[student_M]] = carry[team];

      student_aux1 = student_M;
      student_aux2 = student_M;

      rep(j, k){
        if(ele[student_aux1] == -1 || sol[pos[ele[student_aux1]]] != '0'){
          break;
        }
        student_aux1 = ele[student_aux1];
        // cout << "se marca por la izquierda al " << student_aux1 << '\n';
        sol[pos[student_aux1]] = carry[team];
      }

      rep(j, k){
        // cout << erre[student_aux2] << '\n';
        if(erre[student_aux2] == -1 || sol[pos[erre[student_aux2]]] != '0'){
          break;
        }
        student_aux2 = erre[student_aux2];
        // cout << "se marca por la derecha al " << student_aux2 << '\n';
        sol[pos[student_aux2]] = carry[team];
      }

      if(ele[student_aux1] != -1){
        erre[ele[student_aux1]] = erre[student_aux2];
      }

      if(erre[student_aux2] != -1){
        ele[erre[student_aux2]] = ele[student_aux1];
      }
      team *= -1LL;
    }
    students.pop();
  }
  
  for(char &x : sol){
  	cout << x;
  }
  cout << '\n';

  return 0;
}