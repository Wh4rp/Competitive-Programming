#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)
#define rep_(i, k, n) for (int i = k; i < n; ++i)
using ll = long long;

int move_r[] = {0, 0, 1, -1};
int move_c[] = {1, -1, 0, 0};

int id(int r, int c) {
    return r * 1000 + c;
}

struct DSU {
    vector<int> p;
    DSU(int N) : p(N, -1) {}
    int get(int x) { return p[x] < 0 ? x : p[x] = get(p[x]); }
    bool sameSet(int a, int b) { return get(a) == get(b); }
    int size(int x) { return -p[get(x)]; }
    void unite(int x, int y) {
        if ((x = get(x)) == (y = get(y)))
            return;
        if (p[x] > p[y])
            swap(x, y);
        p[x] += p[y], p[y] = x;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.setf(ios::fixed);
    cout.precision(10);

    DSU dsu_white(1000000), dsu_black(1000000);
    int N, M;
    cin >> N >> M;
    string grid[N];
    rep(i, N) cin >> grid[i];
    rep(i, N) rep(j, M) {
        rep(k, 4) {
            int ii = i + move_r[k], jj = j + move_c[k];
            if (0 <= ii && ii < N && 0 <= jj && jj < M) {
                if (grid[i][j] == '0' && grid[ii][jj] == '0') {
                    dsu_white.unite(id(i, j), id(ii, jj));
                }
                if (grid[i][j] == '1' && grid[ii][jj] == '1') {
                    dsu_black.unite(id(i, j), id(ii, jj));
                }
            }
        }
    }
    set<int> white, black;
    rep(i, N) rep(j, M) {
        if (grid[i][j] == '0')
            white.insert(dsu_white.get(id(i, j)));
        if (grid[i][j] == '1')
            black.insert(dsu_black.get(id(i, j)));
    }

    int ans_white = white.size(), ans_black = black.size();

    cout << "Hay " << white.size() << " componentes blancas\n";
    cout << "Hay " << black.size() << " componentes negras\n";

    rep(i, M) {
        cout << "En la columna " << i << ":\n";
        set<int> white_column, black_column;
        rep(j, N) {
            if (grid[j][i] == '0') {
                white_column.insert(dsu_white.get(id(j, i)));
                cout << dsu_white.get(id(j, i)) << '\n';
            }
            if (grid[j][i] == '1') {
                black_column.insert(dsu_black.get(id(j, i)));
                cout << dsu_black.get(id(j, i)) << '\n';
            }
        }
        cout << "Hay " << white_column.size() << " componentes blancas\n";
        cout << "Hay " << black_column.size() << " componentes negras\n";
        int aux_white = white.size() + 2 * white_column.size(),
            aux_black = black.size() - (black_column.size() - 1);
        if (ans_white + ans_black < aux_white + aux_black) {
            ans_white = aux_white;
            ans_black = aux_black;
        }
    }

    cout << ans_white << ' ' << ans_black << '\n';

    return 0;
}