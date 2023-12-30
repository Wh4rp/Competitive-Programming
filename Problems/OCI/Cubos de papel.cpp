#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)
#define rep_(i, k, n) for (int i = k; i < n; ++i)
using ll = long long;

int cube_1[6], cube_2[6];

bool equal() {
    rep(i, 6) {
        if (cube_1[i] != cube_2[i]) {
            return false;
        }
    }
    return true;
}

void move_right() {
    swap(cube_1[2], cube_1[3]);
    swap(cube_1[3], cube_1[4]);
    swap(cube_1[4], cube_1[5]);
}

void move_down() {
    swap(cube_1[0], cube_1[5]);
    swap(cube_1[5], cube_1[1]);
    swap(cube_1[1], cube_1[3]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.setf(ios::fixed);
    cout.precision(10);

    rep(i, 6) cin >> cube_1[i];
    rep(i, 6) cin >> cube_2[i];

    rep(i, 4) {
        move_right();
        rep(j, 4) {
            move_down();
            if (equal()) {
                cout << "1\n";
                return 0;
            }
        }
    }

    cout << "0\n";

    return 0;
}