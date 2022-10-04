#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)
#define rep_(i, k, n) for (int i = k; i < n; ++i)
using ll = long long;

const int MAXN = 1e5 + 5;
const ll A = 31;
const ll B = 1e9 + 7;

int n;
string s, r;
ll h[MAXN], p[MAXN];

int make_hash(string x){
    int ans = 0;
    for(char c : x){
        ans = (ans * A + c) % B;
    }
    return ans;
}

void preprocess() {
    p[0] = 1;
    for (int i = 1; i <= n; i++) {
        p[i] = (p[i - 1] * A) % B;
    }
    h[0] = s[0];
    for (int i = 1; i < n; i++) {
        h[i] = (h[i - 1] * A + s[i]) % B;
    }
}

int get_hash(int i, int j) {
    return i != 0 ? (h[j]-h[i-1]*p[j-i+1] + B*B) % B : h[j];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.setf(ios::fixed);
    cout.precision(10);
    
    int ans = 0;
    cin >> s >> r;
    n = s.size();
    preprocess();
    int m = r.size();
    int h = make_hash(r);
    for (int i = 0; i + m - 1 < n; i++) {
      if (get_hash(i, i + m - 1) == h) {
          ans++;
      }
    }

    cout << ans << '\n';

    return 0;
}