#include "../../Template.cpp"

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

// Usage

int main() {
    Trie trie;
    trie.insert("trie");
    trie.insert("tree");

    cout << trie.find("trie") << endl;
    cout << trie.find("tree") << endl;
    cout << trie.find("tr") << endl;

    return 0;
}