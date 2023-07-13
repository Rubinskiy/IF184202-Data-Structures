#include <iostream>
#include <bits/stdc++.h>

#define lld long long int

using namespace std;

typedef struct bstnode_t {
    lld key;
    struct bstnode_t* left, * right;
} BSTNode;

BSTNode* createNode(lld value) {
    BSTNode* newNode = (BSTNode*)malloc(sizeof(BSTNode));
    newNode->key = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

BSTNode* insert(BSTNode* root, lld value) {
    if (root == NULL)
        return createNode(value);

    if (value < root->key)
        root->left = insert(root->left, value); 
    else if (value > root->key)
        root->right = insert(root->right, value);

    return root;
}

BSTNode* search(BSTNode* root, lld value) {
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

BSTNode* findMinNode(BSTNode* node) {
    BSTNode* currNode = node;
    while (currNode && currNode->left != NULL)
        currNode = currNode->left;
    return currNode;
}

BSTNode* remove(BSTNode* root, lld value) {
    if (root == NULL)
        return NULL;

    if (value > root->key)
        root->right = remove(root->right, value);
    else if (value < root->key)
        root->left = remove(root->left, value);
    else {

        if (root->left == NULL) {
            BSTNode* rightChild = root->right;
            free(root);
            return rightChild;
        } else if (root->right == NULL) {
            BSTNode* leftChild = root->left;
            free(root);
            return leftChild;
        }

        BSTNode* temp = findMinNode(root->right);
        root->key = temp->key;
        root->right = remove(root->right, temp->key);
    }
    return root;
}

void printNodesOneChild(BSTNode* root, vector<lld>& values) {
    if (root == NULL) {
        return;
    }
    printNodesOneChild(root->right, values);
    if ((root->left != NULL &&
        root->right == NULL) ||
    (root->left == NULL &&
        root->right != NULL)) {
        values.push_back(root->key);
    }
    printNodesOneChild(root->left, values);
}

int main() {
    //BST set;
    //set.init();
    // apparentyl if you pass the root node to the main function it works
    BSTNode* root = NULL;
    vector<lld> values;

    lld n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        lld x, input;
        cin >> input;
        if (input == 15) {
            // insert into bst
            cin >> x;
            //set.insert(x);
            root = insert(root, x);
        } else if (input == 4) {
            // remove from bst
            cin >> x;
            //set.remove(x);
            root = remove(root, x);
        } else if (input == 89) {
            // print all nodes that has one child with an ascending order
            //set.modified_inorder(set._root, values);
            printNodesOneChild(root, values);

            // print the instr
            if (values.empty()) {
                cout << "Use whatever means you must to control our population. Just do it." << endl;
            } else {
                // print the values from the back
                while (!values.empty()) {
                    cout << values.back() << " ";
                    values.pop_back();
                }
                cout << endl;
            }

            /*
            BSTNode *parent = NULL;
            BSTNode *child = NULL;
            set.findOneChildNodes(set._root, parent, child, values);
            if (values.empty()) {
                cout << "Use whatever means you must to control our population. Just do it.";
            }
            // print the map in ascending order
            for (auto it = values.begin(); it != values.end(); it++) {
                cout << it->first << " ";
            }
            cout << endl;
            */
        }
    }
    return 0;
}