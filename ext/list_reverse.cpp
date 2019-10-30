#include <iostream>
using namespace std;

const int g_max_len = 10; // 1024000;

typedef struct Node_t {
    int value;
    struct Node_t* next;
} Node;

Node* reverse1(Node* root) {

    Node* q = root;
    Node* p = q->next;
    q->next = nullptr;

    while (p != nullptr) {
        Node* r = p->next;
        p->next = q;
        q = p;
        p = r;
    }
    root = q;
    return root;
}

Node* reverse2(Node* root) {
    Node* p = root->next;
    Node* l = p;
    if (p == nullptr) {
        return root;
    }

    while (p != nullptr) {
        Node* q = p->next;
        p->next = root->next;
        root->next = p;
        cout << p->value << endl;
        p = q;
    }

    Node* n = root->next;;
    l->next = root;
    root->next = nullptr;
    root = n;

    return root;
}

int main() {

    Node* root = nullptr;
    Node* p = nullptr;
    for (int i = 0; i < g_max_len; ++i) {
        Node* node = new Node();
        node->value = i;
        if (root == nullptr) {
            root = node;
        } else {
            p->next = node;
        }
        p = node;
    }
    p->next = nullptr;

    p = root;
    while (p != nullptr) {
        cout << p->value << ",";
        p = p->next;
    }
    cout << endl;

    // root = reverse1(root);
    root = reverse2(root);

    p = root;
    while (p != nullptr) {
        cout << p->value << ",";
        p = p->next;
    }
    cout << endl;



}
