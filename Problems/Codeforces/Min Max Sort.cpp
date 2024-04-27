#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)
#define rep_(i, k, n) for (int i = k; i < n; ++i)
using ll = long long;

int ceil(int a, int b){
    return (a + b - 1) / b;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.setf(ios::fixed);
    cout.precision(10);

    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        int positions[n+1];
        rep_(i, 1, n+1){
            int x;
            cin >> x;
            positions[x] = i;
        }
        int sort_cont = 1;
        if(n % 2 == 0){
            int a = n / 2, b = n / 2 + 1;
            if(positions[a] > positions[b]){
                sort_cont = 1;
                cout << n / 2 << '\n';
            }
            else{
                sort_cont = 2;
                while (a != 1){
                    int x = a - 1, y = b + 1;
                    if (positions[x] < positions[a] && positions[b] < positions[y]){
                        sort_cont += 2;
                    }
                    else {
                        break;
                    }
                    a = x, b = y;
                }
                cout << (n - sort_cont) / 2 << '\n';
            }
        }
        else {
            int a = n / 2, m = n / 2 + 1, b = n / 2 + 2;
            // cout << a << " " << m << ' ' << b << '\n'; 
            if(positions[a] < positions[m] && positions[m] < positions[b]){
                // hago lo mismo de antes
                sort_cont = 2;
                while (a != 1){
                    int x = a - 1, y = b + 1;
                    if (positions[x] < positions[a] && positions[b] < positions[y]){
                        sort_cont += 2;
                    }
                    else {
                        break;
                    }
                    a = x, b = y;
                }
                cout << (n - sort_cont) / 2 << '\n';
            }
            else{
                cout << n / 2 << '\n';
            }
        }
    }

    return 0;
}