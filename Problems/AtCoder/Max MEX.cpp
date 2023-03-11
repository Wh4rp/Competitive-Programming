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

    int n, k, aux, ans;
    cin >> n >> k;
    set<int> s;
    rep(i, n){

        cin >> aux;
        s.insert(aux);
    }
    int j = 0;

    for(int x : s){
        if(x != j){
            ans = j;
            break;
        }
        j++;
    }

    cout << min(k, ans) << '\n';

    return 0;
}