#include "treap.h"

static void destroy(TreapNode* node) {
    if (node == nullptr) return;
    destroy(node->left);
    destroy(node->right);
    delete node;
}

static TreapNode* merge(TreapNode* a, TreapNode* b) {
    if (a == nullptr) return b;
    if (b == nullptr) return a;

    if (a->priority > b->priority) {
        a->right = merge(a->right, b);
        return a;
    } else {
        b->left = merge(a, b->left);
        return b;
    }
}

Treap::Treap() : root(nullptr) {}

Treap::~Treap() {
    destroy(root);
}