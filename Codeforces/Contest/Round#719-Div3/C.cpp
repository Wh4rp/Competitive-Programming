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
  
  int t; cin >> t;
  while (t--){
    int n;
    cin >> n;
    if(n == 1){
      cout << "1\n";
    }
    else{
      if(n == 2){
        cout << "-1\n";
      }
      else{
        int out = 1;
        rep(i, n){
          rep(j, n){
            cout << out << " ";
            if(out >= n * n - 1){
              out = 0;
            }
            out += 2;
          }
          cout << '\n';
        }

      }
    }
  }
  
  return 0;
}