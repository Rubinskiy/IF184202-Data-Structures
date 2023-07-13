#include <iostream>
#include <cstdio>
using namespace std;

struct Node {
    unsigned int id;
    unsigned int sales;
    double profit;
    Node* left;
    Node* right;

    Node(unsigned int id, unsigned int sales, double profit) {
        this->id = id;
        this->sales = sales;
        this->profit = profit;
        this->left = nullptr;
        this->right = nullptr;
    }
};

Node* insert_node(Node* root, unsigned int id, unsigned int sales, double profit) {
    if (root == nullptr) {
        return new Node(id, sales, profit);
    }
    if (sales > root->sales || (sales == root->sales && profit > root->profit)) {
        root->right = insert_node(root->right, id, sales, profit);
    } else {
        root->left = insert_node(root->left, id, sales, profit);
    }
    return root;
}

double traverse_tree(Node* root, unsigned int target_id, double total_profit) {
    if (root == nullptr) {
        return 0.0;
    }
    if (root->id == target_id) {
        return total_profit;
    }
    total_profit += root->profit;
    if (root->sales == 0) {
        return 0.0;
    }
    if (root->left == nullptr) {
        return traverse_tree(root->right, target_id, total_profit);
    }
    if (root->right == nullptr) {
        return traverse_tree(root->left, target_id, total_profit);
    }
    double left_profit = traverse_tree(root->left, target_id, total_profit);
    double right_profit = traverse_tree(root->right, target_id, total_profit + root->left->profit + root->profit);
    return left_profit + right_profit;
}

int main() {
    unsigned int M, T;
    cin >> M;

    Node* root = nullptr;
    for (unsigned int i = 0; i < M; i++) {
        unsigned int id, sales;
        double profit;
        scanf("%u %u %lf", &id, &sales, &profit);
        root = insert_node(root, id, sales, profit);
    }

    cin >> T;
    for (unsigned int i = 0; i < T; i++) {
        unsigned int target_id, target_sales;
        double target_profit;
        scanf("%u %u %lf", &target_id, &target_sales, &target_profit);
        double total_profit = traverse_tree(root, target_id, 0.0);
        printf("%.6f\n", total_profit);
    }

    return 0;
}

/*
when member insert:
- if sales > cur sales = right
- if sales == cur sales && profit > cur profit == right

go to a leaf by members with least profit
print the total profit of the members had to visit to go to the leaf

int m;
for int i < m:
	cin id sales profit;

int t;
for int i < t:
	cin id sales profit;
*/