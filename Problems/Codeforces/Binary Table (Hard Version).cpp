#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)
#define rep_(i, k, n) for (int i = k; i < n; ++i)
using ll = long long;

// movs in binary are
// 1110 = 14
// 1101 = 13
// 1011 = 11
// 0111 = 7

int movs[4] = {14, 13, 11, 7};
vector<pair<int, int>> movs_pos[4] = {
    {{0, 0}, {0, 1}, {1, 0}},
    {{0, 0}, {0, 1}, {1, 1}},
    {{0, 0}, {1, 0}, {1, 1}},
    {{0, 1}, {1, 0}, {1, 1}}
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.setf(ios::fixed);
    cout.precision(10);

    int t;
    cin >> t;
    while (t--){
        int n, m;
        vector<pair<int, int>> ans;
        cin >> n >> m;
        string grid[n];
        rep(i, n){
            cin >> grid[i];
        }

        // --->
        // --->
        rep(i, n - 2){
            rep(j, m){
                if(grid[i][j] == '1'){
                    grid[i][j] = '0';
                    grid[i + 1][j] = (grid[i + 1][j] == '0') ? '1' : '0';
                    ans.push_back({i, j});
                    ans.push_back({i + 1, j});
                    if(j != m - 1){
                        grid[i + 1][j + 1] = (grid[i + 1][j + 1] == '0') ? '1' : '0';
                        ans.push_back({i + 1, j + 1});
                    }
                    else {
                        grid[i + 1][j-1] = (grid[i + 1][j-1] == '0') ? '1' : '0';
                        ans.push_back({i + 1, j - 1});
                    }
                    // print grid
                    // rep(i, n){
                    //     cout << grid[i] << '\n';
                    // }
                    // cout << '\n';
                }
            }
        }

        // | | |
        // v v v
        rep(j, m - 2){
            rep_(i, n - 2, n){
                if(grid[i][j] == '1'){
                    grid[i][j] = '0';
                    grid[i][j+1] = (grid[i][j+1] == '0') ? '1' : '0';
                    ans.push_back({i, j});
                    ans.push_back({i, j + 1});
                    if(i != n - 1){
                        grid[i+1][j+1] = (grid[i+1][j+1] == '0') ? '1' : '0';
                        ans.push_back({i + 1, j + 1});
                    }
                    else {
                        grid[i-1][j+1] = (grid[i-1][j+1] == '0') ? '1' : '0';
                        ans.push_back({i - 1, j + 1});
                    }
                    // print grid
                    // rep(i, n){
                    //     cout << grid[i] << '\n';
                    // }
                    // cout << '\n';
                }
            }
        }

        // case 2 x 2
        // throw bfs
        int int_00 = grid[n-2][m-2] - '0';
        int int_01 = grid[n-2][m-1] - '0';
        int int_10 = grid[n-1][m-2] - '0';
        int int_11 = grid[n-1][m-1] - '0';
        int val_init = int_00 * 8 + int_01 * 4 + int_10 * 2 + int_11;
        
        pair<int, vector<pair<int, int>>> start = {val_init, {}};
        queue<pair<int, vector<pair<int, int>>>> q;
        vector<bool> visited(16, false);
        q.push(start);

        while(!q.empty()){
            pair<int, vector<pair<int, int>>> curr = q.front();
            q.pop();
            int val = curr.first;
            if(visited[val]) continue;
            visited[val] = true;
            vector<pair<int, int>> path = curr.second;
            if(val == 0){
                ans.insert(ans.end(), path.begin(), path.end());
                break;
            }
            rep(i, 4){
                if(!visited[val ^ movs[i]]){
                    vector<pair<int, int>> new_path = path;
                    new_path.push_back({n-2 + movs_pos[i][0].first, m-2 + movs_pos[i][0].second});
                    new_path.push_back({n-2 + movs_pos[i][1].first, m-2 + movs_pos[i][1].second});
                    new_path.push_back({n-2 + movs_pos[i][2].first, m-2 + movs_pos[i][2].second});
                    q.push({val ^ movs[i], new_path});
                }
            }
        }

        // print sol with ans.size()
        cout << ans.size()/3 << '\n';
        for(int i = 0; i < ans.size(); i += 3){
            cout << ans[i].first + 1 << ' ' << ans[i].second + 1 << ' ';
            cout << ans[i + 1].first + 1 << ' ' << ans[i + 1].second + 1 << ' ';
            cout << ans[i + 2].first + 1 << ' ' << ans[i + 2].second + 1 << '\n';
        }
    }

    return 0;
}