#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)
#define rep_(i, k, n) for (int i = k; i < n; ++i)
using ll = long long;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.setf(ios::fixed);
    cout.precision(10);

    int t;
    cin >> t;
    while (t--){
        int n, ans = 0;
        cin >> n;
        vector<int> a(n);
        rep(i, n) cin >> a[i];
        sort(a.begin(), a.end());
        int i = 1, j = 0;
        vector<int> visited(n + 5, 0);
        while(i <= n + 1 && j < n){
            if(a[j] <= n && visited[a[j]] != 1){
                visited[a[j]] = 1;
            }
            else{
                if(visited[i]){
                    i++;
                    continue;
                }
                else{
                    if(a[j]/2 - (a[j]%2==0) < i){
                        ans = -1;
                        break;
                    }
                    else{
                        visited[i] = 1;
                        i++;
                        ans++;
                    }
                }
            }
            j++;
        }
        cout << ans << '\n';
    }

    return 0;
}