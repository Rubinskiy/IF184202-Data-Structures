#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct bstnode_t {
    int key;
    struct bstnode_t *left;
    struct bstnode_t *right;
} BSTNode;

typedef struct bst_t {
    BSTNode *_root;
    unsigned int _size;
} BST;

void bst_init(BST *bst) {
    bst->_root = NULL;
    bst->_size = 0;
}

BSTNode*__bst__createNode(int value) {
    BSTNode *newNode = (BSTNode*) malloc(sizeof(BSTNode));
    newNode->key = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

BSTNode* __bst__search(BSTNode *root, int value) {
    while(root != NULL) {
        if (value < root->key) {
            root = root->left;
        } else if (value > root->key) {
            root = root->right;
        } else {
            return root;
        }
    }
    return root;
}

bool bst_find(BST *bst, int value) {
    BSTNode *temp = __bst__search(bst->_root, value);
    if (temp == NULL) {
        return false;
    }

    if (temp->key == value) {
        return true;
    } else {
        return false;
    }
}

BSTNode* __bst__insert(BSTNode *root, int value) {
    if (root == NULL) {
        return __bst__createNode(value);
    }

    if (value < root->key) {
        root->left = __bst__insert(root->left, value);
    } else if (value > root->key) {
        root->right = __bst__insert(root->right, value);
    }

    return root;
}

void bst_insert(BST *bst, int value) {
    if (!bst_find(bst, value)) {
        bst->_root = __bst__insert(bst->_root, value);
        bst->_size++;
    }
}

BSTNode* __bst__findMinNode(BSTNode *node) {
    BSTNode *currNode = node;
    while (currNode && currNode->left != NULL) {
        currNode = currNode->left;
    }
    return currNode;
}

BSTNode *__bst__remove(BSTNode *root, int value) {
    if (root == NULL) {
        return NULL;
    }

    if (value < root->key) {
        root->left = __bst__remove(root->left, value);
    } else if (value > root->key) {
        root->right = __bst__remove(root->right, value);
    } else {
        if (root->left == NULL) {
            BSTNode *rightChild = root->right;
            free(root);
            return rightChild;
        } else if (root->right == NULL) {
            BSTNode *leftChild = root->left;
            free(root);
            return leftChild;
        }

        BSTNode *temp = __bst__findMinNode(root->right);
        root->key = temp->key;
        root->right = __bst__remove(root->right, temp->key);
    }
    return root;
}

void bst_remove(BST *bst, int value) {
    if (bst_find(bst, value)) {
        bst->_root = __bst__remove(bst->_root, value);
        bst->_size--;
    }
}

// orders
void __bst__inorder(BSTNode *root) {
    if (root) {
        __bst__inorder(root->left);
        printf("%d ", root->key);
        __bst__inorder(root->right);
    }
}
void bst_inorder(BST *bst) {
    __bst__inorder(bst->_root);
}

void __bst__preorder(BSTNode *root) {
    if (root) {
        printf("%d ", root->key);
        __bst__preorder(root->left);
        __bst__preorder(root->right);
    }
}
void bst_preorder(BST *bst) {
    __bst__preorder(bst->_root);
}

void __bst__postorder(BSTNode *root) {
    if (root) {
        __bst__postorder(root->left);
        __bst__postorder(root->right);
        printf("%d ", root->key);
    }
}
void bst_postorder(BST *bst) {
    __bst__postorder(bst->_root);
}

// find lowest common ancestor of two nodes
int find_lca(BSTNode *root, int x) {
    if (root->key == x) {
        return 0;
    } else if (root->key > x) {
        return 1 + find_lca(root->left, x);
    } else {
        return 1 + find_lca(root->right, x);
    }
}

// minimum distance between two nodes
int find_min_distance(BSTNode *root, int node1, int node2) {
    if (!root) {
        return 0;
    }

    if (root->key > node1 && root->key > node2) {
        return find_min_distance(root->left, node1, node2);
    }
    if (root->key < node1 && root->key < node2) {
        return find_min_distance(root->right, node1, node2);
    }
    if (root->key >= node1 && root->key <= node2) {
        return find_lca(root, node1) + find_lca(root, node2);
    }
    return 0;
}

int main() {
    BST bst;
    bst_init(&bst);

    int n = 0;
    scanf("%d", &n);
    int nums[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    // make a bst from the array nums
    for (int i = 0; i < n; i++) {
        bst_insert(&bst, nums[i]);
    }

    int tests = 0;
    scanf("%d", &tests);
    int results[100];
    for (int i = 0; i < tests; i++) {
        int a = 0, b = 0;
        scanf("%d %d", &a, &b);
        results[i] = find_min_distance(bst._root, a, b);
    }

    // print the results array
    for (int i = 0; i < tests; i++) {
        printf("%d ", results[i]);
    }
    
    return 0;
}