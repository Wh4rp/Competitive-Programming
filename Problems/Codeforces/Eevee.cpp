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

    string name, evolutions[] = {"vaporeon", "jolteon", "flareon", "espeon", "umbreon", "leafeon", "glaceon", "sylveon"};
    int n;
    cin >> n >> name;
    rep(i, 8){
        if(name.length() == evolutions[i].length()){
            bool match = true;
            rep(j, n){
                if(name[j] == '.')
                    continue;
                if(name[j] != evolutions[i][j]){
                    match = false;
                    break;
                }
            }
            if (match){
                cout << evolutions[i] << '\n';
                break;
            }
        }
    }

    return 0;
}