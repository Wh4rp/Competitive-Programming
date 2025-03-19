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
    int char_sum_accumulate[2][26][200005];

    while (t--) {
        int n, q;
        cin >> n >> q;
        string s[2];
        cin >> s[0] >> s[1];
        rep(k, 2) {
            rep(i, 26) {
                char_sum_accumulate[k][i][0] = (s[k][0] == ('a' + i));
            }
        }
        rep(k, 2) {
            rep(i, 26) {
                rep_(j, 1, n) {
                    char_sum_accumulate[k][i][j] =
                        char_sum_accumulate[k][i][j - 1] +
                        (s[k][j] == ('a' + i));
                }
                char_sum_accumulate[k][i][n] = char_sum_accumulate[k][i][n - 1];
            }
        }

        auto count_letter = [&](int a, int b, int letter,
                                int arr) -> int {  // [a, b] inclusive
            if (a == 0)
                return char_sum_accumulate[arr][letter][b];
            else
                return char_sum_accumulate[arr][letter][b] -
                       char_sum_accumulate[arr][letter][a - 1];
        };

        rep(_, q) {
            int l, r, ans = 0;
            cin >> l >> r;
            l--, r--;
            rep(i, 26) {
                int dif = count_letter(l, r, i, 0) - count_letter(l, r, i, 1);
                if (dif > 0)
                    ans += dif;
            }
            cout << ans << '\n';
        }
    }

    return 0;
}