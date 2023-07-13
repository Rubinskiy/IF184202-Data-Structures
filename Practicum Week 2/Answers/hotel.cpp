#include <iostream>
using namespace std;

class Node {
public:
    int key;
    Node* left;
    Node* right;
    Node(int k) {
        key = k;
        left = nullptr;
        right = nullptr;
    }
};

class BST {
public:
    Node* root;
    BST() {
        root = nullptr;
    }

    void insert(int k) {
        if (root == nullptr) {
            root = new Node(k);
            return;
        }
        Node* cur = root;
        while (true) {
            if (k < cur->key) {
                if (cur->left == nullptr) {
                    cur->left = new Node(k);
                    break;
                } else {
                    cur = cur->left;
                }
            } else if (k > cur->key) {
                if (cur->right == nullptr) {
                    cur->right = new Node(k);
                    break;
                } else {
                    cur = cur->right;
                }
            } else {
                break;  // don't allow duplicate keys
            }
        }
    }

    void inorderTraversal(Node* node) {
        if (node == nullptr) {
            return;
        }
        inorderTraversal(node->left);
        cout << node->key << " ";
        inorderTraversal(node->right);
    }

    void traverseInorder() {
        inorderTraversal(root);
    }
    
    bool findPath(Node* node, int k) {
        if (node == nullptr) {
            return false;
        }
        if (node->key == k) {
            cout << k << " ";
            return true;
        }
        if (k < node->key) {
            if (findPath(node->left, k)) {
                cout << node->key << " ";
                return true;
            }
        } else {
            if (findPath(node->right, k)) {
                cout << node->key << " ";
                return true;
            }
        }
        return false;
    }

    void printPath(int k) {
        if (!findPath(root, k)) {
            cout << "path not found" << endl;
        }
    }

    void init() {
        root = nullptr;
    }
};

int main(int argc, char const *argv[]) {
    BST set;
    set.init();

    int num, seq;
    int value;

    cin >> num >> seq;

    for (int i = 0; i < num; i++) {
        cin >> value;
        set.insert(value);
    }
    
    for (int i = 1; i <= seq; i++) {
        cin >> value;
        cout << i << ": ";
        set.printPath(value);
    }

    return 0;
}