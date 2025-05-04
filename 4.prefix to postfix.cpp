#include <iostream>
#include <stack>  //Here we are inserting stack library 
using namespace std;

struct Node { // 1st we are creating node struction by using struct keyword
    char data;
    Node *left, *right;
    Node(char val) : data(val), left(nullptr), right(nullptr) {} //Constructor
};

// Construct expression tree from prefix expression
Node* constructTree(const string &prefix) {

    stack<Node*> st;
    for (int i = prefix.length() - 1; i >= 0; i--) {
        Node* node = new Node(prefix[i]);
        if (isalpha(prefix[i])) st.push(node);
        else {
            node->left = st.top(); st.pop();
            node->right = st.top(); st.pop();
            st.push(node);

        }
    }

    return st.top();
}

// Non-recursive post-order traversal
void postOrderTraversal(Node* root) {
    if (!root) {
        cout << "None";
        return;
    }
    stack<Node*> s1, s2;
    s1.push(root);
    while (!s1.empty()) {
        Node* node = s1.top(); s1.pop();
        s2.push(node);
        if (node->left) s1.push(node->left);
        if (node->right) s1.push(node->right);
    }
    while (!s2.empty()) {
        cout << s2.top()->data << " ";
        s2.pop();
    }
}

// Delete the tree with step-wise output
void deleteTree(Node* &root) {
    if (!root) return;
    stack<Node*> s;
    s.push(root);
    while (!s.empty()) {
        Node* node = s.top(); s.pop();
        cout << "Deleting node " << node->data << endl;
        if (node->right) s.push(node->right);
        if (node->left) s.push(node->left);
        delete node;
        cout << "Remaining: ";
        postOrderTraversal(s.empty() ? nullptr : s.top());
        cout << endl;
    }
    root = nullptr;
}

int main() {
    string prefix = "+--a*bc/def"; // this in given expression
    Node* root = constructTree(prefix);
    cout << "\nGiven prefix: " << prefix << endl << endl;
    cout << "Resulting Post-order Traversal: ";
    postOrderTraversal(root);
    cout << endl << endl;
    deleteTree(root);
    return 0;
}