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
    map<int, int> points = {
        {1, 3},
        {2, 1},
        {3, 0}
    };
    
    while(t--){
        int p[3] = {0, 0, 0};
        string aux;
        vector<string> a[3];
        map<string, int> count;
        int n; 
        cin >> n;
        rep(i, 3){
            rep(j, n){
                cin >> aux;
                count[aux]++;
                a[i].push_back(aux);
            }
        }
        rep(i, 3){
            rep(j, n){
                p[i] += points[count[a[i][j]]];
            }
        }
        cout << p[0] << " " << p[1] << " " << p[2] << '\n';
    }
    
    return 0;
}