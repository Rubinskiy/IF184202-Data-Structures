#include <iostream>
#include <queue>
#include <bits/stdc++.h>
#include <climits>

#define lld long long int
using namespace std;

struct Node {
    lld data;
    Node* left;
    Node* right;

    Node(lld value) {
        data = value;
        left = NULL;
        right = NULL;
    }
};

Node* insert(Node* node, lld value) {
    if (node == NULL) {
        return new Node(value);
    }
    if (value < node->data) {
        node->left = insert(node->left, value);
    } else if (value > node->data) {
        node->right = insert(node->right, value);
    }
    return node;
}

void find_rightmost_nodes(Node* root, queue<Node*> values, lld values_size, lld max_value) {
    if (root == NULL) {
        return;
    }
    values.push(root);
    while (!values.empty()) {
        values_size = values.size();
        max_value = numeric_limits<lld>::min();
        while (values_size > 0) {
            Node* node = values.front();
            values.pop();
            max_value = max(max_value, node->data);
            if (node->left != NULL) {
                values.push(node->left);
            }
            if (node->right != NULL) {
                values.push(node->right);
            }
            values_size--;
        }
        cout << max_value << endl;
	}
}

int main() {
    Node* root = NULL;
    queue<Node*> values;
    lld num;
    while (cin >> num) {
        root = insert(root, num);
    }
    lld values_size = values.size();
    lld max_value = numeric_limits<lld>::min();
    find_rightmost_nodes(root, values, values_size, max_value);
    return 0;
}
