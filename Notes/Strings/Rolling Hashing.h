#include "../../Template.cpp"

// Polynomial Rolling Hashing

int pol_hash(string s) {
    int A = 31, B = 1e9 + 7;
    int ans = 0;
    for(char c : s){
        ans = (ans * A + c) % B;
    }
    return ans;
}

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
    h[0] = s[0];
    for (int i = 1; i < n; i++) {
        h[i] = (h[i - 1] * A + s[i]) % B;
    }
}

// Get the hash of the string s[i..j]

int get_hash(int i, int j) {
    return i != 0 ? (h[j] - h[i-1] * p[j-i+1] + B*B) % B : h[j];
}

// Usage example

int main() {
    cin >> s;
    n = s.size();
    preprocess();
    string r = "PABLO";
    int m = r.size();
    int l = pol_hash(r);
    for (int i = 0; i + m - 1 < n; i++) {
        if (get_hash(i, i + m - 1) == l) {
            cout << i << '\n';
            break;
        }
    }
    return 0;
}