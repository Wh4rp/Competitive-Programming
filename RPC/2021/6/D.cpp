#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#define REPGET(_1, _2, _3, NAME, ...) NAME
#define rep3(i, b, n) for (int i = b; i < n; i++)
#define rep2(i, n) rep3(i, 0, n)
#define rep(...) REPGET(__VA_ARGS__, rep3, rep2)(__VA_ARGS__)
#define invrep3(i, b, n) for (int i = n - 1; i >= b; i--)
#define invrep2(i, n) invrep3(i, 0, n)
#define invrep(...) REPGET(__VA_ARGS__, invrep3, invrep2)(__VA_ARGS__)

typedef long long ll;

int n;
int a[100000];
int b[100000];

int cyclelen[100000];
bool visited1[100000], visited2[100000];;

ll mcm(ll a, ll b){
  return a * b / __gcd(a, b);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    rep(i, n) {
        cin >> a[i];
        a[i]-=1;
    }
    rep(i, n) {
        cin >> b[i];
        b[i]-=1;
    }

    ll tcycles1 = 1;
    rep(i, n) {
        int nxt = i;
        int cyclelen = 0;
        while(!visited1[nxt]) {
            visited1[nxt] = true;
            cyclelen += 1;
            nxt = a[b[nxt]];
        }

        if (cyclelen > 0) {
            tcycles1 = mcm(tcycles1, cyclelen);
            if (tcycles1 > 1000000000000ll) {
                break;
            }
        }
    }

    ll tcycles2 = 1;
    rep(i, n) {
        visited2[i] = true;
        int nxt = a[i];
        int cyclelen = 0;
        while(!visited2[nxt]) {
            visited2[nxt] = true;
            cyclelen += 1;
            nxt = b[a[nxt]];
        }

        if (cyclelen > 0) {
            tcycles2 = mcm(tcycles2, cyclelen);
            if (tcycles2 > 1000000000000ll) {
                break;
            }
        }
    }
    cout << 2 * tcycles1 << '\n';
    cout << 1 + 2 * tcycles2 << '\n';
    ll tcycles = min(2 * tcycles1, 1 + 2 * tcycles2);
    if (tcycles > 1000000000000ll) {
        cout << "huge\n";
        return 0;
    }
    cout << tcycles << endl;
}
