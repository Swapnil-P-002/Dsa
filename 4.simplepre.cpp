#include <iostream>
#include <stack>
using namespace std;

struct Node {
    char d; Node *l, *r;
    Node(char x) : d(x), l(NULL), r(NULL) {}
};

Node* build(string pre) {
    stack<Node*> s;
    for (int i = pre.size() - 1; i >= 0; i--) {
        if (isalpha(pre[i])) s.push(new Node(pre[i]));
        else {
            Node* n = new Node(pre[i]);
            n->l = s.top(); s.pop();
            n->r = s.top(); s.pop();
            s.push(n);
        }
    }
    return s.top();
}

void post(Node* r) {
    stack<Node*> s1, s2;
    s1.push(r);
    while (!s1.empty()) {
        Node* n = s1.top(); s1.pop();
        s2.push(n);
        if (n->l) s1.push(n->l);
        if (n->r) s1.push(n->r);
    }
    while (!s2.empty()) {
        cout << s2.top()->d << " ";
        s2.pop();
    }
}

void bye(Node* r) {
    stack<Node*> s;
    s.push(r);
    while (!s.empty()) {
        Node* n = s.top(); s.pop();
        if (n->l) s.push(n->l);
        if (n->r) s.push(n->r);
        delete n;
    }
}

int main() {
    string pre = "+-a*bc/def";
    cout << "Prefix: " << pre << "\n";
    Node* root = build(pre);
    cout << "Postfix: "; post(root); cout << "\n";
    bye(root);
    cout << "Tree vanished! (Deleted successfully)\n";
    return 0;
}