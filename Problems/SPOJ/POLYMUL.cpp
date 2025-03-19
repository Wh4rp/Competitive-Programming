#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < n; ++i)
#define rep_(i, k, n) for (int i = k; i < n; ++i)
using ll = long long;

using cd = complex<double>;
const double PI = acos(-1);

void fft(vector<cd> &a, bool inv) {
    int N = a.size(), k = 0, b;
    assert(N == 1 << __builtin_ctz(N));
    rep_(i, 1, N) {
        for (b = N >> 1; k & b;) k ^= b, b >>= 1;
        if (i < (k ^= b)) swap(a[i], a[k]);
    }
    for (int l = 2; l <= N; l <<= 1) {
        double ang = 2 * PI / l * (inv ? -1 : 1);
        cd wl(cos(ang), sin(ang));
        for (int i = 0; i < N; i += l) {
            cd w = 1;
            rep(j, l / 2) {
                cd u = a[i + j], v = a[i + j + l / 2] * w;
                a[i + j] = u + v;
                a[i + j + l / 2] = u - v;
                w *= wl;
            }
        }
    }
    if (inv) rep(i, N) a[i] /= N;
}

void convolve(vector<cd> &a, vector<cd> b, int n) {
    n = 1 << (32 - __builtin_clz(2 * n - 1));
    a.resize(n), b.resize(n);
    fft(a, false), fft(b, false);
    rep(i, n) a[i] *= b[i];
    fft(a, true);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<cd> A(n + 1), B(n + 1);

        rep(i, n + 1) {
            double x;
            cin >> x;
            A[i] = x;
        }
        rep(i, n + 1) {
            double x;
            cin >> x;
            B[i] = x;
        }

        convolve(A, B, n + 1);

        rep(i, (2 * n) + 1) {
            cout << ll(round(A[i].real())) << " \n"[i == 2 * n];
        }
    }

    return 0;
}
