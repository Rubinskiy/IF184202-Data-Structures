#include <stdlib.h>
#include <stdio.h>
#include <stack>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

#define lld long long int

using namespace std;

struct AVLNode {
    int id;
    AVLNode *left, *right;
    int height;
};

struct AVL
{
private:
    AVLNode *_root;
    unsigned _size;

    AVLNode* _avl_createNode(int id) {
        AVLNode *newNode = (AVLNode*) malloc(sizeof(AVLNode));
        newNode->id = id;
        newNode->height = 1;
        newNode->left = newNode->right = NULL;
        return newNode;
    }

    AVLNode* _search(AVLNode *root, int value) {
        while (root != NULL) {
            if (value < root->id)
                root = root->left;
            else if (value > root->id)
                root = root->right;
            else
                return root;
        }
        return root;
    }

    int _getHeight(AVLNode* node){
        if(node==NULL)
            return 0; 
        return node->height;
    }

    int _max(int a,int b){
        return (a > b)? a : b;
    }

    AVLNode* _rightRotate(AVLNode* pivotNode){
        AVLNode* newParrent=pivotNode->left;
        pivotNode->left=newParrent->right;
        newParrent->right=pivotNode;

        pivotNode->height=_max(_getHeight(pivotNode->left),
                        _getHeight(pivotNode->right))+1;
        newParrent->height=_max(_getHeight(newParrent->left),
                        _getHeight(newParrent->right))+1;
        
        return newParrent;
    }

    AVLNode* _leftRotate(AVLNode* pivotNode) {
        AVLNode* newParrent=pivotNode->right;
        pivotNode->right=newParrent->left;
        newParrent->left=pivotNode;

        pivotNode->height=_max(_getHeight(pivotNode->left),
                        _getHeight(pivotNode->right))+1;
        newParrent->height=_max(_getHeight(newParrent->left),
                        _getHeight(newParrent->right))+1;
        
        return newParrent;
    }

    AVLNode* _leftCaseRotate(AVLNode* node){
        return _rightRotate(node);
    }

    AVLNode* _rightCaseRotate(AVLNode* node){
        return _leftRotate(node);
    }

    AVLNode* _leftRightCaseRotate(AVLNode* node){
        node->left=_leftRotate(node->left);
        return _rightRotate(node);
    }

    AVLNode* _rightLeftCaseRotate(AVLNode* node){
        node->right=_rightRotate(node->right);
        return _leftRotate(node);
    }

    int _getBalanceFactor(AVLNode* node){
        if(node==NULL)
            return 0;
        return _getHeight(node->left)-_getHeight(node->right);
    }

    AVLNode* _insert_AVL(AVLNode* node, int id) {
        
        if(node == NULL)
            return _avl_createNode(id);
        if(id < node->id)
            node->left = _insert_AVL(node->left, id);
        else if(id > node->id)
            node->right = _insert_AVL(node->right, id);
        
        node->height= 1 + _max(_getHeight(node->left),_getHeight(node->right)); 

        int balanceFactor=_getBalanceFactor(node);
        
        if(balanceFactor > 1 && id < node->left->id)
            return _leftCaseRotate(node);
        if(balanceFactor > 1 && id > node->left->id)
            return _leftRightCaseRotate(node);
        if(balanceFactor < -1 && id > node->right->id)
            return _rightCaseRotate(node);
        if(balanceFactor < -1 && id < node->right->id)
            return _rightLeftCaseRotate(node);
        
        return node;
    }

    AVLNode* _findMinNode(AVLNode *node) {
        AVLNode *currNode = node;
        while (currNode && currNode->left != NULL)
            currNode = currNode->left;
        return currNode;
    }

    AVLNode* _remove_AVL(AVLNode* node, int value){
        if(node==NULL)
            return node;
        if(value > node->id)
            node->right=_remove_AVL(node->right,value);
        else if(value < node->id)
            node->left=_remove_AVL(node->left,value);
        else{
            AVLNode *temp;
            if((node->left==NULL)||(node->right==NULL)){
                temp=NULL;
                if(node->left==NULL) temp=node->right;  
                else if(node->right==NULL) temp=node->left;
                
                if(temp==NULL){
                    temp=node;
                    node=NULL;
                }
                else
                    *node=*temp;   
                
                free(temp);
            }
            else{
                temp = _findMinNode(node->right);
                node->id=temp->id;
                node->right=_remove_AVL(node->right,temp->id);
            }    
        }

        if(node==NULL) return node;
        
        node->height=_max(_getHeight(node->left),_getHeight(node->right))+1;

        int balanceFactor= _getBalanceFactor(node);
        
        if(balanceFactor>1 && _getBalanceFactor(node->left)>=0) 
            return _leftCaseRotate(node);

        if(balanceFactor>1 && _getBalanceFactor(node->left)<0) 
            return _leftRightCaseRotate(node);
    
        if(balanceFactor<-1 && _getBalanceFactor(node->right)<=0) 
            return _rightCaseRotate(node);

        if(balanceFactor<-1 && _getBalanceFactor(node->right)>0) 
            return _rightLeftCaseRotate(node);
        
        return node;
    }

    void _inorder(AVLNode *node) {
        if (node) {
            _inorder(node->left);
            printf("%d ", node->id);
            _inorder(node->right);
        }
    }

public:
    void init() {
        _root = NULL;
        _size = 0U;
    }

    bool isEmpty() {
        return _root == NULL;
    }

    bool find(int value) {
        AVLNode *temp = _search(_root, value);
        if (temp == NULL)
            return false;
        
        if (temp->id == value) return true;
        else return false;
    }

    void insert(int id) {
        if (!find(id)) {
            _root = _insert_AVL(_root, id);
            _size++;
        }
    }

    void remove(int value) {
        if (find(value)) {
            _root = _remove_AVL(_root, value);
            _size--;
        }
    }

    void inorder() {
        this->_inorder(_root);
    }

    AVLNode* getRoot() {
        return _root;
    }

    int getHeightOfTree(AVLNode* node) {
        if (node == NULL) {
            return 0;
        } else {
            return node->height;
        }
    }

    int getLevelOfNode(AVLNode* node, int value, int level) {
        if (node == NULL) {
            return 0;
        } else if (node->id == value) {
            return level;
        } else if (node->id > value) {
            return getLevelOfNode(node->left, value, level + 1);
        } else if (node->id < value) {
            return getLevelOfNode(node->right, value, level + 1);
        }
    }

    int getSize() {
        return _size;
    }
};

int main(int argc, char const *argv[])
{
    AVL set;
    set.init();

    vector<pair<int, pair<lld, string>>> stock;

    while (true) {
        int id;
        lld price;
        string name;

        scanf("%d", &id);
        scanf("%lld", &price);
        cin >> name;
        if (id == 0 && price == 0 && name == "0") {
            break;
        } else {
            stock.push_back(make_pair(id, make_pair(price, name)));
            set.insert(id);
        }
    }

    while (true) {
        lld id;
        cin >> id;
        if (id == 0) {
            break;
        }

        // find based on id and return id, price, name
        if (set.find(id)) {
            // get height of tree
            int height = set.getHeightOfTree(set.getRoot());
            // get level of node
            int level = set.getLevelOfNode(set.getRoot(), id, 1);
            level = height - level;
            cout << "Item found at page " << level + 1 << endl;
            cout << "Item detail: id=" << id << ", name=" << stock[id-1].second.second << ", price=" << stock[id-1].second.first << endl;
            continue;
        } else {
            cout << "404 NOT FOUND" << endl;
        }
    }

    return 0;
}