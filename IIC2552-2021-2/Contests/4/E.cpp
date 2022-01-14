#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (ll i = 0; i < n; ++i)
#define rep_(i, k, n) for (ll i = k; i < n; ++i)
using ll = long long;

int n, t[1024][4*1024];

void build(int a[], int v, int tl, int tr, int row) {
  if (tl == tr) {
    t[row][v] = a[tl];
  } else {
    int tm = (tl + tr) / 2;
    build(a, v*2, tl, tm, row);
    build(a, v*2+1, tm+1, tr, row);
    t[row][v] = t[row][v*2] + t[row][v*2+1];
  }
}

int sum(int v, int tl, int tr, int l, int r, int row) {
  if (l > r) 
    return 0;
  if (l == tl && r == tr) {
    return t[row][v];
  }
  int tm = (tl + tr) / 2;
  return sum(v*2, tl, tm, l, min(r, tm), row)  + sum(v*2+1, tm+1, tr, max(l, tm+1), r, row);
}

void update(int v, int tl, int tr, int pos, int new_val, int row) {
  if (tl == tr) {
    t[row][v] = new_val;
  } else {
    int tm = (tl + tr) / 2;
    if (pos <= tm)
      update(v*2, tl, tm, pos, new_val, row);
    else
      update(v*2+1, tm+1, tr, pos, new_val, row);
    t[row][v] = t[row][v*2] + t[row][v*2+1];
  }
}


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.setf(ios::fixed);
  cout.precision(10);

  ll test;
  cin >> test;
  while(test--){
    cin >> n;
    rep(i, n){
      rep(j, 4*n + 4)
        t[i][j] = 0;
    }
    string op = "";
    while(cin >> op, op != "END"){
      if(op == "SET"){
        int row, col, new_val;
        cin >> row >> col >> new_val;
        update(1, 0, n - 1, col, new_val, row);
      }
      else{
        int x1, x2, y1, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        int suma = 0;
        rep_(j, y1, y2 + 1){
          suma += sum(1, 0, n - 1, x1, x2, j);
        }
        cout << suma << '\n';
      }
    }
  }
  return 0;
}