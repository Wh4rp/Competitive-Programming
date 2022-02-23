#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){

        int n;
        bool sorted = true;
        cin >> n;
        int v[n];
        cin >> v[0];
        for(int i = 1; i < n; i++){
            cin >> v[i];
            if(v[i-1] > v[i]){
                sorted = false;
            }
        }
        sorted? cout << "NO\n" : cout << "YES\n";
    }
    return 0;
}