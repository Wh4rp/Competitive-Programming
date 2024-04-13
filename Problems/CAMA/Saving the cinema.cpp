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

    string s;
    cin >> s;
    if (s == "Yoda")
        cout << "Pertenece a Star Wars.\n";
    else if (s == "Spock")
        cout << "Pertenece a Star Trek.\n";
    else
        cout << "No pertenece ni a Star Wars ni a Star Trek.\n";

    return 0;
}