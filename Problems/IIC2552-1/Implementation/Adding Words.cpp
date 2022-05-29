#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)
#define rep_(i, k, n) for (int i = k; i < n; ++i)
#define loop(h) for (int hi = 0; hi < h; hi++)
#define ii pair<int, int>
using ll = long long;

template <typename First>
void read(First& t) {
  cin >> t;
}
template <typename First, typename... Args>
void read(First& f, Args&... args) {
  cin >> f;
  read(forward<Args&>(args)...);
}

// VARIADIC OUTPUT
template <typename T>
void print(T&& t) {
  cout << t << "\n";
}
template <typename First, typename... Args>
void print(First&& f, Args&&... args) {
  cout << f << " ";
  print(forward<Args&&>(args)...);
}
template <typename T>
void printLn(T&& t) {
  cout << t << "\n";
}
template <typename First, typename... Args>
void printLn(First&& f, Args&&... args) {
  cout << f << "\n";
  printLn(forward<Args&&>(args)...);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.setf(ios::fixed);
  cout.precision(10);
  map<int, string> n_p;
  map<string, int> p_n;
  string s;
  while (getline(cin, s)) {
    stringstream ss;
    ss << s;
    string comand, variable, operacion;
    int numero;
    ss >> comand;
    if (comand == "calc") {
      int sum = 0, op = 1;
      bool conocido = true;
      while (ss >> variable >> operacion) {
        cout << variable << " " << operacion << " ";
        if (p_n.count(variable)) {
          sum += op * p_n[variable];
        } else
          conocido = false;

        if (operacion == "-") {
          op = -1;
        }
        if (operacion == "+") {
          op = 1;
        }
        if (operacion == "=") {
          op = -1;
        }
      }
      if (!conocido) {
        cout << "unknown\n";
      } else {
        if (n_p.count(sum)) {
          cout << n_p[sum] << '\n';
        } else {
          cout << "unknown\n";
        }
      }
    }
    if (comand == "def") {
      ss >> variable >> numero;

      if (p_n.count(variable)) {
        n_p.erase(p_n[variable]);
        p_n[variable] = numero;
      }
      p_n[variable] = numero;
      n_p[numero] = variable;
    }
    if (comand == "clear") {
      n_p.clear();
      p_n.clear();
    }
  }

  return 0;
}
