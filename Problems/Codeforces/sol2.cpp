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

    ll n;
    cin >> n;
    vector<int> moves;
    while(n != 0) {
        if(n % 2 == 0) {
            moves.push_back(0);
            n /= 2;
        }
        else {
            moves.push_back(1);
            n--;
        }
    }

    reverse(moves.begin(), moves.end());
    rep(i, moves.size()) {
        if(moves[i] == 0) {
            cout << "B";
        }
        else {
            cout << "A";
        }
    }
    cout << '\n';

    return 0;
}