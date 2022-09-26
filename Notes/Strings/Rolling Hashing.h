#include "../../Template.cpp"

const int MAXN = 1e5 + 5;
const int A = 31;
const int B = 1e9 + 7;

int n;
string s;
int h[MAXN], p[MAXN];

// Preprocess the powers of A and the hash
// for each substring s[0..i]

void preprocess() {
    p[0] = 1;
    for (int i = 1; i <= n; i++) {
        p[i] = (p[i - 1] * A) % B;
    }
    h[n] = s[n - 1];
    for (int i = n - 1; i >= 0; i--) {
        h[i] = (h[i + 1] * A + s[i]) % B;
    }
}

// Get the hash of the string s[i..j]

int get_hash(int i, int j) {
    return (h[i] - h[j + 1] * p[j - i + 1] + B) % B;
}
