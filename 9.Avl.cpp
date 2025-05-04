#include <iostream>
#include <string>
using namespace std;

struct Node {
    string keyword, meaning;
    Node *left, *right;
    int height;
    Node(string k, string m) : keyword(k), meaning(m), left(NULL), right(NULL), height(1) {}
};

class AVLDictionary {
public:
    Node* root;
    AVLDictionary() : root(NULL) {}

    int height(Node* node) { return node ? node->height : 0; }
    int balanceFactor(Node* node) { return height(node->left) - height(node->right); }
    void updateHeight(Node* node) { node->height = max(height(node->left), height(node->right)) + 1; }

    Node* leftRotate(Node* x) {
        Node* y = x->right;
        x->right = y->left, y->left = x;
        updateHeight(x), updateHeight(y);
        return y;
    }

    Node* rightRotate(Node* y) {
        Node* x = y->left;
        y->left = x->right, x->right = y;
        updateHeight(y), updateHeight(x);
        return x;
    }

    Node* insert(Node* node, string k, string m) {
        if (!node) return new Node(k, m);
        if (k < node->keyword) node->left = insert(node->left, k, m);
        else if (k > node->keyword) node->right = insert(node->right, k, m);
        else node->meaning = m;
        updateHeight(node);

        int balance = balanceFactor(node);
        if (balance > 1 && k < node->left->keyword) return rightRotate(node);
        if (balance < -1 && k > node->right->keyword) return leftRotate(node);
        if (balance > 1 && k > node->left->keyword) return rightRotate(node->left), rightRotate(node);
        if (balance < -1 && k < node->right->keyword) return leftRotate(node->right), leftRotate(node);

        return node;
    }

    Node* minValueNode(Node* node) {
        while (node->left) node = node->left;
        return node;
    }

    Node* deleteNode(Node* node, string k) {
        if (!node) return NULL;
        if (k < node->keyword) node->left = deleteNode(node->left, k);
        else if (k > node->keyword) node->right = deleteNode(node->right, k);
        else {
            if (!node->left || !node->right) {
                Node* temp = node->left ? node->left : node->right;
                delete node;
                return temp;
            }
            Node* temp = minValueNode(node->right);
            node->keyword = temp->keyword, node->meaning = temp->meaning;
            node->right = deleteNode(node->right, temp->keyword);
        }
        updateHeight(node);

        int balance = balanceFactor(node);
        if (balance > 1 && balanceFactor(node->left) >= 0) return rightRotate(node);
        if (balance < -1 && balanceFactor(node->right) <= 0) return leftRotate(node);
        if (balance > 1 && balanceFactor(node->left) < 0) return leftRotate(node->left), rightRotate(node);
        if (balance < -1 && balanceFactor(node->right) > 0) return rightRotate(node->right), leftRotate(node);

        return node;
    }

    void inorder(Node* node) {
        if (node) inorder(node->left), cout << node->keyword << " : " << node->meaning << endl, inorder(node->right);
    }

    void reverseInorder(Node* node) {
        if (node) reverseInorder(node->right), cout << node->keyword << " : " << node->meaning << endl, reverseInorder(node->left);
    }

    int searchComparisons(Node* node, string k) {
        int comparisons = 0;
        while (node) {
            comparisons++;
            if (k == node->keyword) return comparisons;
            node = (k < node->keyword) ? node->left : node->right;
        }
        return comparisons;  // Return n+1 if not found
    }
};

int main() {
    AVLDictionary dict;
    int choice;
    string keyword, meaning;

    do {
        cout << "\n1. Add keyword\n2. Delete keyword\n3. Update keyword\n4. Display (Ascending)\n5. Display (Descending)\n6. Search keyword comparisons\n7. Exit\nEnter choice: ";
        cin >> choice;
        switch(choice) {
            case 1:
                cout << "Enter keyword: "; cin >> keyword;
                cout << "Enter meaning: "; cin.ignore(); getline(cin, meaning);
                dict.root = dict.insert(dict.root, keyword, meaning);
                break;
            case 2:
                cout << "Enter keyword to delete: "; cin >> keyword;
                dict.root = dict.deleteNode(dict.root, keyword);
                break;
            case 3:
                cout << "Enter keyword to update: "; cin >> keyword;
                cout << "Enter new meaning: "; cin.ignore(); getline(cin, meaning);
                dict.root = dict.insert(dict.root, keyword, meaning);
                break;
            case 4:
                dict.inorder(dict.root);
                break;
            case 5:
                dict.reverseInorder(dict.root);
                break;
            case 6:
                cout << "Enter keyword to search: "; cin >> keyword;
                cout << "Comparisons required to search: " << dict.searchComparisons(dict.root, keyword) << endl;
                break;
            case 7:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while(choice != 7);

    return 0;
}