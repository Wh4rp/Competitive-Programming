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

    int n, m;
    cin >> n >> m;
    int a[m + 5];
    rep(i, m) cin >> a[i];
    int i = 1, j = 0;
    stack<int> s;
    while (i <= n && j < m) {
        while(i != a[j]){
            cout << i << ' ';
            i++;
        }
        while(i == a[j]){
            s.push(i);
            i++, j++;
        }
        s.push(i);
        while(!s.empty()){
            cout << s.top() << ' ';
            s.pop();
        }
        i++;
    }
    rep_(k, i, n+1)
        cout << k << ' ';

    cout << '\n';

    return 0;
}