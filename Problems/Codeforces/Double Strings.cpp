#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)
#define rep_(i, k, n) for (int i = k; i < n; ++i)
using ll = long long;

class Trie {
    struct Node {
        char c;
        bool leaf;
        vector<Node*> children;
        Node(char c) : c(c), leaf(false) {}
    };
    Node* root;

   public:
    Trie() : root(new Node('\0')) {}
    void insert(string s) {
        Node* cur = root;
        for (char c : s) {
            bool found = false;
            for (Node* child : cur->children) {
                if (child->c == c) {
                    cur = child;
                    found = true;
                    break;
                }
            }
            if (!found) {
                Node* new_node = new Node(c);
                cur->children.push_back(new_node);
                cur = new_node;
            }
        }
        cur->leaf = true;
    }
    bool find(string s) {
        Node* cur = root;
        for (char c : s) {
            bool found = false;
            for (Node* child : cur->children) {
                if (child->c == c) {
                    cur = child;
                    found = true;
                    break;
                }
            }
            if (!found)
                return false;
        }
        return cur->leaf;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.setf(ios::fixed);
    cout.precision(10);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> ans(n);
        vector<string> v;
        Trie trie;
        rep(i, n) {
            string s;
            cin >> s;
            v.push_back(s);
            trie.insert(s);
        }
        
        rep(i, n){
            bool match = false;
            int m = v[i].length();
            rep_(j, 1, m){
                if(trie.find(v[i].substr(0, j)) && trie.find(v[i].substr(j, m-j))){
                    match = true;
                    break;
                }
            }
            ans[i] = match;
        }

        rep(i, n)
            cout << ans[i];
        cout << '\n';
    }

    return 0;
}