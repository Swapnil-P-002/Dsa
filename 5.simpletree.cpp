#include <iostream>
using namespace std;

struct Node {
    string key, meaning;
    Node *left, *right;
    Node(string k, string m) : key(k), meaning(m), left(nullptr), right(nullptr) {}
};

Node* add(Node* root, string key, string meaning) {
    if (root == nullptr) {
        return new Node(key, meaning);
    }
    if (key < root->key) {
        root->left = add(root->left, key, meaning);
    } 
    else if (key > root->key) {
        root->right = add(root->right, key, meaning);
    } 
    else {
        root->meaning = meaning;
    }
    return root;
}

void show(Node* root) {
    if (root != nullptr) {
        show(root->left);
        cout << root->key << ": " << root->meaning << endl;
        show(root->right);
    }
}

int main() {
    Node* root = nullptr;
    string key, meaning;

    root = add(root, "apple", "a fruit");
    root = add(root, "ball", "a round object");
    root = add(root, "cat", "an animal");

    show(root);

    return 0;
}