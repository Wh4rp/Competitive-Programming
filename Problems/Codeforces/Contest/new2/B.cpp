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

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int aux = n * n - 1, aux2 = 1;
        int A[n * n];
        A[0] = 1;
        rep_(i, 1, n * n) {
            A[i] = A[i - 1] + aux * aux2;
            aux--;
            aux2 *= -1;
        }
        int matrix[n][n];
        rep(i, n) {
            rep(j, n) {
                matrix[i][j] = -1;
            }
        }
        pair<int, int> moves[4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        int posx = -1, posy = 0, type_mov = 0, k = 0;

        while (k < n * n) {
            int next_pos_x = posx + moves[type_mov].first;
            int next_pos_y = posy + moves[type_mov].second;
            if (next_pos_x < 0 || next_pos_x > n || next_pos_y < 0 ||
                next_pos_y > n || matrix[next_pos_x][next_pos_y] != -1) {
                type_mov = (type_mov + 1) % 4;
                next_pos_x = posx + moves[type_mov].first;
                next_pos_y = posy + moves[type_mov].second;
            }
            matrix[next_pos_x][next_pos_y] = A[k];
            posx = next_pos_x;
            posy = next_pos_y;
            k++;
        }

        rep(i, n) {
            rep(j, n) {
                cout << matrix[i][j] << " \n"[j == n - 1];
            }
        }
    }

    return 0;
}