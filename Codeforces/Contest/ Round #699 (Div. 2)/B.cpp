#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define rep(i, k, n) for (int i = k; i < n; ++i)
#define loop(h) for (int hi = 0; hi < h; hi++)
#define ii pair<int, int>
using ll = long long;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.setf(ios::fixed);
  cout.precision(10);
  int t, n, k;
  cin >> t;
  loop(t) {
    cin >> n >> k;
    int cont = 0, sol = 0;
    stack<int> niveles[101];  // niveles hasta 100
    queue<int> picos;
    int v[n + 2];
    v[0] = 0;
    v[n + 1] = 0;
    rep(i, 0, n) { cin >> v[i + 1]; }
    rep(i, 2, n + 1) {
      if (v[i] > v[i - 1] && v[i] >= v[i + 1]) {
        picos.push(i);
        // cout << "pico: " << i << '\n';
      }
    }
    int pico_anterior = 0;
    while (!picos.empty() && cont != k) {
      int pico = picos.front(), nivel_pico = v[pico];
      picos.pop();
      for (int i = pico_anterior; i <= pico - 1; i++) {
        for (int j = v[i + 1]; j <= 100; j++) {
          niveles[j].push(i + 1);
        }
      }
      for (int i = 0; i < nivel_pico && cont != k; i++) {
        int roca_indice;
        while (!niveles[i].empty() && cont != k) {
          roca_indice = niveles[i].top();
          niveles[i].pop();
          // cout << "Se puso roca en " << roca_indice << '\n';
          // v[roca_indice]++;
          cont++;
        }
        if (cont == k)
          sol = roca_indice;
      }
      pico_anterior = pico;
    }
    /*for (auto x : v)
      cout << x << " ";
    cout << '\n';*/
    if (cont == k)
      cout << sol << '\n';
    else
      cout << -1 << '\n';
  }

  return 0;
}
