#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *left; //left child
    Node *right; //Right child
};

Node *getNewNode(int data) {
    Node *newNode = new Node();
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// insert an element to a tree
Node *insertTree(Node *root, int n) {
    //if the tree is empty
    if (root == NULL) {
        root = getNewNode(n);

    } else if(n <= root->data) {
        // if data of the node is smaller, make it left child. 
        // recursion will create a new node for the child.
        root->left = insertTree(root->left, n);

    } else {
        // if data of the node is greater, make it right child. 
        // recursion will create a new node for the child.
        root->right = insertTree(root->right, n);
    }
    return root;
}

int heightOfTree(Node *root) {
    // stop conditiion
    if (root == NULL) {
        return -1;
    }
    // get the max height
    int max_height_of_left = heightOfTree(root->left);
    int max_height_of_right = heightOfTree(root->right);
    if (max_height_of_left > max_height_of_right) {
        return max_height_of_left + 1;
    } else {
        return max_height_of_right + 1;
    }
}

void preorderTraversal(Node *root) {
    if (root == NULL) return;
    //root->left->right
    cout << root->data << " ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

void postorderTraversal(Node *root) {
    if (root == NULL) return;
    //left->right->root
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout << root->data << " ";
}

void inorderTraversal(Node *root) {
    if (root == NULL) return;
    //left->root->right
    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}

int main() {
    Node *root = getNewNode(1);
    root->left = getNewNode(2);
    root->right = getNewNode(3);
    root->left->left = getNewNode(4);
    root->left->right = getNewNode(5);
    cout << heightOfTree(root) << endl;
    preorderTraversal(root);
    cout << endl;
    postorderTraversal(root);
    cout << endl;
    inorderTraversal(root);
    cout << endl;
    return 0;
}
