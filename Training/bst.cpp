#include <bits/stdc++.h>
using namespace std;

struct Node {
    int v;
    Node* left = NULL;
    Node* right = NULL;
};

class BST {
    public:
        Node* root = NULL;
    public:
        Node* new_node(int v) {
            Node* n = new Node;
            n->v = v;
            return n;
        }

        void insert(int v) {
            Node*& c = root;
            while (c != NULL) {
                if (v < c->v) {
                    if (c->left == NULL) {
                        c->left = new_node(v);
                        return;
                    } else 
                        c = c->left;
                } else {
                    if (c->right == NULL) {
                        c->right = new_node(v);
                        return;
                    } else
                        c = c->right;
                }
            }
        }

        bool search(int v) {
            Node* c = root;
            while (c != NULL) {
                if (c->v == v) 
                    return true;
                if (v < c->v)
                    c = c->left;
                else
                    c = c->right;
            }
            return false;
        }
};

int main() {
    BST bst;
    bst.insert(5);
    cout << bst.root->v;
    bst.insert(15);
    bst.insert(25);

    //cout << bst.search(10);
    //cout << bst.search(20);
    //cout << bst.search(15);
}
