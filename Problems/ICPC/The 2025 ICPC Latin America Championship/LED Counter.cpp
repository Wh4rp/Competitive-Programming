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

    map<string, int> leds = {{"GGGgGGG", 0}, {"gggggGG", 1}, {"gGGGGGg", 2},
                             {"ggGGGGG", 3}, {"GggGgGG", 4}, {"GgGGGgG", 5},
                             {"GGGGGgG", 6}, {"ggGggGG", 7}, {"GGGGGGG", 8},
                             {"GgGGGGG", 9}};

    int n;
    cin >> n;

    rep(i, n) {
        string led;
        cin >> led;

        vector<int> posibles_numbers;

        for (auto [code, number] : leds) {
            // cout << code << ' ' << number << '\n';
            bool valid = true;
            rep(j, 7) {
                // cout << code[j] << ' ' << led[j] << '\n';
                if (code[j] != led[j] && (led[j] != '-' && led[j] != '+')){
                    valid = false;
                    break;
                }
            }

            if (valid)
                posibles_numbers.push_back(number);
        }

        if (posibles_numbers.size() == 1) {
            cout << posibles_numbers[0];
        } else {
            cout << '*';
        }
    }

    cout << '\n';

    return 0;
}