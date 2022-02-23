#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, m = 5005, m2 = 5005;
        cin >> n;
        int v[n];

        for (int i = 0; i < n; i++){
            cin >> v[i];
            if (v[i] != i + 1){
                m = i;
                break;
            }
        }

        for(int j = m + 1; j < n; j++){
            cin >> v[j];
            if (v[j] == m + 1){
                m2 = j;
            }
        }

        for (int i = 0; i < n; i++){
            if (i < m){
                cout << v[i] << ' ';
            }
            if (m <= i && i <= m2){
                cout << v[m2 + m - i] << ' ';
            }
            if (m2 < i){
                cout << v[i] << ' ';
            }
        }
        
        cout << '\n';
    }

    return 0;
}