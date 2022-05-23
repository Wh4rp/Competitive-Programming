#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)
#define rep_(i, k, n) for (int i = k; i < n; ++i)
using ll = long long;

int fRight = -1;
ll v[500005], x[500005];

double bs(int n){
    double l = 0, r = 2e9, m, now, GoRight;
    bool choque = false;
    
    rep(j, 62){
        bool smash = false;
        m = (l + r) * 0.5;
        GoRight = x[fRight] + v[fRight] * m;

        rep_(i, fRight + 1, n){
            now = x[i] + v[i] * m;
            if(v[i] > 0){
                GoRight = max(GoRight, now);
            }
            else{
                if(now < GoRight){
                    smash = true;
                    break;
                }
            }
        }

        if(smash){
            choque = true;
            r = m;
        }
        else
            l = m;
            
    }

    if(!choque)
        return -1;

    return m;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.setf(ios::fixed);
    cout.precision(11);
    
    int n;

    cin >> n;
    rep(i, n){
        cin >> x[i] >> v[i];
        if(fRight == -1 && v[i] > 0){
            fRight = i;
        }
    }
    if(fRight == -1){
        cout << "-1\n";
        return 0;
    }

    cout << bs(n) << '\n';
    return 0;
}