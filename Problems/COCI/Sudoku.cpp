#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)
#define rep_(i, k, n) for (int i = k; i < n; ++i)
using ll = long long;

bool verify_row(vector<vector<int>>& sudoku, int row) {
    set<int> s;
    rep(i, 9) {
        int val = sudoku[row][i];
        if(val != -1 && s.count(val)) return false;
        s.insert(val);
    }
    return true;
}

bool verify_col(vector<vector<int>>& sudoku, int col) {
    set<int> s;
    rep(i, 9) {
        int val = sudoku[i][col];
        if(val != -1 && s.count(val)) return false;
        s.insert(val);
    }
    return true;
}

bool verify_square(vector<vector<int>>& sudoku, int row, int col) {
    set<int> s;
    rep(i, 3) {
        rep(j, 3) {
            int val = sudoku[row + i][col + j];
            if(val != -1 && s.count(val)) return false;
            s.insert(val);
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.setf(ios::fixed);
    cout.precision(10);

    vector<int> lines_types = {0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0}; // 0: separator, 1: row
    vector<vector<int>> sudoku;
    for(int type : lines_types) {
        string line;
        cin >> line;
        if(type) {
            vector<int> sudoku_row;
            rep(i, 3) {
                int pos_chunk = 4 * i + 1;
                rep(j, 3) {
                    int pos =  pos_chunk + j;
                    if(line[pos] == '.') sudoku_row.push_back(-1);
                    else sudoku_row.push_back(line[pos] - '0');
                }
            }
            sudoku.push_back(sudoku_row);
        }
    }

    bool check = true;

    rep(i, 9) {
        check = check && verify_row(sudoku, i);
        check = check && verify_col(sudoku, i);
    }

    rep(i, 3) rep(j, 3) {
        check = check && verify_square(sudoku, 3 * i, 3 * j);
    }

    if(check) cout << "OK\n";
    else cout << "GRESKA\n";

    return 0;
}