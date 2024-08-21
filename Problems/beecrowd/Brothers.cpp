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

    int N, R, C, K;
    while(cin >> N >> R >> C >> K, N != 0){
        vector<vector<int>> grid(R, vector<int>(C)), new_grid(R, vector<int>(C));

        rep(i, R){
            rep(j, C){
                cin >> grid[i][j];
            }
        }

        new_grid = grid;

        rep(k, K){
            rep(i, R){
                rep(j, C){
                    int owner = grid[i][j];
                    int brother_hated = (owner == N-1 ? 0 : owner + 1);
                    if(i != 0) {
                        if (grid[i-1][j] == brother_hated)
                            new_grid[i-1][j] = owner;
                    }
                    if(i != R-1) {
                        if (grid[i+1][j] == brother_hated)
                            new_grid[i+1][j] = owner;
                    }
                    if(j != 0) {
                        if (grid[i][j-1] == brother_hated)
                            new_grid[i][j-1] = owner;
                    }
                    if(j != C-1) {
                        if (grid[i][j+1] == brother_hated)
                            new_grid[i][j+1] = owner;
                    }
                }
            }
            grid = new_grid;
            new_grid = grid;
        }
        rep(i, R){
            rep(j, C){
                cout << grid[i][j] << " \n"[j == C-1];
            }
        }
    }

    return 0;
}