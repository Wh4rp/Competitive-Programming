#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)
#define rep_(i, k, n) for (int i = k; i < n; ++i)
using ll = long long;

#include <complex>
typedef complex<double> cd;
typedef long long ll;
const double PI = acos(-1);

void fft(vector<cd>& a, bool invert) {
    int n = a.size();
    for (int i = 1, j = 0; i < n; i++) {
        int bit = n >> 1;
        for (; j & bit; bit >>= 1)
            j ^= bit;
        j ^= bit;
        if (i < j)
            swap(a[i], a[j]);
    }
    for (int len = 2; len <= n; len <<= 1) {
        double angle = 2 * PI / len * (invert ? -1 : 1);
        cd wlen(cos(angle), sin(angle));
        for (int i = 0; i < n; i += len) {
            cd w(1);
            for (int j = 0; j < len / 2; j++) {
                cd u = a[i + j], v = a[i + j + len / 2] * w;
                a[i + j] = u + v;
                a[i + j + len / 2] = u - v;
                w *= wlen;
            }
        }
    }
    if (invert)
        for (cd& x : a)
            x /= n;
}

vector<int> multiply_polynomials(vector<int>& A, vector<int>& B) {
    int n = 1;
    while (n < A.size() + B.size())
        n <<= 1;
    vector<cd> FA(A.begin(), A.end()), FB(B.begin(), B.end());
    FA.resize(n), FB.resize(n);
    fft(FA, false);
    fft(FB, false);
    for (int i = 0; i < n; i++)
        FA[i] *= FB[i];
    fft(FA, true);
    vector<int> result(n);
    for (int i = 0; i < n; i++)
        result[i] = round(FA[i].real());
    while (!result.empty() && result.back() == 0)
        result.pop_back();
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    // -50000 to 50000
    int N = 100000, M = 50000;
    vector<int> poly(N + 1, 0);
    rep(i, n) {
        int num;
        cin >> num;
        num += M;
        poly[num]++;
    }
    // printeamos el polinomio
    // for (int i = 0; i <= N; i++) {
    //     cout << i << ' ';
    // }
    // cout << '\n';
    // for (int i = 0; i <= N; i++) {
    //     cout << poly[i] << ' ';
    // }
    // cout << '\n';
    vector<int> result = multiply_polynomials(poly, poly);
    // // printeamos el resultado
    // for (int i = 0; i <= 2 * N; i++) {
    //     cout << i << ' ';
    // }
    // cout << '\n';
    // for (int i = 0; i <= 2 * N; i++) {
    //     cout << result[i] << ' ';
    // }
    // cout << '\n';
    // restamos los repetidos
    rep(i, N + 1) {
        // cout << 2 * i << ' ' << poly[i] << '\n';
        result[2 * i] -= poly[i];
    }

    // // printeamos el resultado final
    // for (int i = 0; i <= 2 * N; i++) {
    //     cout << i << ' ';
    // }
    // cout << '\n';
    // for (int i = 0; i <= 2 * N; i++) {
    //     cout << result[i] << ' ';
    // }
    // cout << '\n';

    ll ans = 0;

    rep(i, 2 * N + 1) {
        if (i < N + 1 && poly[i] > 0) {
            ans +=  result[i];
        }
    }

    cout << ans << '\n';

    return 0;
}