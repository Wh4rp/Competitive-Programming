#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)
#define rep_(i, k, n) for (int i = k; i < n; ++i)
using ll = long long;

bool reach(int x, int y, int a, int b, int mov_x, int mov_y){
    if(x == a && y == b) return true;
    bool same_sign_x = (a - x > 0) == (mov_x > 0);
    bool same_sign_y = (b - y > 0) == (mov_y > 0);
    if(!same_sign_x || !same_sign_y) return false;

    mov_x = abs(mov_x);
    mov_y = abs(mov_y);
    int dif_x = abs(a - x);
    int dif_y = abs(b - y);

    if(mov_x == 0 && mov_y == 0) return false;
    if(mov_x == 0) return (dif_x == 0) && (dif_y % mov_y == 0);
    if(mov_y == 0) return (dif_y == 0) && (dif_x % mov_x == 0);

    int steps_x = dif_x / mov_x;
    int steps_y = dif_y / mov_y;

    return (steps_x == steps_y) && (dif_x % mov_x == 0) && (dif_y % mov_y == 0);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.setf(ios::fixed);
    cout.precision(10);

    int a, b, x = 0, y = 0, mov_x = 0, mov_y = 0;
    cin >> a >> b;
    vector<pair<int, int>> pos;
    pos.push_back({0, 0});
    string moves;
    cin >> moves;
    rep(i, moves.size()){
        if(moves[i] == 'U') {
            y++;
            mov_y++;
        }
        else if(moves[i] == 'D') {
            y--;
            mov_y--;
        }
        else if(moves[i] == 'R') {
            x++;
            mov_x++;
        }
        else {
            x--;
            mov_x--;
        }
        pos.push_back({x, y});
    }

    for(auto p : pos){
        if(reach(p.first, p.second, a, b, mov_x, mov_y)){
            cout << "Yes\n";
            return 0;
        }
    }
    cout << "No\n";

    return 0;
}