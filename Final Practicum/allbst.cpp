#include <bits/stdc++.h>

#define lld long long int

using namespace std;

/* Node structure */

struct BSTNode {
    BSTNode *left, *right;
    int key;
};

/* uniqueBST */

struct BST {
    // Member
    BSTNode *_root;
    unsigned int _size;

    // Function
    void init() {
        _root = NULL;
        _size = 0u;
    }

    bool isEmpty() {
        return _root == NULL;
    }

    bool find(int value) {
        BSTNode *temp = __search(_root, value);
        if (!temp)
            return false;
        
        if (temp->key == value)
            return true;
        else
            return false;
    }

    void insert(int value) {
        if (!find(value)) {
            _root = __insert(_root, value);
            _size++;
        }
    }

    void remove(int value) {
        if (find(value)) {
            _root = __remove(_root, value);
            _size++;
        }
    }

    void traverseInorder() {
        __inorder(_root);
    }

    void traversePreorder() {
        __preorder(_root);
    }

    void traversePostorder() {
        __postorder(_root);
    }

public:
    // Utility Function
    BSTNode* __createNode(int value) {
        BSTNode *newNode = (BSTNode*) malloc(sizeof(BSTNode));
        newNode->key = value;
        newNode->left = newNode->right = NULL;
        return newNode;
    }
    
    BSTNode* __search(BSTNode *root, int value) {
        while (root != NULL) {
            if (value < root->key)
                root = root->left;
            else if (value > root->key)
                root = root->right;
            else
                return root;
        }
        return root;
    }

    BSTNode* __insert(BSTNode *root, int value) {
        if (root == NULL)
            return __createNode(value);
        
        if (value < root->key)
            root->left = __insert(root->left, value);
        else if (value > root->key)
            root->right = __insert(root->right, value);
        
        return root;
    }

    BSTNode* __findMinNode(BSTNode *node) {
        BSTNode *currNode = node;
        while (currNode && currNode->left != NULL)
            currNode = currNode->left;
        
        return currNode;
    }

    BSTNode* __remove(BSTNode *root, int value) {
        if (root == NULL) return NULL;

        if (value > root->key) 
            root->right = __remove(root->right, value);
        else if (value < root->key) 
            root->left = __remove(root->left, value);
        else {

            if (root->left == NULL) {
                BSTNode *rightChild = root->right;
                free(root);
                return rightChild;
            }
            else if (root->right == NULL) {
                BSTNode *leftChild = root->left;
                free(root);
                return leftChild;
            }

            BSTNode *temp = __findMinNode(root->right);
            root->key     = temp->key;
            root->right   = __remove(root->right, temp->key);
        }
        return root;
    }

    void __inorder(BSTNode *root) {
        if (root) {
            __inorder(root->left);
            printf("%d ", root->key);
            __inorder(root->right);
        }
    }

    void __postorder(BSTNode *root) {
        if (root) {
            __postorder(root->left);
            __postorder(root->right);
            printf("%d ", root->key);
        }
    }

    void __preorder(BSTNode *root) {
        if (root) {
            printf("%d ", root->key);
            __preorder(root->left);
            __preorder(root->right);
        }
    }

    int getHeight(
        BSTNode *root
    ) {
        if (root == NULL) return 0;
        return max(
            getHeight(root->left),
            getHeight(root->right)
        ) + 1;
    }
    
    int getLevelOfNode(
        BSTNode *root,
        int value
    ) {
        if (root == NULL) return 0;
        if (root->key == value) return 1;
        if (value < root->key) return getLevelOfNode(root->left, value) + 1;
        if (value > root->key) return getLevelOfNode(root->right, value) + 1;
    }

    int inorderIndex(BSTNode* root, int& count, int x) {
        if (root == nullptr)
            return -1;

        int leftIndex = inorderIndex(root->left, count, x);
        if (leftIndex != -1)
            return leftIndex;

        count++;
        if (count == x)
            return root->key;

        return inorderIndex(root->right, count, x);
    }

    int getInorderValue(BSTNode* root, int x) {
        int count = 0;
        return inorderIndex(root, count, x);
    }

    void pathToXUsingStrings(
        BSTNode *root,
        int x,
        string& path
    ) {
        if (root == NULL) return;
        if (root->key == x) {
            path += "S";
            cout << "S";
            return;
        };
        if (x < root->key) {
            path += "L";
            cout << "L";
            pathToXUsingStrings(root->left, x, path);
        } else {
            path += "R";
            cout << "R";
            pathToXUsingStrings(root->right, x, path);
        }
    }
};

int main(int argc, char const *argv[])
{
    BST set;
    set.init();

    while (true) {
        string input;
        cin >> input;
        if (input == "IN") {
            lld x;
            cin >> x;
            set.insert(x);
        } else if (input == "FD") {
            // print level of x
            lld x;
            cin >> x;
            if (set.find(x)) {
                cout << "on level " << set.getLevelOfNode(set._root, x) << endl;
            } else {
                cout << "no " << x << endl;
            }
        } else if (input == "RK") {
            // print out the x-th index in an inorder sequence
            lld x;
            cin >> x;
            cout << set.getInorderValue(set._root, x) << endl;
        } else if (input == "PH") {
            // print path to x (e.g. left = L, right = R, stop = S)
            lld x;
            cin >> x;
            if (set.find(x)) {
                string path = "";
                set.pathToXUsingStrings(set._root, x, path);
                cout << endl;
            } else {
                cout << "no " << x << endl;
            }
        } else if (input == "STOP") {
            cout << "done" << endl;
            return 0;
        }
    }
    
    return 0;
}