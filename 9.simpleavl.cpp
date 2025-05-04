#include <iostream>
#include <string>
using namespace std;

struct Node {
    string keyword, meaning;
    Node* left = nullptr;
    Node* right = nullptr;
};

Node* insert(Node* node, string keyword, string meaning) {
    if (!node) {
        node = new Node;
        node->keyword = keyword;
        node->meaning = meaning;
        return node;
    }

    if (keyword < node->keyword) 
        node->left = insert(node->left, keyword, meaning);
    else 
        node->right = insert(node->right, keyword, meaning);

    return node;
}

void inorder(Node* node) {
    if (!node) return;
    inorder(node->left);
    cout << node->keyword << " : " << node->meaning << endl;
    inorder(node->right);
}

int main() {
    Node* root = nullptr;
    int choice;
    string keyword, meaning;

    do {
        cout << "\n1. Add keyword\n2. Display\n3. Exit\nEnter choice: ";
        cin >> choice;
        switch(choice) {
            case 1:
                cout << "Enter keyword: "; cin >> keyword;
                cout << "Enter meaning: "; cin.ignore(); getline(cin, meaning);
                root = insert(root, keyword, meaning);
                break;
            case 2:
                inorder(root);
                break;
            case 3:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while(choice != 3);

    return 0;
}
