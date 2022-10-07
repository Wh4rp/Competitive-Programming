#include "../../Template.cpp"

vector<int> failure_function(string pattern) {
    int n = pattern.size();
    vector<int> f(n + 1);
    f[0] = f[1] = 0;
    for (int i = 2; i <= n; i++) {
        int j = f[i - 1];

        while (j > 0 && pattern[j] != pattern[i - 1]) {
            j = f[j];
        }

        if (pattern[j] == pattern[i - 1]) {
            j++;
        }

        f[i] = j;
    }
    return f;
}

vector<int> kmp(string text, string pattern) {
    vector<int> f = failure_function(pattern);
    vector<int> matches;
    int n = text.size();
    int m = pattern.size();
    int i = 0, j = 0;
    while (i < n) {
        if (text[i] == pattern[j]) {
            i++;
            j++;
            if (j == m) {
                matches.push_back(i - m);
                j = f[j];
            }
        } else if (j > 0) {
            j = f[j];
        } else {
            i++;
        }
    }
    return matches;
}

// Usage

int main() {
    string pattern = "ABABAC";
    string text = "ABABABAC";

    auto matches = kmp(text, pattern);

    for (int i : matches) {
        cout << i << '\n';
    }

    return 0;
}