#include<bits/stdc++.h>

using namespace std;

int main(){
    int n, q, Q;
    cin >> n >> q;
    vector<int> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    for(int i = 0; i < q; i++){
        cin >> Q;
        auto x = upper_bound(v.begin() , v.end(), Q) - v.begin();
        if(x != 0 && v[x - 1] == Q){
            cout << x - 1 << '\n';
        }
        else{
            cout << "-1\n";
        }
        
    }

    return 0;
}