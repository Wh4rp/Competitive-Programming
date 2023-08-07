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

    int n, x;
    cin >> n >> x;
    set<ll> left, right;
    left.insert(0);
    right.insert(0);
    rep(i, n) {
        ll aux, type;
        cin >> aux >> type;
        if (type)
            left.insert(aux);
        else
            right.insert(aux);
    }
    ll count = 0, curr_pos = x, turn = -1;
    bool flag = true;

    while (flag) {
        // cout << "posicion actual: " << curr_pos << '\n';
        if (turn == 1) {  // la bola se mueve hacia ->
            // cout << "---->\n";
            auto pos = left.upper_bound(curr_pos);
            if (pos != left.end() && *pos != 0) {
                curr_pos = *pos;
                left.erase(pos);
                // cout << "->"
                //      << "(" << *pos << '\n';
            } else {
                if (left.size() != 1 || right.size() != 1)
                    flag = false;
                // cout << "termino\n";
                break;
            }
        } else {  // la bola se mueve hacia <-
            // cout << "<----\n";
            auto pos = right.lower_bound(curr_pos);
            if (right.size() == 1 || curr_pos == 0) {
                count++;
                // cout << "Choco con Luke\n";
                curr_pos = 0;
            } else {
                if(pos != right.begin())
                    pos = prev(pos);
                curr_pos = *pos;
                if (*pos == 0) {
                    count++;
                    // cout << "Choco con Luke\n";
                }
                else{
                    right.erase(pos);
                }
                // cout << *pos << ")"
                //      << "<-" << '\n';
            }
        }
        turn *= -1;
    }

    if (flag) {
        cout << count << '\n';
    } else {
        cout << "-1\n";
    }

    return 0;
}